from yowsup.layers.interface import YowInterfaceLayer, ProtocolEntityCallback
from yowsup.layers.protocol_receipts.protocolentities import OutgoingReceiptProtocolEntity
from yowsup.layers.protocol_messages.protocolentities import TextMessageProtocolEntity


suffix = "@s.whatsapp.net"

class NamakiLayer(YowInterfaceLayer):
    def __init(self):
        self.connected = False
        self.suffix = "@s.whatsapp.net"


    def phone_to_jid(self, phone):
        return phone + self.suffix


    def has_jid(self, phone):
        return phone.find(suffix) >= 0

    @ProtocolEntityCallback("success")
    def onSuccess(self, entity):
        self.connected = True
        print("ouha i'm connected")

    @ProtocolEntityCallback("message")
    def onMessage(self, messageProtocolEntity):
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
