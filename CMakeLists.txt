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
        helpers/const.cpp
        objects/courses/course.h
        objects/courses/course.cpp
        objects/courses/courses.h
        objects/courses/courses.cpp
        objects/students/student.h
        objects/students/student.cpp
        objects/students/Students.h
        objects/students/Students.cpp
)
