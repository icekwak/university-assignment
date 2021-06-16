USE dbsystem;

/* 재명명 연산 */
SELECT i.name, s.name
FROM instructor AS i, student AS s;

SELECT i.name, s.name
FROM instructor AS i, student AS s
WHERE i.salary < 70000 AND s.tot_cred > 100;

/* 스트링 연산 */
SELECT * FROM department
WHERE dept_name LIKE '%i%';

SELECT * FROM student
WHERE name LIKE '_h%';

/* 데이터 출력의 순서화 */
SELECT * FROM student
ORDER BY tot_cred DESC;

SELECT * FROM student
ORDER BY tot_cred;

/* UNION, UNION ALL (합집합) */
SELECT name
FROM instructor
UNION
SELECT name
FROM student;

SELECT name
FROM instructor
UNION ALL
SELECT name
FROM student;

/* INTERSECT (교집합) */
SELECT i.`name`
FROM instructor AS i INNER JOIN student AS s ON i.`name` = s.`name`;

/* EXCEPT (차집합) */
SELECT i.`name`
FROM instructor AS i LEFT JOIN student AS s ON i.`name` = s.`name`
WHERE s.`name` IS NULL;

/* 카티전 곱 */
SELECT *
FROM student, department;

/* INNER JOIN (WHERE 절을 이용) */
SELECT *
FROM student AS s, department AS d
WHERE s.dept_name = d.dept_name;

/* INNER JOIN (INNER JOIN과 ON을 이용) */
SELECT *
FROM instructor AS i INNER JOIN department AS d
ON i.dept_name = d.dept_name;

/* OUTER JOIN (LEFT) */
SELECT i.name AS 교수, s.name AS 학생
FROM instructor AS i LEFT JOIN student AS s
ON i.dept_name = s.dept_name;

/* OUTER JOIN (RIGHT) */
SELECT i.name AS 교수, s.name AS 학생
FROM instructor AS i RIGHT JOIN student AS s
ON i.dept_name = s.dept_name;

/* AVG */
SELECT AVG(salary) FROM instructor;

/* MIN */
SELECT MIN(salary) FROM instructor;

/* MAX */
SELECT MAX(salary) FROM instructor;

/* SUM */
SELECT SUM(salary) FROM instructor;

/* COUNT */
SELECT COUNT(salary) FROM instructor;

SELECT COUNT(salary) FROM instructor
WHERE salary > 70000;

/* GROUP BY, HAVING 절 */
SELECT dept_name FROM instructor
GROUP BY dept_name
HAVING dept_name LIKE '_i%';

/* IN & NOT IN */
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
WHERE dept_name IN
(
	SELECT dept_name
    FROM student
    WHERE dept_name LIKE 'F%'
);

/* SOME & ALL */
SELECT name, salary
FROM instructor
WHERE salary < ALL
(
	SELECT salary
    FROM instructor
    WHERE name LIKE '%i%'
);

SELECT name, salary
FROM instructor
WHERE salary < SOME
(
	SELECT salary
    FROM instructor
    WHERE name LIKE '%i%'
);

/* EXISTS & NOT EXISTS */
SELECT *
FROM instructor
WHERE EXISTS
(
	SELECT dept_name
    FROM student
    WHERE tot_cred > 20
);

SELECT *
FROM instructor
WHERE NOT EXISTS
(
	SELECT dept_name
    FROM student
    WHERE tot_cred > 20
);

/* FROM 절의 부질의 */
SELECT *
FROM (
	SELECT DISTINCT dept_name
    FROM student
    ) AS tmp
WHERE tmp.dept_name LIKE '_i%';

/* 2-1 */
SELECT DISTINCT c_id
FROM section
WHERE years = '2009';

/* 2-2 */
SELECT c_id, grade
FROM
(
	SELECT t.s_id, s.name, t.c_id, t.grade
    FROM student AS s INNER JOIN takes AS t
    ON s.id = t.s_id
) AS tmp
WHERE tmp.name = 'Zhang';

/* 2-3 */
SELECT DISTINCT c_id
FROM
(
	SELECT i.dept_name, t.year, t.c_id
    FROM instructor AS i INNER JOIN teaches AS t
    ON i.id = t.i_id
) AS tmp
WHERE tmp.dept_name = 'Comp.Sci.' AND tmp.year = '2009';

/* 2-4 */
SELECT s_id, SUM(credits) AS 모든학점
FROM
(
	SELECT *
    FROM takes AS t LEFT JOIN course AS c
    ON t.c_id = c.id
) AS tmp
GROUP BY tmp.s_id;