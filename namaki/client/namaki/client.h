#ifndef NAMAKI_CLIENT_H
#define NAMAKI_CLIENT_H

#include <memory>
#include <string>

namespace Namaki
{
class Client
{
public:
    Client(const std::string &listen_address, const int &listen_port);
    ~Client();

private:
    class Impl;
    std::unique_ptr<Impl> pimpl;

}; // Client

} //namespace

#endif /* NAMAKI_CLIENT_H */
