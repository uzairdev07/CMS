//
// Created by Mr. Uzair on 2/26/2022.
//

#include "teacher.h"
#include <iomanip>
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
teacher::teacher() {}

// ? Overloaded Constructor
teacher::teacher(int id, string name, string dob, string contact, string address, string subject)
        :id{id}, name{name}, dob{dob}, contact{contact}, address{address}, subject{subject}
{}

// * Operator Overloading
ostream &operator<<(ostream &os, const teacher &teacher) {
    os << setw(15)
       << teacher.getId() << setw(15)
       << teacher.getName() << setw(15)
       << teacher.getDob() << setw(15)
       << teacher.getContact() << setw(15)
       << teacher.getAddress() << setw(15)
       << teacher.getSubject();
    return os;
}

istream &operator>>(istream &is, teacher &teacher) {
    cout << "Enter Roll: ";
    is >> teacher.id;
    cout << "Enter Name: ";
    is >> teacher.name;
    cout << "Enter Date of Birth: ";
    is >> teacher.dob;
    cout << "Enter Contact: ";
    is >> teacher.contact;
    cout << "Enter Address: ";
    is >> teacher.address;
    cout << "Enter Subject: ";
    is >> teacher.subject;
    return is;
}

// * Methods

// ? Insert Teacher into File
void teacher::setTeacher() {
    CSVParser parser;
    cin >> *this;
    parser.write(TEACHERS_FILE, getTeacher());
}

// ? Get Teacher from File
string teacher::getTeacher() const {
    stringstream ss;
    ss << this->getId();
    ss << ",";
    ss << this->getName();
    ss << ",";
    ss << this->getDob();
    ss << ",";
    ss << this->getContact();
    ss << ",";
    ss << this->getAddress();
    ss << ",";
    ss << this->getSubject();
    ss << ",";
    ss << "\n";
    string teacher = ss.str();
    return teacher;
}

// ? Getters and Setters

int teacher::getId() const {
    return id;
}

void teacher::setId(int id) {
    teacher::id = id;
}

const string &teacher::getName() const {
    return name;
}

void teacher::setName(const string &name) {
    teacher::name = name;
}

const string &teacher::getDob() const {
    return dob;
}

void teacher::setDob(const string &dob) {
    teacher::dob = dob;
}

const string &teacher::getContact() const {
    return contact;
}

void teacher::setContact(const string &contact) {
    teacher::contact = contact;
}

const string &teacher::getAddress() const {
    return address;
}

void teacher::setAddress(const string &address) {
    teacher::address = address;
}

const string &teacher::getSubject() const {
    return subject;
}

void teacher::setSubject(const string &subject) {
    teacher::subject = subject;
}

// ? Destructor
teacher::~teacher() {

}
