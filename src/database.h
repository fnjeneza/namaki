#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

struct sqlite3;

namespace Namaki{
struct Contact;
struct Message;

class Database{
public:
    Database();
    ~Database();
    Database(const Database &) = delete;
    Database & operator=(const Database) = delete;

    void connect(const std::string &db_name="namaki.db");
    bool add_contact(const Contact &contact) const;
    bool remove_contact(const std::string &contact) const;
    Namaki::Contact contact(const std::string &id) const;
    std::vector<Namaki::Contact> contacts() const;
    bool add_message(const Message &message) const;
    bool remove_message(const std::string &id) const;
    std::vector<Message> messages(const std::string &id) const;
    size_t unread(const std::string &id) const;
    std::string last_message(const std::string &id) const;
    bool ack(const std::string &id) const;

private:
    std::vector<std::vector<std::string>>
    query(const std::string &sql) const;
    bool execute(const std::string &sql) const;

private:
    const uint SQLITE_TRUE = 1;
    const uint SQLITE_FALSE = 0;
    sqlite3 *m_db{nullptr};
};
} //namespace
#endif /* DATABASE_H */
