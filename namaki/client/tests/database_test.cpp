#include <catch.hpp>
#include "database.h"
#include "contact.h"
#include "message.h"

#include <algorithm>
#include <cstdlib>
#include <sqlite3.h>


TEST_CASE("(fixture) setup database", "[database]"){
    auto out = std::system("bash db-fixture.sh");
    REQUIRE(out == 0);
}

TEST_CASE("database manipulation", "[database]"){
    Namaki::Database db;
    Namaki::Contact contact;
    contact.id = "33677554433";
    contact.name = "Jean Dupont";

    SECTION("retrieving a contact"){
        auto id = "123456";
        auto result = db.contact(id);
        CAPTURE(result.id);
        REQUIRE_FALSE(result.id.empty());
    }

    SECTION("adding contact"){
        REQUIRE(db.add_contact(contact));
    }

    SECTION("adding a contact who already exist"){
        REQUIRE_FALSE(db.add_contact(contact));
    }

    SECTION("removing contact"){
        REQUIRE(db.remove_contact(contact.id));
    }

    SECTION("removing not existing contact"){
        REQUIRE(db.remove_contact(contact.id));
    }

    SECTION("retrieving all contacts in db"){
        Namaki::Contact zach;
        zach.id = "456789";
        zach.name = "Zacharie Marie";
        REQUIRE(db.add_contact(zach));
        auto result = db.contacts();
        REQUIRE(result.size() > 0);
        for(auto &c :  result){
            auto found = ((c.id == "123456") || (c.id == "456789"));
            REQUIRE(found);
        }
    }

    SECTION("adding message"){
        Namaki::Message m1;
        m1.id = "1";
        m1.body = "hello world";
        m1.out = true;
        m1.read = true;
        m1.contact_id = "123456";
        m1.timestamp="4578561";

        Namaki::Message m2;
        m2.id = "2";
        m2.body = "bonjour le monde";
        m2.out = false;
        m2.read = true;
        m2.contact_id = "123456";
        m2.timestamp="4578561";
        REQUIRE(db.add_message(m1));
        REQUIRE(db.add_message(m2));
    }

    SECTION("retrieving all messages"){
        auto result = db.messages("123456");
        REQUIRE(result.size() == 2);
    }


}
