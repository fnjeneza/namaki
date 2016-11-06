#ifndef CONTACT_H
#define CONTACT_H


#include <string>

namespace Namaki{
class Contact{
public:
    Contact() = default;
    Contact(const std::string &id,
            const std::string &name,
            const std::string &last_message);

    ~Contact() = default;

    std::string name() const noexcept;
    std::string id() const noexcept;
    std::string last_message() const noexcept;

private:
    std::string m_id;
    std::string m_name;
    std::string m_last_message;
};
} //namespace
#endif /* CONTACT_H */
