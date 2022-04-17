//
// Created by Mr. Uzair on 2/24/2022.
//

#include "Students.h"
#include "../courses/Courses.h"
#include "../../helpers/Const.cpp"
#include "../../helpers/style.cpp"
#include "../../utilities/menu.h"
#include "../../utilities/Attendance.h"
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
    vector<CSVRow> students = parser.read(STUDENTS_FILE);
    if (!(students.size()) == 0)
        printStudents(students);
    else
        cerr << "No Record Founded Ye! ...";
}

// ? Search by Student Id
void Students::searchById(int id) {
    CSVParser parser;
    vector<CSVRow> students = parser.search(STUDENTS_FILE, id, 0);
    printStudents(students);
}

// ? Search by Student data
vector<CSVRow> Students::searchStudent(string data, int index) {
    CSVParser parser;
    vector<CSVRow> students = parser.search(STUDENTS_FILE, data, index);
    if (students.size() == 0) {
        cerr << "No Record Founded Yet! ...";
    }
    return students;
}

// ? Search By Student Name
void Students::searchByName(string name) {
    vector<CSVRow> records = searchStudent(name, 1);
    printStudents(records);
}

// ? Search By Student DOB
void Students::searchByDob(string dob) {
    vector<CSVRow> records = searchStudent(dob, 2);
    printStudents(records);
}

// ? Search By Student Contact
void Students::searchByContact(string contact) {
    vector<CSVRow> records = searchStudent(contact, 3);
    printStudents(records);
}

// ? Search By Student Address
void Students::searchByAddress(string address) {
    vector<CSVRow> records = searchStudent(address, 4);
    printStudents(records);
}

// ? Search By Student Course
void Students::searchByCourse(string course_name) {
    CSVParser parser;
    Courses courses;
    int id = courses.getCourseId(course_name);
    vector<CSVRow> records = parser.search(STUDENTS_FILE, id, 5);
    printStudents(records);
}

// ? Get Number of Students
int Students::getSize() const {
    CSVParser parser;
    vector<CSVRow> students = parser.read(STUDENTS_FILE);
    return students.size();
}

// ? Get Course Name By Id
string Students::getCourseName(int id) const {
    CSVParser parser;
    vector<CSVRow> records = parser.search(COURSES_FILE, id, 0);
    for ( auto row: records )
        return row.getString(1);
}

void Students::printStudents(vector<CSVRow> records) const {
    // * values for controlling format
    const int STR_WIDTH = 15;
    const int INT_WIDTH = 7;
    const int DBL_WIDTH = 12;
    const int NUM_FIELDS = 7;
    const string SEP = " |";
    const int TOTAL_WIDTH = STR_WIDTH * 2 + INT_WIDTH * 2 + DBL_WIDTH * 3 + SEP.size() * NUM_FIELDS;
    const string LINE = SEP + string(TOTAL_WIDTH - 1, '-') + '|';
    if (records.size() != 0) {
        cout << LINE << '\n' << SEP
             << setw(INT_WIDTH) << col_names[0] << SEP
             << setw(STR_WIDTH) << col_names[1] << SEP
             << setw(STR_WIDTH) << col_names[2] << SEP
             << setw(STR_WIDTH) << col_names[3] << SEP
             << setw(STR_WIDTH) << col_names[4] << SEP
             << setw(STR_WIDTH) << col_names[5] << SEP
             << '\n' << LINE << '\n';
        for (auto record: records)
            cout << SEP << setw(INT_WIDTH) << record.getInt(0)
                 << SEP << setw(STR_WIDTH) << record.getString(1)
                 << SEP << setw(STR_WIDTH) << record.getString(2)
                 << SEP << setw(STR_WIDTH) << record.getString(3)
                 << SEP << setw(STR_WIDTH) << record.getString(4)
                 << SEP << setw(STR_WIDTH) << getCourseName(record.getInt(5))
                 << SEP << '\n';
        cout << LINE << '\n';
    } else
        cerr << "No Records founded yet!..." << endl;
}

void Students::takeAttendance() {
    getTotalStudents();
    vector<int> absent_students;
    Attendance attendance;
    int n {};
    input:
    cout << "Enter the student id (Press 0 to save): ";
    n = getche();
    n -= 48;
    if (n == 0)
        goto con;
    else {
        absent_students.push_back(n);
        cout << endl;
        goto input;
    }
    con:
    for (auto id: absent_students) {
        cout << "Student Id: " << id << endl;
        attendance.takeAttendance(id, 0);
    }
    cout << "Attendance taken successfully!" << endl;
}

// ? Display Menu
void Students::displayMenu() const {
    for ( int i = 0; i < options.size(); i++ )
        cout << setw(WIDTH) << i + 1 << ". " << options.at(i) << endl;
}

// ? Display Search Menu
void Students::displaySearchMenu() const {
    for ( int i = 0; i < searchOptions.size(); i++ )
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
                    getline(cin, name);
                    searchByName(name);
                    break;
                case 3:
                    clear();
                    getTotalStudents();
                    cout << "Enter DOB: ";
                    getline(cin, dob);
                    searchByDob(dob);
                    break;
                case 4:
                    clear();
                    getTotalStudents();
                    cout << "Enter Contact: ";
                    getline(cin, contact);
                    searchByContact(contact);
                    break;
                case 5:
                    clear();
                    getTotalStudents();
                    cout << "Enter Address: ";
                    getline(cin, address);
                    searchByAddress(address);
                    break;
                case 6:
                    clear();
                    getTotalStudents();
                    cout << "Enter Course Name: ";
                    getline(cin, course_name);
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
            takeAttendance();
            break;
        case 6:
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
