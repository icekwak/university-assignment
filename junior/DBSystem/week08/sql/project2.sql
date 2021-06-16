CREATE CLASS student UNDER people (
	grade		INT DEFAULT(1),
	course	SET (STRING)
);