USE dbsystem;

CREATE TABLE student
(
	id			VARCHAR(5),
    name		VARCHAR(20) NOT NULL,
    dept_name	VARCHAR(20),
    tot_cred	INT,
    PRIMARY KEY(id)
);

INSERT INTO student
VALUES
(
	'00128',
    'Zhang',
    'Comp.Sci.',
    102
);

INSERT INTO student
VALUES
(
	'12345',
    'Shankar',
    'Comp.Sci.',
    32
);

INSERT INTO student
VALUES
(
	'19991',
    'Brandt',
    'History',
    80
);

INSERT INTO student
VALUES
(
	'23121',
    'Chavez',
    'Finance',
    110
);

INSERT INTO student
VALUES
(
	'44553',
    'Peltier',
    'Physics',
    56
);

INSERT INTO student
VALUES
(
	'45678',
    'Levy',
    'Physics',
    46
);

INSERT INTO student
VALUES
(
	'54321',
    'Williams',
    'Comp.Sci.',
    54
);

INSERT INTO student
VALUES
(
	'55739',
    'Sanchez',
    'Music',
    38
);

INSERT INTO student
VALUES
(
	'70557',
    'Snow',
    'Physics',
    0
);

INSERT INTO student
VALUES
(
	'76543',
    'Brown',
    'Comp.Sci.',
    58
);

INSERT INTO student
VALUES
(
	'76653',
    'Aoi',
    'Elec.Eng.',
    60
);

INSERT INTO student
VALUES
(
	'98765',
    'Bourikas',
    'Elec.Eng.',
    98
);