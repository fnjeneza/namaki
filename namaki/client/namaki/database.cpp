#include "database.h"

#include <array>
#include <iostream>
#include <string>

#include <sqlite3.h>

#include "contact.h"

using Namaki::Contact;

struct Data{
    std::vector<std::vector<std::string>> rows;
};

namespace Namaki{
Database::Database(){
    auto status = sqlite3_open(m_db_name, &m_db);

    if(status != SQLITE_OK){
        std::cerr << status;
    }
}

Database::~Database(){
    sqlite3_close(m_db);
}

Namaki::Contact Database::contact(const std::string &id) const {
    std::string cmd = "SELECT message.id, message.contact_id,\
                       contact.name,message.body \
                       FROM message, contact \
                       WHERE message.contact_id='"+id+"'\
                       ORDER BY message.id DESC \
                       LIMIT 1";
    auto result = execute(cmd);

    if(result.size() == 0){
        return Contact();
    }

    auto columns = result[0];
    auto contact_id = columns[1];
    auto contact_name = columns[2];
    auto last_message = columns[3];
    Contact contact(contact_id, contact_name, last_message);
    return contact;

}
std::vector<std::vector<std::string>>
Database::execute(const std::string &sql) const{
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
        throw std::runtime_error(std::string(err));
    }

    return std::move (data.rows);

}
} //namespace
