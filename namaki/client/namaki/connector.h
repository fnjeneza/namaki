#ifndef NAMAKI_CONNECTOR_H
#define NAMAKI_CONNECTOR_H

#include <memory>

namespace messages{
class Message;
}
namespace Namaki{
class Connector{
public:
    Connector();
    ~Connector();

    messages::Message receive() const;
    void send(const messages::Message &message) const;

private:
    class Impl;
    std::unique_ptr<Impl> pimpl;

};
} // namespace
#endif /* NAMAKI_CONNECTOR_H */
