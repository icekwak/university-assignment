USE dbsystem;

CREATE TABLE department
(
	dept_name	VARCHAR(20),
    building	VARCHAR(15),
    budget		INT,
    PRIMARY KEY(dept_name)
);

INSERT INTO department
VALUES
(
	'Comp.Sci.',
    'Taylor',
    100000
);

INSERT INTO department
VALUES
(
	'Biology',
    'Watson',
    90000
);

INSERT INTO department
VALUES
(
	'Elec.Eng.',
    'Taylor',
    85000
);

INSERT INTO department
VALUES
(
	'Music',
    'Packard',
    80000
);

INSERT INTO department
VALUES
(
	'Finance',
    'Painter',
    120000
);

INSERT INTO department
VALUES
(
	'History',
    'Painter',
    50000
);

INSERT INTO department
VALUES
(
	'Physics',
    'Watson',
    70000
);