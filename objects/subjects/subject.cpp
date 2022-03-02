//
// Created by Mr. Uzair on 2/26/2022.
//

#include "subject.h"
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
subject::subject() {}

// ? Overloaded Constructor
subject::subject(int id, string name)
        :id(id), name(name)
{}

// * Operator Overloading

// ? Extraction Operator
istream &operator>>(istream &is, subject &subject) {
    cout << "Enter id: ";
    is >> subject.id;
    cout << "Enter Name: ";
    is >> subject.name;
    return is;
}

// ? Insertion Operator
ostream &operator<<(ostream &os, const subject &subject) {
    os << subject.getId() << ","
       << subject.getName();
    return os;
}

// * Methods

// ? Insert subject to File
void subject::setSubject() {
    CSVParser parser;
    cin >> *this;
    parser.write(SUBJECTS_FILE, this->getSubject());
}

// ? Get subject
string subject::getSubject() const {
    stringstream ss;
    ss << this->getId();
    ss << ",";
    ss << this->getName();
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

// ? Destructor
subject::~subject() {}