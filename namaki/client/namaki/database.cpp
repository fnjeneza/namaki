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
    std::vector<std::vector<std::string>> rows{};
};

namespace Namaki{
Database::Database(){
    connect();
}

Database::~Database(){
    sqlite3_close(m_db);
}
void Database::connect(const std::string &db_name){
    auto status = sqlite3_open(db_name.c_str(), &m_db);

    if(status != SQLITE_OK){
        std::string error("Sqlite3 error: "+std::to_string(status));
        throw std::runtime_error(error);
    }
    // enable foreign key support
    execute("PRAGMA foreign_keys = ON;");
}

bool Database::add_contact(const Contact &contact) const{
    std::string sql = fmt::format("INSERT INTO contact VALUES('{}', '{}');",
            contact.id,
            contact.name);
    return execute(sql);
}

bool Database::remove_contact(const std::string &id) const {
    std::string sql = fmt::format("DELETE FROM contact WHERE id = '{}'", id);
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
                       WHERE contact.id='{}'",
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
    auto ack = (message.ack == false ? SQLITE_FALSE : SQLITE_TRUE);
    auto direction (message.direction == Direction::IN ? "IN": "OUT");
    std::string sql = fmt::format("INSERT INTO message(body, direction, ack, \
                      timestamp, contact_id ) \
            VALUES('{}', '{}', {}, {}, '{}');",
            message.body,
            direction,
            ack,
            message.timestamp,
            message.contact_id);
    return execute(sql);
}


std::vector<Message> Database::messages(const std::string &contact_id) const {
    std::string sql = fmt::format("SELECT message.body, \
            timestamp, direction FROM message\
            WHERE message.contact_id = '{}'",
            contact_id);
    auto results = query(sql);

    std::vector<Message> message_list;

    if(results.size() == 0){
        return message_list;
    }

    for(auto result : results){
        Message message;
        message.body = result[0];
        message.timestamp = stoul(result[1]);
        message.direction = (result[2] == "IN") ? Direction::IN : Direction::OUT;
        message_list.push_back(std::move(message));
    }

    return message_list;
}

size_t Database::unread(const std::string &id) const{
    std::string sql = fmt::format("SELECT count(id) \
            FROM message \
            WHERE message.ack={} AND message.contact_id='{}'",
            SQLITE_FALSE, id);
    auto result = query(sql);
    return std::stoul(result[0][0]);
}

std::string Database::last_message(const std::string &id) const{
    std::string sql = fmt::format("SELECT message.body, message.timestamp\
            FROM message\
            WHERE message.contact_id='{}'\
            ORDER BY message.timestamp DESC\
            LIMIT 1",
            id);
    auto result = query(sql);

    if (result.empty()){
        return std::string();
    }

    return result[0][0];
}

bool Database::ack(const std::string &id) const{
    std::string sql = fmt::format("UPDATE message\
                        SET ack={}\
                       WHERE message.contact_id='{}'",
                    SQLITE_TRUE,
                    id);
    return execute(sql);
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
      throw std::runtime_error(sql + std::string(err));
    }

    return std::move (data.rows);

}

bool Database::execute(const std::string &sql) const{
    char *err = nullptr;
    sqlite3_exec(m_db,
            sql.c_str(),
            nullptr,
            nullptr,
            &err);

    if(err != nullptr){
      //  logger.debug(std::to_string(err));
      throw std::runtime_error(sql + std::string(err));
      return false;
    }

    return true;
}
} //namespace
