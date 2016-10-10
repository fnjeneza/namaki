import zmq

class Client:
    def __init__(self, hostname="localhost", port="5557"):
        print("Init client ...")
        context = zmq.Context()
        self.receiver = context.socket(zmq.PULL)
        self.receiver.connect("tcp://" + hostname + ":" + port)
        self.handle_incoming()

    def handle_incoming(self):
        """
        handle incoming messages
        """
        while True:
            message = self.receiver.recv()
            print(message)

if __name__ == "__main__":
    c = Client()

