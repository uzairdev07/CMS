//
// Created by Mr. Uzair on 2/24/2022.
//

#include "course.h"
#include "../../CSVParser/CSVParser.h"
#include "../../helpers/Const.cpp"

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
course::course(int id, string name, float fee, string startDate)
        :id(id), name(name), fee(fee), startDate(startDate)
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
    return is;
}

// ? Insertion Operator
ostream &operator<<(ostream &os, const course &course) {
    os << course.getId() << ","
       << course.getName() << ","
       << course.getFee() << ","
       << course.getStartDate();
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

// ? Destructor
course::~course() {}