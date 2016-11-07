#!/bin/bash

if [ -f namaki.db ]; then
    rm namaki.db
fi

# init database
cat db-init.sql | sqlite3 namaki.db

#add an entry
sqlite3 namaki.db "INSERT INTO contact VALUES ('123456', 'John Doe');"
