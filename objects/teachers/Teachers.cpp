//
// Created by Mr. Uzair on 2/24/2022.
//

#include "Teachers.h"
#include "../../CSVParser/CSVParser.h"
#include "../../helpers/Const.cpp"
#include "../../helpers/style.cpp"
#include "../../utilities/menu.h"
#include "../subjects/Subjects.h"
#include <conio.h>

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
        cout << setw(COL_WIDTH) << col.getString(0)
             << setw(COL_WIDTH) << col.getString(1)
             << setw(COL_WIDTH) << col.getString(2)
             << setw(COL_WIDTH) << col.getString(3)
             << setw(COL_WIDTH) << col.getString(4)
             << setw(COL_WIDTH) << col.getString(5)
             << endl;
    printLine(90);
    for (auto teacher: teachers)
        cout << setw(COL_WIDTH) << teacher.getInt(0)
             << setw(COL_WIDTH) << teacher.getString(1)
             << setw(COL_WIDTH) << teacher.getString(2)
             << setw(COL_WIDTH) << teacher.getString(3)
             << setw(COL_WIDTH) << teacher.getString(4)
             << setw(COL_WIDTH) << teacher.getInt(5)
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
                    row.getInt(5)
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
                            row.getInt(5)
                    )
            );
    cout << ts.size();
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
vector<teacher> Teachers::searchBySubject(string subject_name) {
    CSVParser parser;
    vector<CSVRow> records = parser.read(TEACHERS_FILE);
    vector<teacher> teachers;
    Subjects subjects;
    int id = subjects.getSubjectId(subject_name);
    for (auto row : records)
        if (row.getInt(5) == id)
            teachers.push_back(
                    teacher(
                            row.getInt(0),
                            row.getString(1),
                            row.getString(2),
                            row.getString(3),
                            row.getString(4),
                            row.getInt(5)
                    )
            );
    return teachers;
}

// ? Get Number of Teachers
int Teachers::getSize() const {
    CSVParser parser;
    vector<CSVRow> teachers = parser.read(TEACHERS_FILE);
    return teachers.size();
}

// ? Display Menu
void Teachers::displayMenu() const {
    for (int i = 0; i < options.size(); i++)
        cout << setw(WIDTH) << i + 1 << ". " << options.at(i) << endl;
}

// ? Select Menu
void Teachers::select() {
    display:
    clear();
    displayMenu();
    int id, key, course_id;
    string name, courseName;
    teacher t, tr;
    int n;
    again:
    cout << "Enter Number (Press 0 to go back): ";
    n = getche();
    n -= 48;
    if (n == 0)
        Menu m;
    switch (n) {
        case 1:
            clear();
            t.setTeacher();
            break;
        case 2:
            clear();
            break;
        case 3:
            clear();
            break;
        case 4:
            clear();
            cout << "Enter id: ";
            cin >> id;
            searchById(id);
            break;
        case 5:
            clear();
            cout << "Enter Name: ";
            cin >> name;
            searchByName(name);
            break;
        case 6:
            clear();
            cout << "Enter Subject Name: ";
            cin >> name;
            searchBySubject(name);
            break;
        case 7:
            clear();
            getTotalTeachers();
            break;
        default:
            cout << "Invalid Choice! try again..." << endl;
            clear();
            goto again;
    }
    cout << "Press 0 to go back: ";
    key = getche();
    key -= 48;
    if (key == 0)
        goto display;
}

// Destructors
Teachers::~Teachers() {

}