-- create database
CREATE DATABASE College;
-- show databases
 show databases;
 
-- use database
USE College;

-- create tables
CREATE TABLE IF NOT EXISTS course (
    c_code INT PRIMARY KEY,
    c_name VARCHAR(15)
);

-- insert values into course table
/*INSERT INTO course (c_code, c_name) VALUES
(101, 'java'),
(102, 'cpp');
*/

CREATE TABLE IF NOT EXISTS faculty (
    f_id INT PRIMARY KEY,
    f_name VARCHAR(20),
    f_email VARCHAR(50),
    c_code INT,
    f_gender VARCHAR(10),
    FOREIGN KEY (c_code) REFERENCES course(c_code)
);

-- insert values into faculty table
INSERT INTO faculty (f_id, f_name, f_email, c_code) VALUES
(10, 'Anu', 'anu@gmail.com', 101),
(20, 'Meka', 'meka@gmail.com', 102),
(30, 'sravs', 'sravs@gmail.com', 102),
(40, 'harshini', 'harshu@gmail.com', 101);

-- alter table to add f_gender column
ALTER TABLE faculty ADD COLUMN f_gender VARCHAR(10);

-- update f_gender for specific faculty members
UPDATE faculty
SET f_gender = 'female'
WHERE f_id IN (10, 20, 30, 40);

-- insert additional rows into course table
INSERT INTO course (c_code, c_name) VALUES
(103, 'python'),
(104, 'MYSQL'),
(105, 'HTML');

-- insert additional rows into faculty table
INSERT INTO faculty (f_id, f_name, f_email, f_gender, c_code) VALUES
(50, 'haswanth', 'hash@gmail.com', 'male', 105),
(60, 'ubedulla', 'ube@gmail.com', 'male', 103);

-- perform a join
SELECT course.c_code, course.c_name, faculty.f_id, faculty.f_name, faculty.f_email, faculty.f_gender
FROM course
INNER JOIN faculty ON course.c_code = faculty.c_code;

-- left outer join
SELECT course.c_code, course.c_name, faculty.f_id, faculty.f_name, faculty.f_email, faculty.f_gender
FROM course
LEFT OUTER JOIN faculty ON course.c_code = faculty.c_code;

-- right outer join
SELECT course.c_code, course.c_name, faculty.f_id, faculty.f_name, faculty.f_email, faculty.f_gender
FROM course
RIGHT OUTER JOIN faculty ON course.c_code = faculty.c_code;

-- full outer join
SELECT course.c_code, course.c_name, faculty.f_id, faculty.f_name, faculty.f_email, faculty.f_gender
FROM course
LEFT OUTER JOIN faculty ON course.c_code = faculty.c_code
UNION
SELECT course.c_code, course.c_name, faculty.f_id, faculty.f_name, faculty.f_email, faculty.f_gender
FROM course
RIGHT OUTER JOIN faculty ON course.c_code = faculty.c_code;

-- define procedure to update f_email
DELIMITER //
CREATE PROCEDURE update_f_email(IN p_f_email VARCHAR(100), IN name VARCHAR(20))
BEGIN
    UPDATE faculty
    SET f_email = p_f_email
    WHERE f_name = name;
END //
DELIMITER ;

-- call the procedure to update f_email for ubedulla
CALL update_f_email('ube@gmail.com', 'ubedulla');

-- drop the procedure
DROP PROCEDURE IF EXISTS update_f_email;

-- update f_email for specified faculty members
UPDATE faculty
SET f_email = CASE 
    WHEN f_name = 'Anu' THEN 'anu@gmail.com'
    WHEN f_name = 'Meka' THEN 'meka@gmail.com'
    WHEN f_name = 'sravs' THEN 'sravs@gmail.com'
    WHEN f_name = 'harshini' THEN 'harshu@gmail.com'
    WHEN f_name = 'haswanth' THEN 'hash@gmail.com'
    WHEN f_name = 'ubedulla' THEN 'ube@gmail.com'
    ELSE f_email
END;

