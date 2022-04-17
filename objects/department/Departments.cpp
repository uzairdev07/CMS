//
// Created by Mr. Uzair on 4/9/2022.
//

#include "Departments.h"
#include "../../helpers/style.cpp"
#include "../../helpers/Const.cpp"
#include "../../utilities/menu.h"
#include <conio.h>

/*
 *  Constructors
 *  Operator Overloading
 *  Methods
 *  Destructor
*/

// ? Constructor
Departments::Departments() {

}

// ? Overloading Constructor

// ? Operator Overloading

// * Methods

// ? Print all Subjects
void Departments::getTotalDepartments() const {
    CSVParser parser;
    vector<CSVRow> header = parser.getHeader(DEPARTMENTS_FILE);
    vector<CSVRow> departments = parser.read(DEPARTMENTS_FILE);
    for ( auto col: header )
        cout << setw(COL_WIDTH) << col.getString(0)
             << setw(COL_WIDTH) << col.getString(1)
             << endl;
    printLine(30);
    for ( auto department: departments )
        cout << setw(COL_WIDTH) << department.getInt(0)
             << setw(COL_WIDTH) << department.getString(1)
             << endl;
}

// ? Search Department by Id
void Departments::searchById(int id) {
    CSVParser parser;
    vector<CSVRow> rows = parser.search(DEPARTMENTS_FILE, id, 0);
    printDepartments(rows);
}

// ? Search department by Data
vector<CSVRow> Departments::searchDepartment(string data, int index) {
    CSVParser parser;
    vector<CSVRow> departments = parser.search(DEPARTMENTS_FILE, data, index);
    return departments;
}

// ? Search Department by Name
void Departments::searchByName(string name) {
    vector<CSVRow> records = searchDepartment(name, 1);
    printDepartments(records);
}

// ? Get Number of Departments
int Departments::getSize() const {
    CSVParser parser;
    vector<CSVRow> Departments = parser.read(DEPARTMENTS_FILE);
    return Departments.size();
}

void Departments::printDepartments(vector<CSVRow> records) const {
    if (records.size() != 0) {
        cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Name" << setw(COL_WIDTH) << endl;
        for ( auto student: records)
            cout << setw(COL_WIDTH) << student.getInt(0)
                 << setw(COL_WIDTH) << student.getString(1)
                 << endl;
    } else
        cerr << "No Records founded yet!..." << endl;
}

// ? Get Department ID by Name
int Departments::getDepartmentId(const string &name) const {
    CSVParser parser;
    vector<CSVRow> records = parser.search(DEPARTMENTS_FILE, name, 1);
    for (auto row : records)
        return row.getInt(0);
}

// ? Display Menu
void Departments::displayMenu() const {
    for ( int i = 0; i < options.size(); i++ )
        cout << setw(WIDTH) << i + 1 << ". " << options.at(i) << endl;
}

// ? Display Search Menu
void Departments::displaySearchMenu() const {
    for ( int i = 0; i < searchOptions.size(); i++ )
        cout << setw(WIDTH) << i + 1 << ". " << searchOptions.at(i) << endl;
}

// ? Select Menu
void Departments::select() {
    display:
    clear();
    displayMenu();
    int id, key;
    string name;
    department d;
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
            d.setDepartment();
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
                    getTotalDepartments();
                    cout << "Enter id: ";
                    cin >> id;
                    searchById(id);
                    break;
                case 2:
                    clear();
                    getTotalDepartments();
                    cout << "Enter Name: ";
                    getline(cin, name);
                    searchByName(name);
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
            getTotalDepartments();
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
Departments::~Departments() {

}
