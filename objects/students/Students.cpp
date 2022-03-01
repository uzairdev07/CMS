//
// Created by Mr. Uzair on 2/24/2022.
//

#include "Students.h"

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
    for (auto col : header)
        cout << setw(15) << col.getString(0)
             << setw(15) << col.getString(1)
             << setw(15) << col.getString(2)
             << setw(15) << col.getString(3)
             << setw(15) << col.getString(4)
             << setw(15) << col.getString(5)
             << endl;
    printLine();
    for (auto student : students)
        cout << setw(15) << student.getInt(0)
             << setw(15) << student.getString(1)
             << setw(15) << student.getString(2)
             << setw(15) << student.getString(3)
             << setw(15) << student.getString(4)
             << setw(15) << student.getString(5)
             << endl;
}

// ? Search by Student Id
student Students::searchStudent(int id) {
    CSVParser parser;
    vector<CSVRow> students = parser.read(STUDENTS_FILE);
    for (CSVRow row : students)
        if (id == row.getInt(0))
            return student (
                    row.getInt(0),
                    row.getString(1),
                    row.getString(2),
                    row.getString(3),
                    row.getString(4),
                    row.getString(5)
            );
}

// ? Search by Student Name
vector<student> Students::searchStudent(string name) {
    CSVParser parser;
    vector<CSVRow> students = parser.read(STUDENTS_FILE);
    vector<student> st;
    for (CSVRow row : students)
        if (name == row.getString(1))
            st.push_back (
                    student (
                            row.getInt(0),
                            row.getString(1),
                            row.getString(2),
                            row.getString(3),
                            row.getString(4),
                            row.getString(5)
                    )
            );
    return st;
}

// ? Get Number of Students
int Students::getSize() const {
    CSVParser parser;
    vector<CSVRow> students = parser.read(STUDENTS_FILE);
    return students.size();
}

// ? Print Header Bottom Border
void Students::printLine() const {
    cout << setw(8);
    for (int i = 0; i < 90; i++)
        (i < 89) ? (cout << "_") : (cout << endl);
}

// ? Destructor
Students::~Students() {

}
