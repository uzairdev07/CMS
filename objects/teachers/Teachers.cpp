//
// Created by Mr. Uzair on 2/24/2022.
//

#include "Teachers.h"
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
    if (teachers.size() != 0) {
        for ( auto col: header )
            cout << setw(COL_WIDTH) << col.getString(0)
                 << setw(COL_WIDTH) << col.getString(1)
                 << setw(COL_WIDTH) << col.getString(2)
                 << setw(COL_WIDTH) << col.getString(3)
                 << setw(COL_WIDTH) << col.getString(4)
                 << setw(COL_WIDTH) << col.getString(5)
                 << setw(COL_WIDTH) << "Subject_Name"
                 << endl;
        printLine(105);
        for ( auto teacher: teachers )
            cout << setw(COL_WIDTH) << teacher.getInt(0)
                 << setw(COL_WIDTH) << teacher.getString(1)
                 << setw(COL_WIDTH) << teacher.getString(2)
                 << setw(COL_WIDTH) << teacher.getString(3)
                 << setw(COL_WIDTH) << teacher.getString(4)
                 << setw(COL_WIDTH) << teacher.getString(5)
                 << setw(COL_WIDTH) << getSubjectName(teacher.getInt(6))
                 << endl;
    } else
        cerr << "No Record Founded Ye! ...";
}

// ? Search by Teacher Id
void Teachers::searchById(int id) {
    CSVParser parser;
    vector<CSVRow> teachers = parser.search(TEACHERS_FILE, id, 0);
    printTeachers(teachers);
}

// ? Search by Teacher Data
vector<CSVRow> Teachers::searchTeacher(string data, int index) {
    CSVParser parser;
    vector<CSVRow> teachers = parser.search(TEACHERS_FILE, data, index);
    return teachers;
}

// ? Search By Teacher Name
void Teachers::searchByName(string name) {
    vector<CSVRow> teachers = searchTeacher(name, 1);
    printTeachers(teachers);
}

// ? Search By Teacher DOB
void Teachers::searchByDob(string dob) {
    vector<CSVRow> teachers = searchTeacher(dob, 2);
    printTeachers(teachers);
}

// ? Search By Teacher Contact
void Teachers::searchByContact(string contact) {
    vector<CSVRow> teachers = searchTeacher(contact, 3);
    printTeachers(teachers);
}

// ? Search By Teacher Address
void Teachers::searchByAddress(string address) {
    vector<CSVRow> teachers = searchTeacher(address, 4);
    printTeachers(teachers);
}

// ? Search By Teacher Role
void Teachers::searchByRole(string role) {
    vector<CSVRow> teachers = searchTeacher(role, 5);
    printTeachers(teachers);
}

// ? Search By Teacher Subject
void Teachers::searchBySubject(string subject_name) {
    CSVParser parser;
    Subjects subjects;
    int id = subjects.getSubjectId(subject_name);
    vector<CSVRow> records = parser.search(TEACHERS_FILE, id, 6);
    printTeachers(records);
}

// ? Get Number of Teachers
int Teachers::getSize() const {
    CSVParser parser;
    vector<CSVRow> teachers = parser.read(TEACHERS_FILE);
    return teachers.size();
}

// ? Get Course Name By Id
string Teachers::getSubjectName(int id) const {
    CSVParser parser;
    string subject_name;
    vector<CSVRow> records = parser.search(SUBJECTS_FILE, id, 0);
    for (auto row : records)
        return row.getString(1);
}

void Teachers::printTeachers(vector<CSVRow> records) const {
    if (records.size() != 0) {
        cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << "DOB" << setw(COL_WIDTH)
             << "Contact" << setw(COL_WIDTH) << "Address" << setw(COL_WIDTH) << "Role" << setw(COL_WIDTH) << "Subject Name" << endl;
        for ( auto record: records)
            cout << setw(COL_WIDTH) << record.getInt(0)
                 << setw(COL_WIDTH) << record.getString(1)
                 << setw(COL_WIDTH) << record.getString(2)
                 << setw(COL_WIDTH) << record.getString(3)
                 << setw(COL_WIDTH) << record.getString(4)
                 << setw(COL_WIDTH) << record.getString(5)
                 << setw(COL_WIDTH) << getSubjectName(record.getInt(6))
                 << endl;
    } else
        cerr << "No Records founded yet!..." << endl;
}

// ? Display Menu
void Teachers::displayMenu() const {
    for ( int i = 0; i < options.size(); i++ )
        cout << setw(WIDTH) << i + 1 << ". " << options.at(i) << endl;
}

// ? Display Search Menu
void Teachers::displaySearchMenu() const {
    for ( int i = 0; i < searchOptions.size(); i++ )
        cout << setw(WIDTH) << i + 1 << ". " << searchOptions.at(i) << endl;
}

// ? Select Menu
void Teachers::select() {
    display:
    clear();
    displayMenu();
    int id, key;
    string name, subject_name, dob, contact, address, role;
    teacher t;
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
                    getTotalTeachers();
                    cout << "Enter id: ";
                    cin >> id;
                    searchById(id);
                    break;
                case 2:
                    clear();
                    getTotalTeachers();
                    cout << "Enter Name: ";
                    getline(cin, name);
                    searchByName(name);
                    break;
                case 3:
                    clear();
                    getTotalTeachers();
                    cout << "Enter DOB: ";
                    getline(cin, dob);
                    searchByDob(dob);
                    break;
                case 4:
                    clear();
                    getTotalTeachers();
                    cout << "Enter Contact ";
                    getline(cin, contact);
                    searchByContact(contact);
                    break;
                case 5:
                    clear();
                    getTotalTeachers();
                    cout << "Enter Address: ";
                    getline(cin, address);
                    searchByAddress(address);
                    break;
                case 6:
                    clear();
                    getTotalTeachers();
                    cout << "Enter Role: ";
                    getline(cin, role);
                    searchByRole(role);
                    break;
                case 7:
                    clear();
                    getTotalTeachers();
                    cout << "Enter Subject: ";
                    getline(cin, subject_name);
                    searchBySubject(subject_name);
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
