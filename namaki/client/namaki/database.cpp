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
