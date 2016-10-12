from yowsup.layers.interface import YowInterfaceLayer, ProtocolEntityCallback
from yowsup.layers.protocol_receipts.protocolentities import OutgoingReceiptProtocolEntity
from yowsup.layers.protocol_messages.protocolentities import TextMessageProtocolEntity
from broker import Broker
from messages_pb2 import Message

class NamakiLayer(YowInterfaceLayer):
    def __init__(self):
        print("init layer")
        YowInterfaceLayer.__init__(self)
        self._connected = False
        self._suffix = "@s.whatsapp.net"
        self._broker = Broker()
        self._broker.set_message_handler(self.send_message)
        assert self._broker.started(), "broker not running"


    def phone_to_jid(self, phone):
        return phone + self._suffix


    def has_jid(self, phone):
        return phone.find(self._suffix) >= 0


    @ProtocolEntityCallback("success")
    def _onSuccess(self, entity):
        """
        called when a connection succeed
        """
        self._connected = True
        print("ouha!! connected")


    def is_connected(self):
        """
        check if connection is established
        """
        return self._connected


    @ProtocolEntityCallback("message")
    def onMessage(self, messageProtocolEntity):
        """
        called when on incoming text message
        """
        receipt = OutgoingReceiptProtocolEntity(messageProtocolEntity.getId(),
                messageProtocolEntity.getFrom(),
                "read",
                messageProtocolEntity.getParticipant())

        if messageProtocolEntity.getType() == "text":
            print(messageProtocolEntity)

            message = Message()
            message.id = messageProtocolEntity.getId()
            message.src = messageProtocolEntity.getFrom()
            message.text.body = messageProtocolEntity.getBody()
            message.timestamp = messageProtocolEntity.getTimestamp()
            self.push(message.SerializeToString())

        #send ack
        self.toLower(receipt)


    @ProtocolEntityCallback("ack")
    def _onAck(self, entity):
        """
        called when ack is sent by a friend
        """
        print("message sent")


    @ProtocolEntityCallback("failure")
    def _onFailure(self, entity):
        """
        when authentication failed
        """
        print("Login failed, reason %s" % entity.getReason())


    def send_message(self, phone, message):
        """
        outgoing message
        param:
            phone
            message
        """
        if not self.has_jid(phone):
            phone = self.phone_to_jid(phone)

        out = TextMessageProtocolEntity(message.encode(),
                to = phone)
        self.toLower(out)

    def push(self, message):
        """
        push message to the broker
        """
        print("push message to the broker")
        self._broker.send(message)
