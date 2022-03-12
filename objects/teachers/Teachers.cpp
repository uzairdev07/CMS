//
// Created by Mr. Uzair on 2/24/2022.
//

#include "Teachers.h"
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
Teachers::Teachers() {}

// * Methods

// ? Display All Teachers
void Teachers::getTotalTeachers() const {
    CSVParser parser;
    vector<CSVRow> header = parser.getHeader(TEACHERS_FILE);
    vector<CSVRow> teachers = parser.read(TEACHERS_FILE);
    for (auto col : header)
        cout << setw(15) << col.getString(0)
             << setw(15) << col.getString(1)
             << setw(15) << col.getString(2)
             << setw(15) << col.getString(3)
             << setw(15) << col.getString(4)
             << setw(15) << col.getString(5)
             << endl;
    printLine(90);
    for (auto teacher: teachers)
        cout << setw(15) << teacher.getInt(0)
             << setw(15) << teacher.getString(1)
             << setw(15) << teacher.getString(2)
             << setw(15) << teacher.getString(3)
             << setw(15) << teacher.getString(4)
             << setw(15) << teacher.getString(5)
             << endl;
}

// ? Search by Teacher Id
teacher Teachers::searchById(int id) {
    CSVParser parser;
    vector<CSVRow> teachers = parser.read(TEACHERS_FILE);
    for (CSVRow row: teachers)
        if (id == row.getInt(0))
            return teacher(
                    row.getInt(0),
                    row.getString(1),
                    row.getString(2),
                    row.getString(3),
                    row.getString(4),
                    row.getString(5)
            );
}

// ? Search by Teacher Data
vector<teacher> Teachers::searchTeacher(string data, int index) {
    CSVParser parser;
    vector<CSVRow> teachers = parser.read(TEACHERS_FILE);
    vector<teacher> ts;
    for (CSVRow row : teachers)
        if (data == row.getString(index))
            ts.push_back (
                    teacher (
                            row.getInt(0),
                            row.getString(1),
                            row.getString(2),
                            row.getString(3),
                            row.getString(4),
                            row.getString(5)
                    )
            );
    if (ts.size() == 0) {
        cerr << "No record founded yet!";
        return ts;
    } else
        return ts;
}

// ? Search By Teacher Name
vector<teacher> Teachers::searchByName(string name) {
    return searchTeacher(name, 1);
}

// ? Search By Teacher DOB
vector<teacher> Teachers::searchByDob(string dob) {
    return searchTeacher(dob, 2);
}

// ? Search By Teacher Contact
vector<teacher> Teachers::searchByContact(string contact) {
    return searchTeacher(contact, 3);
}

// ? Search By Teacher Address
vector<teacher> Teachers::searchByAddress(string address) {
    return searchTeacher(address, 4);
}

// ? Search By Teacher Subject
vector<teacher> Teachers::searchBySubject(string subject) {
    return searchTeacher(subject, 5);
}

// ? Get Number of Teachers
int Teachers::getSize() const {
    CSVParser parser;
    vector<CSVRow> teachers = parser.read(TEACHERS_FILE);
    return teachers.size();
}

// Destructors
Teachers::~Teachers() {

}
