from yowsup.layers.interface import YowInterfaceLayer, ProtocolEntityCallback
from yowsup.layers.protocol_receipts.protocolentities import OutgoingReceiptProtocolEntity
from yowsup.layers.protocol_messages.protocolentities import TextMessageProtocolEntity


suffix = "@s.whatsapp.net"

class NamakiLayer(YowInterfaceLayer):
    def __init(self):
        self._connected = False
        self._suffix = "@s.whatsapp.net"


    def phone_to_jid(self, phone):
        return phone + self._suffix


    def has_jid(self, phone):
        return phone.find(suffix) >= 0


    @ProtocolEntityCallback("success")
    def onSuccess(self, entity):
        """
        called when a connection succeed
        """
        self._connected = True
        print("connected")


    def assert_connected(self):
        """
        check if connection is established
        """
        assert _connected, "Not connected"


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


    def send_message(self, phone, message):
        if not self.has_jid(phone):
            phone = self.phone_to_jid(phone)

        out = TextMessageProtocolEntity(message.encode(),
                to = phone)
        self.toLower(out)
