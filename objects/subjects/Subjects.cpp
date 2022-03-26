//
// Created by Mr. Uzair on 2/24/2022.
//

#include "Subjects.h"
#include "../../utilities/menu.h"
#include "../../CSVParser/CSVParser.h"
#include "../../helpers/Const.cpp"
#include "../../helpers/style.cpp"
#include "../courses/Courses.h"
#include <conio.h>

/*
 *  Constructors
 *  Operator Overloading
 *  Methods
 *  Destructor
*/

// ? Constructor
Subjects::Subjects() {

}

// ? Overloading Constructor

// ? Operator Overloading

// * Methods

// ? Print all Subjects
void Subjects::getTotalSubjects() const {
    CSVParser parser;
    vector<CSVRow> header = parser.getHeader(SUBJECTS_FILE);
    vector<CSVRow> subjects = parser.read(SUBJECTS_FILE);
    for (auto col : header)
        cout << setw(COL_WIDTH) << col.getString(0)
             << setw(COL_WIDTH) << col.getString(1)
             << setw(COL_WIDTH) << col.getString(2)
             << endl;
    printLine(30);
    for (auto subject : subjects)
        cout << setw(COL_WIDTH) << subject.getInt(0)
             << setw(COL_WIDTH) << subject.getString(1)
             << setw(COL_WIDTH) << subject.getInt(2)
             << endl;
}

// ? Search Course by Id
subject Subjects::searchById(int id) {
    CSVParser parser;
    vector<CSVRow> subjects = parser.read(SUBJECTS_FILE);
    for (CSVRow row : subjects)
        if (id == row.getInt(0))
            return subject (
                    row.getInt(0),
                    row.getString(1),
                    row.getInt(2)
            );
}

// ? Search Course by Name
vector<subject> Subjects::searchByName(string name) {
    CSVParser parser;
    vector<CSVRow> subjects = parser.read(SUBJECTS_FILE);
    vector<subject> st;
    for (CSVRow row : subjects)
        if (name == row.getString(1))
            st.push_back (
                    subject (
                            row.getInt(0),
                            row.getString(1),
                            row.getInt(2)
                    )
            );
    if (st.size() == 0) {
        cerr << "No Record Founded Ye! ...";
        return st;
    } else
        return st;
}

// ? Search By Subject Course
vector<subject> Subjects::searchByCourse(string course_name) {
    CSVParser parser;
    vector<CSVRow> records = parser.read(SUBJECTS_FILE);
    vector<subject> subjects;
    Courses courses;
    int id = courses.getCourseId(course_name);
    for (auto row : records)
        if (row.getInt(2) == id)
            subjects.push_back(
                    subject(
                            row.getInt(0),
                            row.getString(1),
                            row.getInt(2)
                    )
            );
    return subjects;
}

// ? Get Number of Subjects
int Subjects::getSize() const {
    CSVParser parser;
    vector<CSVRow> subjects = parser.read(SUBJECTS_FILE);
    return subjects.size();
}

// ? Display Menu
void Subjects::displayMenu() const {
    for (int i = 0; i < options.size(); i++)
        cout << setw(WIDTH) << i + 1 << ". " << options.at(i) << endl;
}

// ? Select Menu
void Subjects::select() {
    display:
    clear();
    clear();
    displayMenu();
    int id, key, course_id;
    string name, courseName;
    subject s, sb;
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
            s.setSubject();
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
            cout << "Enter Course Name: ";
            cin >> name;
            searchByCourse(name);
            break;
        case 7:
            clear();
            getTotalSubjects();
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

// ? Get Subject ID
int Subjects::getSubjectId(const string subject_name) const {
    CSVParser parser;
    vector<CSVRow> records = parser.read(SUBJECTS_FILE);
    for (auto row : records)
        if (row.getString(1) == subject_name)
            return row.getInt(0);
}

// ? Destructor
Subjects::~Subjects() {}