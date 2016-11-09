#ifndef NAMAKI_CONNECTOR_H
#define NAMAKI_CONNECTOR_H

#include <memory>

namespace Namaki{
class Message;
class Connector{
public:
    Connector();
    ~Connector();

    Namaki::Message receive() const;
    void send(const Namaki::Message &message) const;

private:
    class Impl;
    std::unique_ptr<Impl> pimpl;

};
} // namespace
#endif /* NAMAKI_CONNECTOR_H */
