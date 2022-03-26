//
// Created by Mr. Uzair on 2/24/2022.
//

#include "Students.h"
#include "../courses/Courses.h"
#include "../../CSVParser/CSVParser.h"
#include "../../helpers/Const.cpp"
#include "../../helpers/style.cpp"
#include "../../utilities/menu.h"
#include <conio.h>

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
            cout << setw(COL_WIDTH) << col.getString(0)
                 << setw(COL_WIDTH) << col.getString(1)
                 << setw(COL_WIDTH) << col.getString(2)
                 << setw(COL_WIDTH) << col.getString(3)
                 << setw(COL_WIDTH) << col.getString(4)
                 << setw(COL_WIDTH) << col.getString(5)
                 << endl;
        printLine(90);
        for ( auto student: students )
            cout << setw(COL_WIDTH) << student.getInt(0)
                 << setw(COL_WIDTH) << student.getString(1)
                 << setw(COL_WIDTH) << student.getString(2)
                 << setw(COL_WIDTH) << student.getString(3)
                 << setw(COL_WIDTH) << student.getString(4)
                 << setw(COL_WIDTH) << student.getString(5)
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
                    row.getInt(5)
            );
}

// ? Search by Student data
vector<student> Students::searchStudent(string data, int index) {
    CSVParser parser;
    vector<CSVRow> students = parser.read(STUDENTS_FILE);
    vector<student> st;
    for ( CSVRow row: students )
        if (data == row.getString(index))
            st.push_back(
                    student(
                            row.getInt(0),
                            row.getString(1),
                            row.getString(2),
                            row.getString(3),
                            row.getString(4),
                            row.getInt(5)
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
vector<student> Students::searchByCourse(string course_name) {
    CSVParser parser;
    vector<CSVRow> records = parser.read(STUDENTS_FILE);
    vector<student> students;
    Courses courses;
    int id = courses.getCourseId(course_name);
    for (auto row : records)
        if (row.getInt(5) == id)
            students.push_back(
                    student(
                            row.getInt(0),
                            row.getString(1),
                            row.getString(2),
                            row.getString(3),
                            row.getString(4),
                            row.getInt(5)
                    )
            );
    return students;
}

// ? Get Number of Students
int Students::getSize() const {
    CSVParser parser;
    vector<CSVRow> students = parser.read(STUDENTS_FILE);
    return students.size();
}

// ? Display Menu
void Students::displayMenu() const {
    clear();
    for ( int i = 0; i < options.size(); i++ )
        cout << setw(WIDTH) << i + 1 << ". " << options.at(i) << endl;
}

// ? Select Menu
void Students::select() {
    display:
    clear();
    displayMenu();
    int id;
    string name, dob, phone, address, courseName;
    student s, st;
    int n, key;
    again:
    cout << "Enter Number (Press 0 to go back): ";
    n = getche();
    n -= 48;
    if (n == 0)
        Menu m;
    switch (n) {
        clear();
        case 1:
            s.setStudent();
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
            cout << "Enter DOB: ";
            cin >> dob;
            searchByDob(dob);
            break;
        case 7:
            clear();
            cout << "Enter Phone: ";
            cin >> phone;
            searchByContact(phone);
            break;
        case 8:
            clear();
            cout << "Enter Address: ";
            cin >> address;
            searchByAddress(address);
            break;
        case 9:
            clear();
            cout << "Enter Course Name: ";
            cin >> courseName;
            searchByCourse(courseName);
            break;
        case 10:
            clear();
            getTotalStudents();
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

// ? Destructor
Students::~Students() {

}
