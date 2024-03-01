-- use database
USE University;

-- INSERT
INSERT INTO course(cid,cname)
values(504,'python'),
      (505,'HTML');

-- select
-- select * from course;

-- inner join
SELECT course.cid,course.cname,faculty.fid,faculty.fname,faculty.femail
FROM course
INNER JOIN faculty ON course.cid = faculty.cid;

 -- select
-- SELECT * from faculty;

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

