USE dbsystem;

CREATE TABLE instructor
(
	id			VARCHAR(5),
    name		VARCHAR(20) NOT NULL,
    dept_name	VARCHAR(20),
    salary		INT,
    PRIMARY KEY(id)
);

INSERT INTO instructor
VALUES
(
	'22222',
    'Einstein',
    'Physics',
    95000
);

INSERT INTO instructor
VALUES
(
	'12121',
    'Wu',
    'Finance',
    90000
);

INSERT INTO instructor
VALUES
(
	'32343',
    'El Said',
    'History',
    60000
);

INSERT INTO instructor
VALUES
(
	'45565',
    'Katz',
    'Comp.Sci.',
    75000
);

INSERT INTO instructor
VALUES
(
	'98345',
    'Kim',
    'Elec.Eng',
    80000
);

INSERT INTO instructor
VALUES
(
	'76766',
    'Crick',
    'Biology',
    72000
);

INSERT INTO instructor
VALUES
(
	'10101',
    'Srinivasan',
    'Comp.Sci.',
    65000
);

INSERT INTO instructor
VALUES
(
	'58583',
    'Clifieri',
    'History',
    62000
);

INSERT INTO instructor
VALUES
(
	'83821',
    'Brandt',
    'Comp.Sci.',
    92000
);

INSERT INTO instructor
VALUES
(
	'15151',
    'Mozart',
    'Music',
    40000
);

INSERT INTO instructor
VALUES
(
	'33456',
    'Gold',
    'Physics',
    87000
);

INSERT INTO instructor
VALUES
(
	'76543',
    'Singh',
    'Finance',
    80000
);