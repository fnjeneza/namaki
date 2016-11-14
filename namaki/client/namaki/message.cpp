#include "message.h"
#include <ctime>

namespace Namaki{


std::pair<std::string, std::string>
Message::datetime() const noexcept{
    std::time_t t = static_cast<time_t>(timestamp);
    char date_[10];
    char time_[10];
    std::strftime(date_,sizeof(date_), "%D", std::localtime(&t) );
    std::strftime(time_,sizeof(time_), "%R", std::localtime(&t) );
    return std::make_pair<std::string, std::string>(std::string(date_),
            std::string(time_));
}
}
