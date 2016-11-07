#include "database.h"

#include <array>
#include <string>

#include <sqlite3.h>
#include <fmt/format.h>

#include "contact.h"
#include "message.h"

using Namaki::Contact;
using sqlite3 = struct sqlite3;

struct Data{
    std::vector<std::vector<std::string>> rows;
};

namespace Namaki{
Database::Database(){
    auto status = sqlite3_open(m_db_name, &m_db);

    if(status != SQLITE_OK){
        std::string error("Sqlite3 error: "+std::to_string(status));
        throw std::runtime_error(error);
    }
}

Database::~Database(){
    sqlite3_close(m_db);
}

bool Database::add_contact(const Contact &contact) const{
    std::string sql = fmt::format("INSERT INTO contact VALUES({}, '{}');",
            contact.id,
            contact.name);
    return execute(sql);
}

bool Database::remove_contact(const std::string &id) const {
    std::string sql = fmt::format("DELETE FROM contact WHERE id = {}", id);
    return execute(sql);
}

std::vector<Contact> Database::contacts() const {
    std::string sql("SELECT contact.id, contact.name FROM contact");
    auto results = query(sql);

    std::vector<Contact> contact_list;

    if(results.size() == 0){
        return contact_list;
    }

    for(auto result : results){
        Contact contact;
        contact.id = result[0];
        contact.name = result[1];
        contact_list.push_back(std::move(contact));
    }

    return contact_list;
}

Namaki::Contact Database::contact(const std::string &id) const {
    std::string cmd = fmt::format("SELECT contact.id, contact.name \
                       FROM contact \
                       WHERE contact.id={}",
                       id);
    auto result = query(cmd);

    if(result.size() == 0){
        return Contact();
    }

    auto columns = result[0];
    Contact contact;
    contact.id = columns[0];
    contact.name = columns[1];
    return contact;

}

bool Database::add_message(const Message &message) const{
    auto out = message.out == true ? SQLITE_TRUE : SQLITE_FALSE;
    auto read = message.read == true ? SQLITE_TRUE : SQLITE_FALSE;
    std::string sql = fmt::format("INSERT INTO message \
            VALUES({},'{}', {}, {}, {}, {});",
            message.id,
            message.body,
            out,
            read,
            message.timestamp,
            message.contact_id);
    return execute(sql);
}


std::vector<Message> Database::messages(const std::string &contact_id) const {
    std::string sql = fmt::format("SELECT message.id, message.body, \
            message.timestamp, message.out, message.read FROM message\
            WHERE message.contact_id = {}",
            contact_id);
    auto results = query(sql);

    std::vector<Message> message_list;

    if(results.size() == 0){
        return message_list;
    }

    for(auto result : results){
        Message message;
        message.id = result[0];
        message.body = result[1];
        message.timestamp = result[2];
        message.out = (result[3]==std::to_string(SQLITE_TRUE) ? true : false);
        message.read = (result[4]==std::to_string(SQLITE_TRUE) ? true : false);
        message_list.push_back(std::move(message));
    }

    return message_list;
}
std::vector<std::vector<std::string>>
Database::query(const std::string &sql) const{
    char* err = nullptr;
    Data data;

    sqlite3_exec(m_db,
            sql.c_str(),
            [](void* data_, int argc, char** values, char**)->int{
                std::vector<std::string> row;
                auto capture = static_cast<Data*>(data_);
                for(int i = 0; i < argc; ++i){
                    row.push_back(std::string(values[i]));
                }
                capture->rows.push_back(std::move(row));
                return 0;
            },
            static_cast<void*>(&data),
            &err);

    if(err != nullptr){
    //    logger.debug(std::to_string(err));
    //  throw std::runtime_error(std::string(err));
    }

    return std::move (data.rows);

}

bool Database::execute(const std::string &sql) const{
    char *err = nullptr;
    sqlite3_exec(m_db,
            sql.c_str(),
            [](void* , int , char** , char**)->int{
                return 0;
            },
            nullptr,
            &err);

    if(err != nullptr){
      //  logger.debug(std::to_string(err));
      //throw std::runtime_error(std::string(err));
      return false;
    }

    return true;
}
} //namespace
