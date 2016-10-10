import zmq
from threading import Thread

class Broker:
    def __init__(self, bind_address="*", port="5557"):
        print("Broker initialisation...")
        self.context = zmq.Context()
        Thread(target=self._setup_receiver, args=(bind_address, port,)).start()
        self.sender = self._setup_sender("localhost", "5558")


    def _setup_receiver(self, address, port):
        receiver_socket = self.context.socket(zmq.REP)
        receiver_socket.bind("tcp://" + address + ":" + port)
        while True:
            msg = receiver_socket.recv()
            print(msg)
            receiver_socket.send_string("")

    def _setup_sender(self, address, port):
        sender_socket = self.context.socket(zmq.REQ)
        sender_socket.connect("tcp://" + address + ":" + port)
        return sender_socket

    def send(self, message):
        self.sender.send_string(message)
        reply = self.sender.recv()
        return reply


    def handle_message(self):
        print("handling message")
        while True:
            msg = self.receiver_socket.recv()
            print(msg)

            self.receiver_socket.send_string("")


if __name__ == "__main__":
    br = Broker()
    br.send("server")
