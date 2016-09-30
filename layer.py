from yowsup.layers import YowLayer

class NamakiLayer(YowLayer):
    def receive(self, protocolEntity):
        if protocolEntity.getTag() == "message":
            self.onMessage(protocolEntity)

    def onMessage(self, messageProtocolEntity):
        message = messageProtocolEntity/getBody()
        print(message)
