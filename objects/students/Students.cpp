//
// Created by Mr. Uzair on 2/24/2022.
//

#include "Students.h"
#include "../../CSVParser/CSVParser.h"
#include "../../helpers/Const.cpp"
#include "../../helpers/style.cpp"

/*
 *  Constructors
 *  Operator Overloading
 *  Methods
 *  Destructor
*/

// ? Constructor
Students::Students() {}

// ? Overloading Constructor

// ? Operator Overloading


// * Methods

// ? Display All Students
void Students::getTotalStudents() const {
    CSVParser parser;
    vector<CSVRow> header = parser.getHeader(STUDENTS_FILE);
    vector<CSVRow> students = parser.read(STUDENTS_FILE);
    if (!(students.size()) == 0) {
        for ( auto col: header )
            cout << setw(15) << col.getString(0)
                 << setw(15) << col.getString(1)
                 << setw(15) << col.getString(2)
                 << setw(15) << col.getString(3)
                 << setw(15) << col.getString(4)
                 << setw(15) << col.getString(5)
                 << endl;
        printLine(90);
        for ( auto student: students )
            cout << setw(15) << student.getInt(0)
                 << setw(15) << student.getString(1)
                 << setw(15) << student.getString(2)
                 << setw(15) << student.getString(3)
                 << setw(15) << student.getString(4)
                 << setw(15) << student.getString(5)
                 << endl;
    } else
        cerr << "No Record Founded Ye! ...";
}

// ? Search by Student Id
student Students::searchById(int id) {
    CSVParser parser;
    vector<CSVRow> students = parser.read(STUDENTS_FILE);
    for ( CSVRow row: students )
        if (id == row.getInt(0))
            return student(
                    row.getInt(0),
                    row.getString(1),
                    row.getString(2),
                    row.getString(3),
                    row.getString(4),
                    row.getString(5)
            );
}

// ? Search by Student data
vector<student> Students::searchStudent(string data, int index) {
    CSVParser parser;
    vector<CSVRow> students = parser.read(STUDENTS_FILE);
    vector<student> st;
    for (CSVRow row: students)
        if (data == row.getString(index))
            st.push_back(
                    student(
                            row.getInt(0),
                            row.getString(1),
                            row.getString(2),
                            row.getString(3),
                            row.getString(4),
                            row.getString(5)
                    )
            );
    if (students.size() == 0) {
        cerr << "No Record Founded Yet! ...";
        return st;
    } else
        return st;
}

// ? Search By Student Name
vector<student> Students::searchByName(string name) {
    return searchStudent(name, 1);
}

// ? Search By Student DOB
vector<student> Students::searchByDob(string dob) {
    return searchStudent(dob, 2);
}

// ? Search By Student Contact
vector<student> Students::searchByContact(string contact) {
    return searchStudent(contact, 3);
}

// ? Search By Student Address
vector<student> Students::searchByAddress(string address) {
    return searchStudent(address, 4);
}

// ? Search By Student Course
vector<student> Students::searchByCourse(string course) {
    return searchStudent(course, 5);
}

// ? Get Number of Students
int Students::getSize() const {
    CSVParser parser;
    vector<CSVRow> students = parser.read(STUDENTS_FILE);
    return students.size();
}

// ? Destructor
Students::~Students() {

}
