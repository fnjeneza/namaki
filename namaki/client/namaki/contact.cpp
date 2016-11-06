#include "contact.h"

namespace Namaki{
Contact::Contact(const std::string &id,
        const std::string &name,
        const std::string &last_message):
    m_id {id},
    m_name {name},
    m_last_message{last_message}
{}

std::string Contact::name() const noexcept{
    return m_name;
}

std::string Contact::id() const noexcept{
    return m_id;
}

std::string Contact::last_message() const noexcept{
    return m_last_message;
}

} //namespace
