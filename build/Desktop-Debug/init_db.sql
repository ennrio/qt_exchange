INSERT INTO currencies (code, name, rate) VALUES
('USD', 'US Dollar', 1.0),
('EUR', 'Euro', 0.93),
('GBP', 'British Pound', 0.79),
('JPY', 'Japanese Yen', 151.86),
('CAD', 'Canadian Dollar', 1.36);

INSERT INTO users (username, password_hash, full_name, role) VALUES
('admin', '5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8', 'Administrator', 'admin'),
('user1', '5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8', 'John Doe', 'user');
