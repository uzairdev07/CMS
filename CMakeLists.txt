cmake_minimum_required(VERSION 3.0)
project(CMS)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        CMS
        main.cpp
        CSVParser/CSVParser.cpp
        CSVParser/CSVParser.h
        CSVParser/CSVRow.cpp
        CSVParser/CSVRow.h
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
        objects/department/department.cpp
        objects/department/department.h
        objects/department/Departments.cpp
        objects/department/Departments.h
        objects/library/books/book.h
        objects/library/books/book.cpp
        objects/library/books/Book.h
        objects/library/books/Books.cpp
        utilities/menu.cpp
        utilities/menu.h
        helpers/style.cpp
        helpers/Const.cpp
)
