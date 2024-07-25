CREATE DATABASE IF NOT EXISTS crud_cpp;
USE crud_cpp;

-- Contoh tabel dan data, sesuaikan dengan kebutuhan Anda
CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL,
    email VARCHAR(50) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

INSERT INTO users (username, email) VALUES ('admin', 'admin@example.com');
