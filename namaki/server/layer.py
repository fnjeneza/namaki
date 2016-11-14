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

        timestamp = messageProtocolEntity.getTimestamp()
        participant = messageProtocolEntity.getParticipant()

        message = Message()
        message.id = messageProtocolEntity.getId()
        message.src = messageProtocolEntity.getFrom()
        message.timestamp = timestamp
        message.author = messageProtocolEntity.getAuthor()
        message.notify = messageProtocolEntity.getNotify()

        if participant:
            message.participant = participant

        if messageProtocolEntity.getType() == "text":
            message.text.body = messageProtocolEntity.getBody()

        elif messageProtocolEntity.getType() == "media":
            #media_type = messageProtocolEntity.getMediaType();
            mime_type = messageProtocolEntity.getMimeType();
            message.media.data = messageProtocolEntity.getMediaContent()

            ext = mime_type.split('/')[-1]
            message.media.extension = ext;
            message.text.body = messageProtocolEntity.getCaption()

        # push to the broker
        self.push(message.SerializeToString())
        #send ack
        self.toLower(receipt)


    @ProtocolEntityCallback("ack")
    def _onAck(self, entity):
        """
        called when ack is sent by a friend
        """
        print("ack message sent")


    @ProtocolEntityCallback("failure")
    def _onFailure(self, entity):
        """
        when authentication failed
        """
        print("Login failed, reason %s" % entity.getReason())


    def send_message(self, message):
        """
        outgoing message
        param:
            message
        """
        msg = Message()
        msg.ParseFromString(message)
        phone = msg.dest
        body = msg.text.body

        print("message to be sent %s to whatsapp number %s" % (message,phone))

        out = TextMessageProtocolEntity(body.encode(),
                to = phone)
        self.toLower(out)

    def push(self, message):
        """
        push message to the broker
        """
        print("push message to the broker")
        self._broker.send(message)
