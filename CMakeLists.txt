cmake_minimum_required(VERSION 3.21)
project(CMS)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        CMS
        main.cpp
        CSVParser/CSVParser.cpp
        CSVParser/CSVParser.h
        CSVParser/CSVRow.cpp
        CSVParser/CSVRow.h
        helpers/Const.cpp
        objects/courses/course.h
        objects/courses/course.cpp
        objects/courses/Courses.h
        objects/courses/Courses.cpp
        objects/subjects/subject.h
        objects/subjects/subject.cpp
        objects/subjects/Subjects.h
        objects/subjects/Subjects.cpp
        objects/teachers/teacher.h
        objects/teachers/teacher.cpp
        objects/teachers/Teachers.h
        objects/teachers/Teachers.cpp
        objects/students/student.h
        objects/students/student.cpp
        objects/students/Students.h
        objects/students/Students.cpp
        helpers/style.cpp)
