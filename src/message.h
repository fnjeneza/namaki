#ifndef NAMAKI_MESSAGE_H
#define NAMAKI_MESSAGE_H

#include <string>
#include <utility>
#include <ctime>

namespace Namaki{
enum struct Direction{
    IN,
    OUT
};

struct Message{

    std::string whatsapp_id{};
    std::string body{};
    std::string contact_id{};
    size_t timestamp{static_cast<size_t>(std::time(nullptr))};
    bool ack{}; //true if message has been opened
    Direction direction{};
    std::string media_path{};
    std::string notify{};
    std::string author{};

    std::pair<std::string, std::string>
    datetime() const noexcept;
};
}// namespace

#endif /* NAMAKI_MESSAGE_H */
