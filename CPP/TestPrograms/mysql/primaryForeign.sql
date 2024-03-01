-- create database
CREATE DATABASE University;

-- show databases
SHOW databases;
-- use databases
USE University;
 
-- create course table
CREATE TABLE course
(
cid INT PRIMARY KEY,
cname VARCHAR(20)
);

-- create faculty table
CREATE TABLE faculty
(
fid INT PRIMARY KEY,
fname VARCHAR(20),
femail VARCHAR(30),
cid INT,
FOREIGN KEY(cid) REFERENCES course(cid)
);
 -- insert values in course
INSERT INTO course values(501,'java'),(502,'CPP'),(503,'MYSQL');

-- select
SELECT * FROM course;

-- insert values in faculty
INSERT INTO faculty (fid,fname,femail,cid) 
values(10,'sravani','sravs@gmail.com',501),
      (20,'meharaj','meka@gmail.com',502),
      (30,'ubedulla','ubedul@gmail.com',502),
      (40,'haswanth','hash@gmail.com',503),
      (50,'harshini','harsh@gmail.com',503);

-- select 
SELECT * FROM faculty;	
