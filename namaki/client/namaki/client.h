#include <zmq.hpp>
#include <memory>
#include <string>
#include <utility>

namespace Namaki
{
class Client
{
public:
    Client(const std::string &listen_address, const int &listen_port);
    ~Client();

private:
    void setup_receiver(const std::string &address, const int &port);
    void setup_sender(const std::string &address, const int &port);
    void handle_incoming(zmq::message_t &message);

private:
    std::unique_ptr<zmq::context_t> context;
    std::unique_ptr<zmq::socket_t> sender;
    std::unique_ptr<zmq::socket_t> receiver;

    std::pair<std::string, int> m_listen_addr; //addr to listen too

};

}
