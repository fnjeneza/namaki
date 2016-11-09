#ifndef NAMAKI_MESSAGE_H
#define NAMAKI_MESSAGE_H

#include <string>
namespace Namaki{
struct Message{
    std::string id;
    std::string timestamp;
    std::string body;
    std::string contact_id;
    bool out; //true for outgoing message
    bool read; //true if message has been opened
};
}// namespace

#endif /* NAMAKI_MESSAGE_H */
