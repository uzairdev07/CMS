//
// Created by Mr. Uzair on 4/9/2022.
//

#include "department.h"
#include "../../CSVParser/CSVParser.h"
#include "../../helpers/Const.cpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

/*
 *  Constructors
 *  Operator Overloading
 *  Methods
 *  Getters and Setters
 *  Destructor
*/

// ? Constructors
department::department() {}

// ? Overloaded Constructor
department::department(int id, string name)
        :id(id), name(name)
{}

// * Operator Overloading

// ? Extraction Operator
istream &operator>>(istream &is, department &department) {
    cout << "Enter id: ";
    is >> department.id;
    cout << "Enter Name: ";
    getline(is, department.name);
    return is;
}

// ? Insertion Operator
ostream &operator<<(ostream &os, const department &department) {
    os << setw(COL_WIDTH)
       << department.getId() << setw(COL_WIDTH)
       << department.getName() << setw(COL_WIDTH);
    return os;
}

// * Methods

// ? Insert department to File
void department::setDepartment() {
    CSVParser parser;
    cin >> *this;
    parser.write(DEPARTMENTS_FILE, this->getDepartment());
}

// ? Get department
string department::getDepartment() const {
    stringstream ss;
    ss << this->getId();
    ss << ",";
    ss << this->getName();
    ss << ",";
    ss << "\n";
    string department = ss.str();
    return department;
}

const int &department::getId() const {
    return id;
}

void department::setId(const int &id) {
    department::id = id;
}

const string &department::getName() const {
    return name;
}

void department::setName(const string &name) {
    department::name = name;
}

department::~department() {

}
