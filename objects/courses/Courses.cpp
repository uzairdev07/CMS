//
// Created by Mr. Uzair on 2/26/2022.
//

#include "Courses.h"
#include "../../CSVParser/CSVParser.h"
#include "../../helpers/style.cpp"
#include "../../helpers/Const.cpp"
#include "../../utilities/menu.h"

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
        cout << setw(COL_WIDTH) << col.getString(0)
             << setw(COL_WIDTH) << col.getString(1)
             << setw(COL_WIDTH) << col.getString(2)
             << setw(COL_WIDTH) << col.getString(3)
             << endl;
    printLine(60);
    for (auto course: courses)
        cout << setw(COL_WIDTH) << course.getInt(0)
             << setw(COL_WIDTH) << course.getString(1)
             << setw(COL_WIDTH) << course.getInt(2)
             << setw(COL_WIDTH) << course.getString(3)
             << endl;
}

// ? Search Course by Id
course Courses::searchById(int id) {
    CSVParser parser;
    vector<CSVRow> courses = parser.read(COURSES_FILE);
    for (CSVRow row: courses)
        if (id == row.getInt(0))
            return course(
                    row.getInt(0),
                    row.getString(1),
                    row.getDouble(2),
                    row.getString(3)
            );
}

// ? Search Course by Data
vector<course> Courses::searchCourse(string data, int index) {
    CSVParser parser;
    vector<CSVRow> courses = parser.read(COURSES_FILE);
    vector<course> st;
    for (CSVRow row: courses)
        if (data == row.getString(index))
            st.push_back(
                    course(
                            row.getInt(0),
                            row.getString(1),
                            row.getDouble(2),
                            row.getString(3)
                    )
            );
    if (st.size() == 0) {
        cerr << "No Record Founded Ye! ...";
        return st;
    } else
        return st;
}

// ? Search Course by Data
vector<course> Courses::searchCourse(float data, int index) {
    CSVParser parser;
    vector<CSVRow> courses = parser.read(COURSES_FILE);
    vector<course> st;
    for (CSVRow row: courses)
        if (data == row.getDouble(index))
            st.push_back(
                    course(
                            row.getInt(0),
                            row.getString(1),
                            row.getDouble(2),
                            row.getString(3)
                    )
            );
    return st;
}

// ? Search Course by Name
vector<course> Courses::searchByName(string name) {
    return searchCourse(name, 1);
}

// ? Search Course by Fee
vector<course> Courses::searchByFee(float fee) {
    return searchCourse(fee, 2);
}

// ? Search Course by Name
vector<course> Courses::searchByStartDate(string start_date) {
    return searchCourse(start_date, 3);
}

// ? Get Number of Subjects
int Courses::getSize() const {
    CSVParser parser;
    vector<CSVRow> courses = parser.read(COURSES_FILE);
    return courses.size();
}

// ? Display Menu
void Courses::displayMenu() const {
    for (int i = 0; i < options.size(); i++)
        cout << setw(WIDTH) << i + 1 << ". " << options.at(i) << endl;
}

// ? Select Menu
void Courses::select() {
    displayMenu();
    int id, key;
    float fee;
    string name, startDate;
    course c, cr;
    int n;
    again:
    cout << "Enter Number (Press 0 to go back): ";
    cin >> n;
    if (n == 0)
        Menu m;
    switch (n) {
        case 1:
            c.setCourse();
            break;
        case 2:

            break;
        case 3:
            // Delete
            break;
        case 4:
            cout << "Enter id: ";
            cin >> id;
            searchById(id);
            break;
        case 5:
            cout << "Enter Name: ";
            cin >> name;
            searchByName(name);
            break;
        case 6:
            cout << "Enter Fee: ";
            cin >> fee;
            searchByFee(fee);
            break;
        case 7:
            cout << "Enter Start Date: ";
            cin >> startDate;
            searchByStartDate(startDate);
            break;
        case 8:
            getTotalCourses();
            break;
        default:
            cout << "Invalid Choice! try again..." << endl;
            goto again;
    }
    cout << "Press 0 to return to Main Menu: ";
    cin >> key;
    if (key == 0)
        goto again;
}

// ? Get Course ID
int Courses::getCourseId(const string course_name) const {
    CSVParser parser;
    vector<CSVRow> records = parser.read(COURSES_FILE);
    for (auto row : records)
        if (row.getString(1) == course_name)
            return row.getInt(0);
}

// ? Destructor
Courses::~Courses()
{

}
