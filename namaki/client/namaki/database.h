#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

using sqlite3 = struct sqlite3;

namespace Namaki{
class Contact;
class Message;

class Database{
public:
    Database();
    ~Database();

    std::vector<Namaki::Contact> contacts() const;
    Namaki::Contact contact(const std::string &id) const;
    std::vector<Message> messages(const std::string &id) const;

private:
    std::vector<std::vector<std::string>>
    execute(const std::string &sql) const;

private:
    const char *m_db_name = "namaki.db";
    sqlite3 *m_db;
};
} //namespace
#endif /* DATABASE_H */
