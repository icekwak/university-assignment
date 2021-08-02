USE dbsystem;

CREATE TABLE section (
	sec_id	VARCHAR(1),
    c_id	VARCHAR(7),
    semester	VARCHAR(10),
    years	VARCHAR(4),
    building	VARCHAR(15),
    room_num	VARCHAR(5),
    time_slot_id	VARCHAR(1)
);

INSERT INTO section
VALUES ('1', 'BIO-101', 'Summer', '2009', 'Painter', '514', 'B');

INSERT INTO section
VALUES ('1', 'BIO-301', 'Summer', '2010', 'Painter', '514', 'A');

INSERT INTO section
VALUES ('1', 'CS-101', 'Fall', '2009', 'Packard', '101', 'H');

INSERT INTO section
VALUES ('1', 'CS-101', 'Spring', '2010', 'Packard', '101', 'F');

INSERT INTO section
VALUES ('1', 'CS-190', 'Spring', '2009', 'Toylor', '3128', 'E');

INSERT INTO section
VALUES ('2', 'CS-190', 'Spring', '2009', 'Toylor', '3128', 'A');

INSERT INTO section
VALUES ('1', 'CS-315', 'Spring', '2010', 'Watson', '120', 'D');

INSERT INTO section
VALUES ('1', 'CS-319', 'Spring', '2010', 'Watson', '100', 'B');

INSERT INTO section
VALUES ('2', 'CS-319', 'Spring', '2010', 'Toylor', '3128', 'C');

INSERT INTO section
VALUES ('1', 'CS-347', 'Fall', '2009', 'Toylor', '3128', 'A');

INSERT INTO section
VALUES ('1', 'EE-181', 'Spring', '2009', 'Toylor', '3128', 'C');

INSERT INTO section
VALUES ('1', 'FIN-201', 'Spring', '2010', 'Packard', '101', 'B');

INSERT INTO section
VALUES ('1', 'HIS-351', 'Spring', '2010', 'Painter', '514', 'C');

INSERT INTO section
VALUES ('1', 'MU-199', 'Spring', '2010', 'Packard', '101', 'D');

INSERT INTO section
VALUES ('1', 'PHY-101', 'Fall', '2009', 'Watson', '100', 'A');