import zmq
from threading import Thread

class Broker:
    def __init__(self,
            bind_address="*",
            bind_port="5557",
            connect_address="localhost",
            connect_port="5558"):

        print("Broker initialisation...")

        #NamakiLayer method to handler icoming message
        self.message_handler = None

        self.context = zmq.Context()
        Thread(target=self._setup_receiver,
                args=(bind_address, bind_port,)).start()
        self.sender = self._setup_sender(connect_address, connect_port)

        # once at this line => broker well started
        self._started = True


    def started(self):
        return self._started


    def _setup_receiver(self, address, port):
        """
        Init a socket thread through it will receive data from client
        """
        receiver_socket = self.context.socket(zmq.PULL)
        receiver_socket.bind("tcp://" + address + ":" + port)
        while True:
            msg = receiver_socket.recv()
            assert self.message_handler, "message handler not set"
            self.message_handler("33780889335", msg.decode())
            print(msg)


    def _setup_sender(self, address, port):
        """
        Init a (sub)socket through it will send data to client
        """
        sender_socket = self.context.socket(zmq.PUSH)
        sender_socket.connect("tcp://" + address + ":" + port)
        return sender_socket


    def send(self, message):
        """
        send data to client
        """
        self.sender.send_string(message)


    def set_message_handler(self, fn):
        self.message_handler = fn

# just for test
if __name__ == "__main__":
    br = Broker()
    #br.send("server")
