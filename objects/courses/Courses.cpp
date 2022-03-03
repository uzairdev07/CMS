//
// Created by Mr. Uzair on 2/26/2022.
//

#include "Courses.h"
#include "../../CSVParser/CSVParser.h"
#include "../../helpers/style.cpp"
#include "../../helpers/Const.cpp"

/*
 *  Constructors
 *  Operator Overloading
 *  Methods
 *  Destructor
*/

// ? Constructor
Courses::Courses() {

}

// ? Overloading Constructor

// ? Operator Overloading

// * Methods

// ? Print all Subjects
void Courses::getTotalCourses() const {
    CSVParser parser;
    vector<CSVRow> header = parser.getHeader(COURSES_FILE);
    vector<CSVRow> courses = parser.read(COURSES_FILE);
    for (auto col: header)
        cout << setw(15) << col.getString(0)
             << setw(15) << col.getString(1)
             << setw(15) << col.getString(2)
             << setw(15) << col.getString(3)
             << endl;
    printLine(60);
    for (auto course: courses)
        cout << setw(15) << course.getInt(0)
             << setw(15) << course.getString(1)
             << setw(15) << course.getInt(2)
             << setw(15) << course.getString(3)
             << endl;
}

// ? Search Course by Id
course Courses::searchCourse(int id) {
    CSVParser parser;
    vector<CSVRow> courses = parser.read(COURSES_FILE);
    for (CSVRow row: courses)
        if (id == row.getInt(0))
            return course(
                    row.getInt(0),
                    row.getString(1),
                    row.getInt(2),
                    row.getString(3)
            );
}

// ? Search Course by Name
vector<course> Courses::searchCourse(string name) {
    CSVParser parser;
    vector<CSVRow> courses = parser.read(COURSES_FILE);
    vector<course> st;
    for (CSVRow row: courses)
        if (name == row.getString(1))
            st.push_back(
                    course(
                            row.getInt(0),
                            row.getString(1),
                            row.getInt(2),
                            row.getString(3)
                    )
            );
    return st;
}

// ? Get Number of Subjects
int Courses::getSize() const {
    CSVParser parser;
    vector<CSVRow> courses = parser.read(COURSES_FILE);
    return courses.size();
}

// ? Destructor
Courses::~Courses()
{

}