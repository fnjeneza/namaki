#ifndef NAMAKI_CONTACT_H
#define NAMAKI_CONTACT_H


#include <string>

namespace Namaki{
struct Contact{
public:
    std::string id{};
    std::string name{};
    std::string notify{};

};
} //namespace
#endif /* NAMAKI_CONTACT_H */
