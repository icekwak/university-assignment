USE dbsystem;

CREATE TABLE teaches (
	i_id		VARCHAR(5),
    c_id		VARCHAR(7),
    sec_id		VARCHAR(1),
    semester	VARCHAR(10),
    year		VARCHAR(4)
);

INSERT INTO teaches
VALUES ('10101', 'CS-101', '1', 'Fall', '2009');

INSERT INTO teaches
VALUES ('10101', 'CS-315', '1', 'Spring', '2010');

INSERT INTO teaches
VALUES ('10101', 'CS-347', '1', 'Fall', '2009');

INSERT INTO teaches
VALUES ('12121', 'FIN-201', '1', 'Spring', '2010');

INSERT INTO teaches
VALUES ('15151', 'MU-199', '1', 'Spring', '2010');

INSERT INTO teaches
VALUES ('22222', 'PHY-101', '1', 'Fall', '2009');

INSERT INTO teaches
VALUES ('32343', 'HIS-351', '1', 'Spring', '2010');

INSERT INTO teaches
VALUES ('45565', 'CS-101', '1', 'Spring', '2010');

INSERT INTO teaches
VALUES ('45565', 'CS-319', '1', 'Spring', '2010');

INSERT INTO teaches
VALUES ('76766', 'BIO-101', '1', 'Summer', '2009');

INSERT INTO teaches
VALUES ('76766', 'BIO-301', '1', 'Summer', '2010');

INSERT INTO teaches
VALUES ('83821', 'CS-190', '1', 'Spring', '2009');

INSERT INTO teaches
VALUES ('83821', 'CS-190', '2', 'Spring', '2009');

INSERT INTO teaches
VALUES ('83821', 'CS-319', '2', 'Spring', '2010');

INSERT INTO teaches
VALUES ('98345', 'EE-181', '1', 'Spring', '2009');