USE dbsystem;

SELECT AVG(salary) FROM instructor;

SELECT MIN(salary) FROM instructor;

SELECT MAX(salary) FROM instructor;

SELECT SUM(salary) FROM instructor;

SELECT COUNT(salary) FROM instructor;

SELECT COUNT(salary) FROM instructor
WHERE salary > 70000;

SELECT dept_name FROM instructor
GROUP BY dept_name;

SELECT dept_name FROM student
GROUP BY dept_name;

SELECT dept_name FROM instructor
GROUP BY dept_name
HAVING dept_name LIKE '_i%';

SELECT name, salary 
FROM instructor
WHERE dept_name NOT IN
(
	SELECT dept_name
	FROM student
	WHERE dept_name LIKE 'F%'
);

SELECT name, salary
FROM instructor
WHERE salary < ALL
(
	SELECT salary
	FROM instructor
	WHERE name LIKE '%i%'
);

SELECT * 
FROM instructor
WHERE EXISTS
(
	SELECT dept_name
	FROM student
	WHERE tot_cred > 20
);

SELECT * 
FROM (
	SELECT DISTINCT dept_name
	FROM student
	) AS tmp
WHERE tmp.dept_name LIKE '_i%';