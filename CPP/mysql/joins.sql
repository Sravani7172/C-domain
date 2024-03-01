-- create database
CREATE DATABASE university;

-- use database
use University;

-- create course table
CREATE TABLE course(
cid int PRIMARY KEY,
cname varchar(10));

-- INSERT course data
INSERT INTO course(cid,cname)
values(501,'JAVA'),
      (502,'CPP');
      (503,'PYTHON');

-- select ;
select * from course;

-- create faculty table
CREATE TABLE faculty(
fid int PRIMARY KEY,
fname varchar(20),
femail varchar(30),
cid int,
FOREIGN KEY(cid) references course(cid)
);

-- INSERT faculty 
INSERT INTO faculty(fid,fname,femail,cid)
values(10,'suma','suma123@gmail.com',501),
(20,'sumanth','sumanth456@gmail.com',503);

-- fetch data
select * from faculty;

-- inner join
SELECT course.cid,course.cname,faculty.fid,faculty.fname,faculty.femail
FROM course
INNER JOIN faculty ON course.cid = faculty.cid;

 -- select
 SELECT * from faculty;

-- left outer join
SELECT course.cid,course.cname,faculty.fid,faculty.fname,faculty.femail
FROM course
LEFT OUTER JOIN faculty ON course.cid = faculty.cid;
 
-- right outer join
SELECT course.cid,course.cname,faculty.fid,faculty.fname,faculty.femail
 FROM course
 RIGHT OUTER JOIN faculty ON course.cid = faculty.cid;

-- full outer join
SELECT course.cid,course.cname,faculty.fid,faculty.fname,faculty.femail
FROM course
LEFT OUTER JOIN faculty ON course.cid = faculty.cid 
UNION
SELECT course.cid,course.cname,faculty.fid,faculty.fname,faculty.femail
FROM course
RIGHT OUTER JOIN faculty ON course.cid = faculty.cid; 

