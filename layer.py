from yowsup.layers.interface import YowInterfaceLayer, ProtocolEntityCallback
from yowsup.layers.protocol_receipts.protocolentities import OutgoingReceiptProtocolEntity

class NamakiLayer(YowInterfaceLayer):

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
