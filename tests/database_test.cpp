#include <catch.hpp>
#include "database.h"
#include "contact.h"
#include "message.h"

#include <algorithm>
#include <cstdlib>
#include <sqlite3.h>

using Namaki::Direction;

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
        REQUIRE_THROWS(db.add_contact(contact));
    }

    SECTION("removing contact"){
        REQUIRE(db.remove_contact(contact.id));
    }

    SECTION("removing not existing contact"){
        REQUIRE(db.remove_contact(contact.id));
    }

    SECTION("retrieving all contacts in db"){
        Namaki::Contact zach;
        zach.id = "456789@s.whatsapp.net";
        zach.name = "Zacharie Marie";
        REQUIRE(db.add_contact(zach));
        auto result = db.contacts();
        REQUIRE(result.size() > 0);
    }

    SECTION("adding message"){
        Namaki::Message m1;
        m1.body = "hello world";
        m1.direction = Direction::OUT;
        m1.ack = true;
        m1.contact_id = "123456";
        m1.timestamp=4578561;

        Namaki::Message m2;
        m2.body = "bonjour le monde";
        m2.direction = Direction::OUT;
        m2.ack = true;
        m2.contact_id = "123456";
        m2.timestamp=4578561;
        REQUIRE(db.add_message(m1));
        REQUIRE(db.add_message(m2));
    }

    SECTION("adding message with special char"){
        Namaki::Message m1;
        m1.body = "hello' 'w'orld";
        m1.direction = Direction::OUT;
        m1.contact_id = "123456";
        m1.timestamp=4578561;

        REQUIRE(db.add_message(m1));
    }

    SECTION("retrieving all messages"){
        Namaki::Contact c;
        c.id = "123456@s.whatsapp.net";
        c.name = "Jean Delatour";
        REQUIRE(db.add_contact(c));

        Namaki::Message m1;
        m1.body = "hello world";
        m1.direction = Direction::OUT;
        m1.contact_id = c.id;
        m1.timestamp=4578561;

        Namaki::Message m2;
        m2.body = "bonjour le monde";
        m2.direction = Direction::OUT;
        m2.contact_id = c.id;
        m2.timestamp=4578561;
        REQUIRE(db.add_message(m1));
        REQUIRE(db.add_message(m2));
        auto result = db.messages(c.id);
        REQUIRE(result.size() == 2);
    }

    SECTION("retrieving unread message"){

        Namaki::Contact turner;
        turner.id = "147852";
        turner.name = "Paige Turner";
        REQUIRE(db.add_contact(turner));

        Namaki::Message m1;
        m1.body = "hello world";
        m1.direction = Direction::IN;
        m1.ack = false;
        m1.contact_id = turner.id;
        m1.timestamp=123654;
        REQUIRE(db.add_message(m1));
        auto result = db.unread(turner.id);
        REQUIRE(result == 1);
    }

    SECTION("retrieving last message"){

        Namaki::Contact contact_;
        contact_.id = "456987";
        contact_.name = "Barb Ackue";
        REQUIRE(db.add_contact(contact_));

        Namaki::Message m1;
        m1.body = "message1";
        m1.direction = Direction::OUT;
        m1.ack = false;
        m1.contact_id = contact_.id;
        m1.timestamp=123456;
        REQUIRE(db.add_message(m1));
        Namaki::Message m2;
        m2.body = "message2";
        m2.direction = Direction::OUT;
        m2.ack = false;
        m2.contact_id = contact_.id;
        m2.timestamp=123457;
        REQUIRE(db.add_message(m2));
        auto result = db.last_message(contact_.id);
        REQUIRE(result == m2.body);

    }

    SECTION("retrieving empty message as last message when there is not one"){
        Namaki::Contact contact_;
        contact_.id = "987654";
        contact_.name = "Anna Mull";
        REQUIRE(db.add_contact(contact_));
        auto m =db.last_message(contact_.id);
        REQUIRE(m.empty());
    }

    SECTION("ACKing messages"){
        Namaki::Contact contact_;
        contact_.id = "12987654@s.whatsapp.net";
        contact_.name = "Pete Sariya";
        REQUIRE(db.add_contact(contact_));
        Namaki::Message m1;
        m1.body = "message1";
        m1.direction = Direction::IN;
        m1.ack = false;
        m1.contact_id = contact_.id;
        Namaki::Message m2;
        m2.body = "message2";
        m2.direction = Direction::IN;
        m2.ack = false;
        m2.contact_id = contact_.id;

        REQUIRE(db.ack(contact_.id));
        auto messages = db.messages(contact_.id);
        auto it = std::find_if(std::cbegin(messages), std::cend(messages),
                [](auto m){return m.ack; });
        REQUIRE(it == std::cbegin(messages));
    }


}
