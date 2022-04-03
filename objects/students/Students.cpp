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
void Students::searchById(int id) {
    CSVParser parser;
    vector<CSVRow> students = parser.read(STUDENTS_FILE);
    vector<student> records;
    for ( CSVRow row: students )
        if (id == row.getInt(0))
            records.push_back(
                    student(
                            row.getInt(0),
                            row.getString(1),
                            row.getString(2),
                            row.getString(3),
                            row.getString(4),
                            row.getInt(5)
                    )
            );
    if (records.size() == 0)
        cerr << "No Record Founded Ye! ...";
    cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << "DOB" << setw(COL_WIDTH) << "Contact" << setw(COL_WIDTH) << "Address" << setw(COL_WIDTH) << "Course Id" << endl;
    for (auto s : records)
        cout << setw(COL_WIDTH) << s << endl;
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
    }
    return st;
}

// ? Search By Student Name
void Students::searchByName(string name) {
    vector<student> records = searchStudent(name, 1);
    if (records.size() == 0)
        cerr << "No Record Founded Ye! ...";
    cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << "DOB" << setw(COL_WIDTH) << "Contact" << setw(COL_WIDTH) << "Address" << setw(COL_WIDTH) << "Course Id" << endl;
    for (auto s : records)
        cout << setw(COL_WIDTH) << s << endl;

}

// ? Search By Student DOB
void Students::searchByDob(string dob) {
    vector<student> records = searchStudent(dob, 2);
    if (records.size() == 0)
        cerr << "No Record Founded Ye! ...";
    cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << "DOB" << setw(COL_WIDTH) << "Contact" << setw(COL_WIDTH) << "Address" << setw(COL_WIDTH) << "Course Id" << endl;
    for (auto s : records)
        cout << setw(COL_WIDTH) << s << endl;
}

// ? Search By Student Contact
void Students::searchByContact(string contact) {
    vector<student> records = searchStudent(contact, 3);
    if (records.size() == 0)
        cerr << "No Record Founded Ye! ...";
    cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << "DOB" << setw(COL_WIDTH) << "Contact" << setw(COL_WIDTH) << "Address" << setw(COL_WIDTH) << "Course Id" << endl;
    for (auto s : records)
        cout << setw(COL_WIDTH) << s << endl;
}

// ? Search By Student Address
void Students::searchByAddress(string address) {
    vector<student> records = searchStudent(address, 4);
    if (records.size() == 0)
        cerr << "No Record Founded Ye! ...";
    cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << "DOB" << setw(COL_WIDTH) << "Contact" << setw(COL_WIDTH) << "Address" << setw(COL_WIDTH) << "Course Id" << endl;
    for (auto s : records)
        cout << setw(COL_WIDTH) << s << endl;
}

// ? Search By Student Course
void Students::searchByCourse(string course_name) {
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
    if (records.size() == 0)
        cerr << "No Record Founded Ye! ...";
    cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << "DOB" << setw(COL_WIDTH) << "Contact" << setw(COL_WIDTH) << "Address" << setw(COL_WIDTH) << "Course Id" << endl;
    for (auto s : students)
        cout << setw(COL_WIDTH) << s << endl;
}

// ? Get Number of Students
int Students::getSize() const {
    CSVParser parser;
    vector<CSVRow> students = parser.read(STUDENTS_FILE);
    return students.size();
}

// ? Display Menu
void Students::displayMenu() const {
    for ( int i = 0; i < options.size(); i++ )
        cout << setw(WIDTH) << i + 1 << ". " << options.at(i) << endl;
}

// ? Display Search Menu
void Students::displaySearchMenu() const {
    for (int i = 0; i < searchOptions.size(); i++)
        cout << setw(WIDTH) << i + 1 << ". " << searchOptions.at(i) << endl;
}

// ? Select Menu
void Students::select() {
    display:
    clear();
    displayMenu();
    int id, key;
    string name, dob, contact, address, course_name;
    course c;
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
            c.setCourse();
            break;
        case 2:
            clear();
            break;
        case 3:
            clear();
            break;
        case 4:
        searchMenu:
            clear();
            displaySearchMenu();
            int n, key;
            cout << "Enter Number (Press 0 to go back): ";
            n = getche();
            n -= 48;
            if (n == 0)
                goto display;
            switch (n) {
                case 1:
                    clear();
                    getTotalStudents();
                    cout << "Enter id: ";
                    cin >> id;
                    searchById(id);
                    break;
                case 2:
                    clear();
                    getTotalStudents();
                    cout << "Enter Name: ";
                    cin >> name;
                    searchByName(name);
                    break;
                case 3:
                    clear();
                    getTotalStudents();
                    cout << "Enter DOB: ";
                    cin >> dob;
                    searchByDob(dob);
                    break;
                case 4:
                    clear();
                    getTotalStudents();
                    cout << "Enter Contact: ";
                    cin >> contact;
                    searchByContact(contact);
                    break;
                case 5:
                    clear();
                    getTotalStudents();
                    cout << "Enter Address: ";
                    cin >> address;
                    searchByAddress(address);
                    break;
                case 6:
                    clear();
                    getTotalStudents();
                    cout << "Enter Course Name: ";
                    cin >> course_name;
                    searchByCourse(course_name);
                    break;
            }
            cout << "Press 0 to go back: ";
            key = getche();
            key -= 48;
            if (key == 0)
                goto searchMenu;
            break;
        case 5:
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
