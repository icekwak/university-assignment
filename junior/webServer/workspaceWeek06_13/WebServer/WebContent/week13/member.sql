CREATE TABLE member (
    id VARCHAR(20) NOT NULL,
    passwd VARCHAR(20),
    name VARCHAR(30),
    PRIMARY KEY(id)
)DEFAULT CHARSET = utf8;

SELECT * FROM member;