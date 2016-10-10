import zmq

class Broker:
    def __init__(self, bind_address="*", port="5557"):
        print("Broker initialisation...")
        context = zmq.Context()
        self.receiver_socket = context.socket(zmq.REP)
        self.receiver_socket.bind("tcp://" + bind_address + ":" + port)
        self.handle_message()


    def handle_message(self):
        print("handling message")
        while True:
            msg = self.receiver_socket.recv()
            print(msg)

            self.receiver_socket.send_string("")


if __name__ == "__main__":
    br = Broker()
