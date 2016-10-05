from yowsup.layers.interface import YowInterfaceLayer, ProtocolEntityCallback
from yowsup.layers.protocol_receipts.protocolentities import OutgoingReceiptProtocolEntity
from yowsup.layers.protocol_messages.protocolentities import TextMessageProtocolEntity


class NamakiLayer(YowInterfaceLayer):
    def __init__(self):
        YowInterfaceLayer.__init__(self)
        self._connected = False
        self._suffix = "@s.whatsapp.net"


    def phone_to_jid(self, phone):
        return phone + self._suffix


    def has_jid(self, phone):
        return phone.find(self._suffix) >= 0


    @ProtocolEntityCallback("success")
    def onSuccess(self, entity):
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

        message = messageProtocolEntity.getBody()
        # TODO
        # do some action here
        print("... %s" % message)

        #send ack
        self.toLower(receipt)


    @ProtocolEntityCallback("ack")
    def onAck(self, entity):
        """
        called when ack is sent by a friend
        """
        print("message sent")


    @ProtocolEntityCallback("failure")
    def onFailure(self, entity):
        """
        when authentication failed
        """
        print("Login failed, reason %s" % entity.getReason())


    def send_message(self, phone, message):
        if not self.has_jid(phone):
            phone = self.phone_to_jid(phone)

        out = TextMessageProtocolEntity(message.encode(),
                to = phone)
        self.toLower(out)
