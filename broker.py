import zmq

class Broker:
    def __init__(self, bind_address="*", port="5557"):
        print("Broker initialisation...")
        context = zmq.Context()
        self.sender = context.socket(zmq.PUSH)
        self.sender.bind("tcp://" + bind_address + ":" + port)

    def send(self, message):
        print("sending message to client")
        self.sender.send_string(message)


if __name__ == "__main__":
    br = Broker()
    br.send("hello world")
