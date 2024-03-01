

-- create database
CREATE DATABASE college;
-- show database
 SHOW DATABASES;
-- use database
use college;

-- create tables
CREATE TABLE course
(
c_code INT PRIMARY KEY,
c_name VARCHAR(15)
);

-- insert values 
INSERT INTO course values
(101,'java'),
(102,'cpp');

CREATE TABLE faculty
     (
    f_id INT PRIMARY KEY,
    f_name VARCHAR(20),
    f_email VARCHAR(20),
    c_code INT,
    FOREIGN KEY (c_code) references course(c_code)
    );
    
INSERT INTO faculty (f_id,f_name,f_email,c_code) 
values (10,'Anu','anu@gmail.com',101),
(20,'Meka','meka@gmail.com',102),
(30,'sravs','sravs@gmail.com',102),
(40,'harshini','harshu@gmail.com',101)
;
 
-- alter 
ALTER table faculty 
add f_gender VARCHAR(10);

UPDATE faculty
SET f_gender = 'female'
WHERE f_id IN (10, 20, 30, 40);
 
 -- join 
SELECT course.c_code, course.c_name, faculty.f_id, faculty.f_name, faculty.f_email, faculty.f_gender
FROM course
INNER JOIN faculty ON course.c_code = faculty.c_code;

-- insert 
 Insert into course(c_code,c_name)
 values(103,'python'),
 (104,'MYSQL'),
 (105,'HTML');
 
 select * from course;

-- left outer join
SELECT course.c_code, course.c_name, faculty.f_id, faculty.f_name,
faculty.f_email, faculty.f_gender FROM course LEFT OUTER JOIN faculty ON course.c_code = faculty.c_code;

-- right outer join
SELECT course.c_code, course.c_name, faculty.f_id, faculty.f_name,
faculty.f_email, faculty.f_gender FROM course right OUTER JOIN faculty ON course.c_code = faculty.c_code;

-- insert 
Insert into faculty(f_id,f_name,f_email,f_gender,c_code)
values(50,'haswanth','hash@gmail.com','male',105),
(60,'ubedulla','ube@gmail.com','male',103);

-- full outer join
SELECT course.c_code, course.c_name, faculty.f_id, faculty.f_name, faculty.f_email, faculty.f_gender
FROM course
LEFT OUTER JOIN faculty ON course.c_code = faculty.c_code
UNION
SELECT course.c_code, course.c_name, faculty.f_id, faculty.f_name, faculty.f_email, faculty.f_gender
FROM course
RIGHT OUTER JOIN faculty ON course.c_code = faculty.c_code;

-- procedures
DELIMITER //
CREATE PROCEDURE update_f_email(IN f_email VARCHAR(100), IN name VARCHAR(20))
BEGIN
    UPDATE faculty
    SET f_email = f_email
    WHERE f_name = name;
END //
call update_f_email('mental@gmail.com','ubedulla');
DELIMITER ;

-- drop procedures
DROP PROCEDURE IF EXISTS update_f_email;

-- Create Event to Update Faculty Name
CREATE EVENT update_faculty_name_event
ON SCHEDULE AT CURRENT_TIMESTAMP + INTERVAL 1 MINUTE
DO
BEGIN
    UPDATE faculty
    SET f_name = 'Meharaj'
    WHERE f_id = 20;
END;

SHOW events;

select * from faculty;





