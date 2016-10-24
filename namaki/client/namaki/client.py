import zmq
from threading import Thread
from messages_pb2 import Message

class NamakiClient:
    def __init__(self, bind_address="*", port="5558"):
        print("Client initialisation...")
        self.context = zmq.Context()
        self.sender = self._setup_sender("localhost", "5557")
        Thread(target=self._setup_receiver,
                args=(bind_address, port,)).start()

    def _setup_receiver(self, address, port):
        receiver_socket = self.context.socket(zmq.PULL)
        receiver_socket.bind("tcp://" + address + ":" + port)
        while True:
            msg = receiver_socket.recv()
            self.handle_incoming(msg)

    def _setup_sender(self, address, port):
        sender_socket = self.context.socket(zmq.PUSH)
        sender_socket.connect("tcp://" + address + ":" + port)
        return sender_socket

    def send(self, message):
        self.sender.send_string(message)

    def handle_incoming(self, message):
        """
        Handle incoming messages
        message: protobuf serialized data
        """
        msg = Message()
        msg.ParseFromString(message)
        print(msg)

# just for test
if __name__ == "__main__":
    nc = NamakiClient()
