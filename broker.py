import zmq

class Broker:
    def __init__(self):
        print("Broker initialisation...")
        context = zmq.Context()
        self.sender = context.socket(zmq.PUSH)
        self.sender.bind("tcp://*:5557")

    def send(self, message):
        print("sending message to client")
        self.sender.send_string(message)


if __name__ == "__main__":
    br = Broker()
    br.send("hello world")
