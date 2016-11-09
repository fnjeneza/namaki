---
--- Contact
---
CREATE TABLE IF NOT EXISTS contact (
    id VARCHAR(50) PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);

---
--- Message
---
CREATE TABLE IF NOT EXISTS message (
    id INTEGER PRIMARY KEY,
    whatsapp_id INTEGER,
    body TEXT,
    ack BOOLEAN,
    direction VARCHAR(3),
    timestamp INTEGER NOT NULL,
    contact_id VARCHAR(50),
    FOREIGN KEY(contact_id) REFERENCES contact(id)
);
