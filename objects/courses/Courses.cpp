//
// Created by Mr. Uzair on 2/26/2022.
//

#include "Courses.h"
#include "../../helpers/style.cpp"
#include "../../helpers/Const.cpp"
#include "../../utilities/menu.h"
#include "../department/Departments.h"
#include <conio.h>

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

// ? Print all Courses
void Courses::getTotalCourses() const {
    CSVParser parser;
    vector<CSVRow> header = parser.getHeader(COURSES_FILE);
    vector<CSVRow> courses = parser.read(COURSES_FILE);
    for ( auto col: header )
        cout << setw(COL_WIDTH) << col.getString(0)
             << setw(COL_WIDTH) << col.getString(1)
             << setw(COL_WIDTH) << col.getString(2)
             << setw(COL_WIDTH) << col.getString(3)
             << setw(COL_WIDTH) << col.getString(4)
             << endl;
    printLine(75);
    for ( auto course: courses )
        cout << setw(COL_WIDTH) << course.getInt(0)
             << setw(COL_WIDTH) << course.getString(1)
             << setw(COL_WIDTH) << course.getInt(2)
             << setw(COL_WIDTH) << course.getString(3)
             << setw(COL_WIDTH) << getDepartmentName(course.getInt(4))
             << endl;
}

// ? Search Course by Id
void Courses::searchById(int id) {
    CSVParser parser;
    vector<CSVRow> rows = parser.search(COURSES_FILE, id, 0);
    printCourses(rows);
}

// ? Search Course by Data
vector<CSVRow> Courses::searchCourse(string data, int index) {
    CSVParser parser;
    vector<CSVRow> courses = parser.search(COURSES_FILE, data, index);
    return courses;
}

// ? Search Course by Data
vector<CSVRow> Courses::searchCourse(float data, int index) {
    CSVParser parser;
    vector<CSVRow> courses = parser.search(COURSES_FILE, data, index);
    return courses;
}

// ? Search Course by Name
void Courses::searchByName(string name) {
    vector<CSVRow> records = searchCourse(name, 1);
    printCourses(records);
}

// ? Search Course by Fee
void Courses::searchByFee(float fee) {
    vector<CSVRow> records = searchCourse(fee, 2);
    printCourses(records);
}

// ? Search Course by Name
void Courses::searchByStartDate(string start_date) {
    vector<CSVRow> records = searchCourse(start_date, 3);
    printCourses(records);
}

// ? Search Course by Department Name
void Courses::searchByDepartmentName(const string dep_name) const {
    CSVParser parser;
    Departments departments;
    int id = departments.getDepartmentId(dep_name);
    vector<CSVRow> records = parser.search(COURSES_FILE, id, 4);
    printCourses(records);
}

// ? Get Number of Courses
int Courses::getSize() const {
    CSVParser parser;
    vector<CSVRow> courses = parser.read(COURSES_FILE);
    return courses.size();
}

void Courses::printCourses(vector<CSVRow> records) const {
    if (records.size() != 0) {
        cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << "Fee" << setw(COL_WIDTH)
             << "Start Date" << setw(COL_WIDTH) << "Department Name" << endl;
        for (auto record: records)
            cout << setw(COL_WIDTH) << record.getInt(0)
                 << setw(COL_WIDTH) << record.getString(1)
                 << setw(COL_WIDTH) << record.getDouble(2)
                 << setw(COL_WIDTH) << record.getString(1)
                 << setw(COL_WIDTH) << getDepartmentName(record.getInt(4))
                 << endl;
    } else
        cerr << "No Records founded yet!..." << endl;
}

// ? Get Department Name by ID
string Courses::getDepartmentName(int dep_id) const {
    CSVParser parser;
    vector<CSVRow> records = parser.search(DEPARTMENTS_FILE, dep_id, 0);
    for (auto row : records)
        return row.getString(1);
}

// ? Display Menu
void Courses::displayMenu() const {
    for ( int i = 0; i < options.size(); i++ )
        cout << setw(WIDTH) << i + 1 << ". " << options.at(i) << endl;
}

// ? Display Search Menu
void Courses::displaySearchMenu() const {
    for ( int i = 0; i < searchOptions.size(); i++ )
        cout << setw(WIDTH) << i + 1 << ". " << searchOptions.at(i) << endl;
}

// ? Select Menu
void Courses::select() {
    display:
    clear();
    displayMenu();
    int id, key;
    float fee;
    string name, startDate, dep_name;
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
                    getTotalCourses();
                    cout << "Enter id: ";
                    cin >> id;
                    searchById(id);
                    break;
                case 2:
                    clear();
                    getTotalCourses();
                    cout << "Enter Name: ";
                    cin >> name;
                    searchByName(name);
                    break;
                case 3:
                    clear();
                    getTotalCourses();
                    cout << "Enter Fee: ";
                    cin >> fee;
                    searchByFee(fee);
                    break;
                case 4:
                    clear();
                    getTotalCourses();
                    cout << "Enter Start Date: ";
                    cin >> startDate;
                    searchByStartDate(startDate);
                    break;
                case 5:
                    clear();
                    getTotalCourses();
                    cout << "Enter Department Name: ";
                    cin >> dep_name;
                    searchByDepartmentName(dep_name);
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
            getTotalCourses();
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

// ? Get Course ID by Name
int Courses::getCourseId(const string course_name) const {
    CSVParser parser;
    vector<CSVRow> records = parser.search(COURSES_FILE, course_name, 1);
    for (auto row: records)
        return row.getInt(0);
}

// ? Destructor
Courses::~Courses() {

}
