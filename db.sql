---
--- Contact
---
CREATE TABLE IF NOT EXISTS contact (
    id VARCHAR(50) PRIMARY KEY,
    name VARCHAR(100),
    notify VARCHAR(100)
);

---
--- Message
---
CREATE TABLE IF NOT EXISTS message (
    id INTEGER PRIMARY KEY,
    whatsapp_id TEXT,
    body TEXT,
    ack BOOLEAN NOT NULL,
    direction VARCHAR(3) NOT NULL,
    timestamp INTEGER NOT NULL,
    contact_id VARCHAR(50) NOT NULL,
    media_path TEXT,
    FOREIGN KEY(contact_id) REFERENCES contact(id)
);


