//
// Created by Mr. Uzair on 2/24/2022.
//

#include "course.h"
#include "../../CSVParser/CSVParser.h"
#include "../../helpers/Const.cpp"
#include "../department/Departments.h"
#include <iomanip>

/*
 *  Constructors
 *  Operator Overloading
 *  Methods
 *  Getters and Setters
 *  Destructor
*/

// ? Constructors
course::course() {}

// ? Overloaded Constructor
course::course(int id, string name, float fee, string startDate, int dep_id)
        :id(id), name(name), fee(fee), startDate(startDate), dep_id{dep_id}
{}

// * Operator Overloading

// ? Extraction Operator
istream &operator>>(istream &is, course &course) {
    cout << "Enter id: ";
    is >> course.id;
    cout << "Enter Name: ";
    is >> course.name;
    cout << "Enter Fee: ";
    is >> course.fee;
    cout << "Enter Start Date: ";
    is >> course.startDate;
    Departments departments;
    departments.getTotalDepartments();
    cout << "Enter Department Id: ";
    is >> course.dep_id;
    return is;
}

// ? Insertion Operator
ostream &operator<<(ostream &os, const course &course) {
    os << setw(COL_WIDTH)
       << course.getId() << setw(COL_WIDTH)
       << course.getName() << setw(COL_WIDTH)
       << course.getFee() << setw(COL_WIDTH)
       << course.getStartDate() << setw(COL_WIDTH)
       << course.getDepartmentId();
    return os;
}

// * Methods

// ? Insert Course to File
void course::setCourse() {
    CSVParser parser;
    cin >> *this;
    parser.write(COURSES_FILE, this->getCourse());
}

// ? Get Course
string course::getCourse() const {
    stringstream ss;
    ss << this->getId();
    ss << ",";
    ss << this->getName();
    ss << ",";
    ss << this->getFee();
    ss << ",";
    ss << this->getStartDate();
    ss << ",";
    ss << this->getDepartmentId();
    ss << ",";
    ss << "\n";
    string course = ss.str();
    return course;
}

// ? Getters and Setters

int course::getId() const {
    return id;
}

void course::setId(int id) {
    course::id = id;
}

const string &course::getName() const {
    return name;
}

void course::setName(const string &name) {
    course::name = name;
}

float course::getFee() const {
    return fee;
}

void course::setFee(float fee) {
    course::fee = fee;
}

const string &course::getStartDate() const {
    return startDate;
}

void course::setStartDate(const string &startDate) {
    course::startDate = startDate;
}

const int &course::getDepartmentId() const {
    return dep_id;
}

void course::setDepartmentId(const int dep_id) {
    this->dep_id = dep_id;
}

// ? Destructor
course::~course() {}
