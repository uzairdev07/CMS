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
    for ( auto col: header )
        cout << setw(COL_WIDTH) << col.getString(0)
             << setw(COL_WIDTH) << col.getString(1)
             << setw(COL_WIDTH) << col.getString(2)
             << setw(COL_WIDTH) << col.getString(3)
             << setw(COL_WIDTH) << col.getString(4)
             << setw(COL_WIDTH) << col.getString(5)
             << endl;
    printLine(90);
    for ( auto teacher: teachers )
        cout << setw(COL_WIDTH) << teacher.getInt(0)
             << setw(COL_WIDTH) << teacher.getString(1)
             << setw(COL_WIDTH) << teacher.getString(2)
             << setw(COL_WIDTH) << teacher.getString(3)
             << setw(COL_WIDTH) << teacher.getString(4)
             << setw(COL_WIDTH) << teacher.getInt(5)
             << endl;
}

// ? Search by Teacher Id
void Teachers::searchById(int id) {
    CSVParser parser;
    vector<CSVRow> teachers = parser.read(TEACHERS_FILE);
    vector<teacher> records;
    for ( CSVRow row: teachers )
        if (id == row.getInt(0))
            records.push_back(
                    teacher(
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
    cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << "DOB" << setw(COL_WIDTH) << "Contact" << setw(COL_WIDTH) << "Address" << setw(COL_WIDTH) << "Subject Id" << endl;
    for (auto t : records)
        cout << setw(COL_WIDTH) << t << endl;
}

// ? Search by Teacher Data
vector<teacher> Teachers::searchTeacher(string data, int index) {
    CSVParser parser;
    vector<CSVRow> teachers = parser.read(TEACHERS_FILE);
    vector<teacher> records;
    for ( CSVRow row: teachers )
        if (data == row.getString(index))
            records.push_back(
                    teacher(
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
    return records;
}

// ? Search By Teacher Name
void Teachers::searchByName(string name) {
    vector<teacher> teachers = searchTeacher(name, 1);
    cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << "DOB" << setw(COL_WIDTH) << "Contact" << setw(COL_WIDTH) << "Address" << setw(COL_WIDTH) << "Subject Id" << endl;
    for (auto t : teachers)
        cout << setw(COL_WIDTH) << t << endl;
}

// ? Search By Teacher DOB
void Teachers::searchByDob(string dob) {
    vector<teacher> teachers = searchTeacher(dob, 2);
    cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << "DOB" << setw(COL_WIDTH) << "Contact" << setw(COL_WIDTH) << "Address" << setw(COL_WIDTH) << "Subject Id" << endl;
    for (auto t : teachers)
        cout << setw(COL_WIDTH) << t << endl;
}

// ? Search By Teacher Contact
void Teachers::searchByContact(string contact) {
    vector<teacher> teachers = searchTeacher(contact, 3);
    cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << "DOB" << setw(COL_WIDTH) << "Contact" << setw(COL_WIDTH) << "Address" << setw(COL_WIDTH) << "Subject Id" << endl;
    for (auto t : teachers)
        cout << t << endl;
}

// ? Search By Teacher Address
void Teachers::searchByAddress(string address) {
    vector<teacher> teachers = searchTeacher(address, 4);
    cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << "DOB" << setw(COL_WIDTH) << "Contact" << setw(COL_WIDTH) << "Address" << setw(COL_WIDTH) << "Subject Id" << endl;
    for (auto t : teachers)
        cout << setw(COL_WIDTH) << t << endl;
}

// ? Search By Teacher Subject
void Teachers::searchBySubject(string subject_name) {
    CSVParser parser;
    vector<CSVRow> records = parser.read(TEACHERS_FILE);
    vector<teacher> teachers;
    Subjects subjects;
    int id = subjects.getSubjectId(subject_name);
    for ( auto row: records )
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
    cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << "DOB" << setw(COL_WIDTH) << "Contact" << setw(COL_WIDTH) << "Address" << setw(COL_WIDTH) << "Subject Id" << endl;
    for (auto t : teachers)
        cout << setw(COL_WIDTH) << t << endl;
}

// ? Get Number of Teachers
int Teachers::getSize() const {
    CSVParser parser;
    vector<CSVRow> teachers = parser.read(TEACHERS_FILE);
    return teachers.size();
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
    string name, subject_name, dob, contact, address;
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
                    cin >> name;
                    searchByName(name);
                    break;
                case 3:
                    clear();
                    getTotalTeachers();
                    cout << "Enter DOB: ";
                    cin >> dob;
                    searchByDob(dob);
                    break;
                case 4:
                    clear();
                    getTotalTeachers();
                    cout << "Enter Contact ";
                    cin >> contact;
                    searchByContact(contact);
                    break;
                case 5:
                    clear();
                    getTotalTeachers();
                    cout << "Enter Address: ";
                    cin >> address;
                    searchByAddress(address);
                    break;
                case 6:
                    clear();
                    getTotalTeachers();
                    cout << "Enter Subject: ";
                    cin >> subject_name;
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