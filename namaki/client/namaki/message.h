#ifndef NAMAKI_MESSAGE_H
#define NAMAKI_MESSAGE_H

#include <string>
namespace Namaki{
enum class Direction{
    IN,
    OUT
};

struct Message{
    std::string id;
    std::string whatsapp_id;
    std::string body;
    std::string contact_id;
    size_t timestamp;
    bool ack; //true if message has been opened
    Direction direction;
};
}// namespace

#endif /* NAMAKI_MESSAGE_H */
