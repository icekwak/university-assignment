USE dbsystem;

CREATE TABLE takes (
	s_id		VARCHAR(5),
    c_id		VARCHAR(7),
    sec_id		VARCHAR(1),
    semester	VARCHAR(10),
    year		VARCHAR(4),
    grade		VARCHAR(2)
);

INSERT INTO takes
VALUES ('00128', 'CS-101', '1', 'Fall', '2009', 'A');

INSERT INTO takes
VALUES ('00128', 'CS-347', '1', 'Fall', '2009', 'A-');

INSERT INTO takes
VALUES ('12345', 'CS-101', '1', 'Fall', '2009', 'C');

INSERT INTO takes
VALUES ('12345', 'CS-190', '2', 'Spring', '2009', 'A');

INSERT INTO takes
VALUES ('12345', 'CS-315', '1', 'Spring', '2010', 'A');

INSERT INTO takes
VALUES ('12345', 'CS-347', '1', 'Fall', '2009', 'A');

INSERT INTO takes
VALUES ('19991', 'HIS-351', '1', 'Spring', '2010', 'B');

INSERT INTO takes
VALUES ('23121', 'FIN-201', '1', 'Spring', '2010', 'C+');

INSERT INTO takes
VALUES ('44553', 'PHY-101', '1', 'Fall', '2009', 'B-');

INSERT INTO takes
VALUES ('45678', 'CS-101', '1', 'Fall', '2009', 'F');

INSERT INTO takes
VALUES ('45678', 'CS-101', '1', 'Spring', '2010', 'B+');

INSERT INTO takes
VALUES ('45678', 'CS-319', '1', 'Spring', '2010', 'B');

INSERT INTO takes
VALUES ('54321', 'CS-101', '1', 'Fall', '2009', 'A-');

INSERT INTO takes
VALUES ('54321', 'CS-190', '2', 'Spring', '2009', 'B+');