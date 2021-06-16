USE dbsystem;

CREATE TABLE course (
	id 			VARCHAR(7),
    title		VARCHAR(100),
    dept_name	VARCHAR(20),
    credits	INT,
    PRIMARY KEY(id)
);

INSERT INTO course
VALUES ('BIO-101', 'Intro. to Biology', 'Biology', 4);

INSERT INTO course
VALUES ('BIO-301', 'Computational Biology', 'Biology', 4);

INSERT INTO course
VALUES ('BIO-399', 'Genetics', 'Biology', 3);

INSERT INTO course
VALUES ('CS-101', 'Intro. to Computer Science', 'Comp.Sci.', 4);

INSERT INTO course
VALUES ('CS-190', 'Game Design', 'Comp.Sci.', 4);

INSERT INTO course
VALUES ('CS-315', 'Robotics', 'Comp.Sci.', 3);

INSERT INTO course
VALUES ('CS-319', 'Image Processing', 'Comp.Sci.', 3);

INSERT INTO course
VALUES ('CS-347', 'Database System Concepts', 'Comp.Sci.', 3);

INSERT INTO course
VALUES ('EE-181', 'Intro. to Digital System', 'Elec.Eng.', 3);

INSERT INTO course
VALUES ('FIN-201', 'Investment Banking', 'Finance', 3);

INSERT INTO course
VALUES ('HIS-351', 'World History', 'History', 3);

INSERT INTO course
VALUES ('MU-199', 'Music Video Production', 'Music', 3);

INSERT INTO course
VALUES ('PHY-101', 'Physycal Principles', 'Physics', 4);