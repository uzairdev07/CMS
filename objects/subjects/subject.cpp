//
// Created by Mr. Uzair on 2/26/2022.
//

#include "subject.h"
#include "../../CSVParser/CSVParser.h"
#include "../../helpers/Const.cpp"
#include "../courses/Courses.h"
#include <iomanip>

/*
 *  Constructors
 *  Operator Overloading
 *  Methods
 *  Getters and Setters
 *  Destructor
*/

// ? Constructors
subject::subject() {}

// ? Overloaded Constructor
subject::subject(int id, string name, int course_id)
        :id(id), name(name), course_id(course_id)
{}

// * Operator Overloading

// ? Extraction Operator
istream &operator>>(istream &is, subject &subject) {
    cout << "Enter id: ";
    is >> subject.id;
    cout << "Enter Name: ";
    is >> subject.name;
    Courses courses;
    courses.getTotalCourses();
    cout << "Enter Course Id: ";
    is >> subject.course_id;
    return is;
}

// ? Insertion Operator
ostream &operator<<(ostream &os, const subject &subject) {
    os << setw(15)
       << subject.getId() << setw(15)
       << subject.getName() << setw(15)
       << subject.getCourseId();
    return os;
}

// * Methods

// ? Insert subjectMenu to File
void subject::setSubject() {
    CSVParser parser;
    cin >> *this;
    parser.write(SUBJECTS_FILE, this->getSubject());
}

// ? Get subjectMenu
string subject::getSubject() const {
    stringstream ss;
    ss << this->getId();
    ss << ",";
    ss << this->getName();
    ss << ",";
    ss << this->getCourseId();
    ss << ",";
    ss << "\n";
    string subject = ss.str();
    return subject;
}

// ? Getters and Setters
int subject::getId() const {
    return id;
}

void subject::setId(int id) {
    subject::id = id;
}

const string &subject::getName() const {
    return name;
}

void subject::setName(const string &name) {
    subject::name = name;
}

int subject::getCourseId() const {
    return course_id;
}

void subject::setCourseId(int courseId) {
    course_id = courseId;
}

// ? Destructor
subject::~subject() {}
