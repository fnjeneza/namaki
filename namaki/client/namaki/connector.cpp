#include "connector.h"
#include <string>
#include <zmq.hpp>
#include <iostream>
#include "messages.h"

using messages::Message;
namespace Namaki{

class Connector::Impl{
public:
    Impl();
    ~Impl();

    void outgoing(const Message &message) const;
    Message incoming() const;

private:
    std::unique_ptr<zmq::context_t> m_context;
    std::unique_ptr<zmq::socket_t> m_sender;
    std::unique_ptr<zmq::socket_t> m_receiver;
    std::pair<std::string, int> m_listen_addr; //addr to listen too
    std::pair<std::string, int> m_remote_addr; //addr to connect too
};

Connector::Connector():pimpl{std::make_unique<Impl>()}{
    std::cout << "connector ctor" << '\n';
}
Connector::~Connector() = default;

Message Connector::receive() const{
    return pimpl->incoming();
}

void Connector::send(const Message &message) const{
    pimpl->outgoing(message);
}

Connector::Impl::Impl():
    m_context{std::make_unique<zmq::context_t>(1)},
    m_sender { std::make_unique<zmq::socket_t>(*m_context, ZMQ_PUSH)},
    m_receiver{std::make_unique<zmq::socket_t>(*m_context,ZMQ_PULL)},
    m_listen_addr{"*", 5558},
    m_remote_addr {"localhost", 5557}
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    auto address = std::get<0>(m_listen_addr);
    auto port = std::to_string(std::get<1>(m_listen_addr));
    auto remote_address = std::get<0>(m_remote_addr);
    auto remote_port = std::to_string(std::get<1>(m_remote_addr));

    m_receiver->bind("tcp://"+address+":"+port);
    m_sender->connect("tcp://"+remote_address+":"+remote_port);
}

Connector::Impl::~Impl(){
    ::google::protobuf::ShutdownProtobufLibrary();
}
Message Connector::Impl::incoming() const{
    std::cout << "wait for a message" << '\n';
    zmq::message_t msg;
    m_receiver->recv(&msg);

    std::string s_message(static_cast<char*>(msg.data()), msg.size());
    Message message;
    message.ParseFromString(s_message);
    return message;
}

void Connector::Impl::outgoing(const Message &message) const{
    auto out = message.SerializeAsString();
    auto size = out.size();
    zmq::message_t msg(size);
    memcpy(msg.data(), out.c_str(), size);
    m_sender->send(msg);
}
} //namespace