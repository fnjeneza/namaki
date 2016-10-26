#include "client.h"

#include <memory>
#include <zmq.hpp>
#include <iostream>
#include "messages.h"

using messages::Message;


namespace Namaki {

class Client::Impl {
public:
    Impl(const std::string &listen_address, const int &listen_port);
    ~Impl();

private:
    void setup_receiver(const std::string &address, const int &port);
    void setup_sender(const std::string &address, const int &port);
    void handle_incoming(zmq::message_t &message);

    std::unique_ptr<zmq::context_t> context;
    std::unique_ptr<zmq::socket_t> sender;
    std::unique_ptr<zmq::socket_t> receiver;
    std::pair<std::string, int> m_listen_addr; //addr to listen too
};

Client::Client(const std::string &listen_address, const int &listen_port):
    pimpl{std::make_unique<Impl>(listen_address, listen_port)}
{}

Client::~Client() = default;

Client::Impl::Impl(const std::string &listen_address, const int &listen_port):
    m_listen_addr{listen_address, listen_port}
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    std::cout << "Client init..." << std::endl;
    context = std::make_unique<zmq::context_t>(1);
    setup_receiver(std::get<0>(m_listen_addr), std::get<1>(m_listen_addr));
    //setup_sender("*", 5557);
}

Client::Impl::~Impl()
{
    ::google::protobuf::ShutdownProtobufLibrary();
}

void Client::Impl::setup_receiver(const std::string &address, const int &port)
{
    receiver = std::make_unique<zmq::socket_t>(*context, ZMQ_PULL);
    auto s_port = std::to_string(port);
    receiver->bind("tcp://"+address+":"+s_port);

    while(true)
    {
        zmq::message_t message;
        receiver->recv(&message);
        handle_incoming(message);
    }
}

void Client::Impl::setup_sender(const std::string &address, const int &port)
{
    sender = std::make_unique<zmq::socket_t>(*context, ZMQ_PUSH);
    auto s_port = std::to_string(port);
    sender->connect("tcp://"+address+":"+s_port);
}

void Client::Impl::handle_incoming(zmq::message_t &message)
{
    std::string s_message(static_cast<char*>(message.data()), message.size());

    Message msg;
    msg.ParseFromString(s_message);
    auto id = msg.id();
    auto src = msg.src();
    auto dest = msg.dest();
    auto timestamp = msg.timestamp();
    auto body = msg.text().body();

    std::cout <<"id: " << id << std::endl;
    if(!src.empty())
    {
        std::cout << "src: " << src << std::endl;
    }
    else
    {
        std::cout << "dest: " << dest << std::endl;
    }
    std::cout << "timestamp: " << timestamp << std::endl;
    std::cout << "body: " << body << std::endl;
}
}
