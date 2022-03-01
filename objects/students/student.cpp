//
// Created by Mr. Uzair on 2/26/2022.
//

#include "student.h"

/*
 *  Constructors
 *  Operator Overloading
 *  Methods
 *  Getters and Setters
 *  Destructor
*/

// ? Constructors

student::student() {

}

// ? Overloaded Constructor
student::student(int roll, string name, string dob, string contact, string address, string course)
        :roll{roll}, name{name}, dob{dob}, contact{contact}, address{address}, course{course}
{}

// * Operator Overloading

// ? Extraction Operator
istream &operator>>(istream &is, student &student) {
    cout << "Enter Roll: ";
    is >> student.roll;
    cout << "Enter Name: ";
    is >> student.name;
    cout << "Enter Date of Birth: ";
    is >> student.dob;
    cout << "Enter Contact: ";
    is >> student.contact;
    cout << "Enter Address: ";
    is >> student.address;
    cout << "Enter Course: ";
    is >> student.course;
    return is;
}

// ? Insertion Operator
ostream &operator<<(ostream &os, const student &student) {
    os << student.getRoll() << ","
       << student.getName() << ","
       << student.getDob() << ","
       << student.getContact() << ","
       << student.getAddress() << ","
       << student.getCourse();
    return os;
}

// * Methods

// ? Insert Student Into File
void student::setStudent() {
    CSVParser parser;
    cin >> *this;
    parser.write(STUDENTS_FILE, this->getStudent());
}

// ? Get Student
string student::getStudent() const {
    stringstream ss;
    ss << this->getRoll();
    ss << ",";
    ss << this->getName();
    ss << ",";
    ss << this->getDob();
    ss << ",";
    ss << this->getContact();
    ss << ",";
    ss << this->getAddress();
    ss << ",";
    ss << this->getCourse();
    ss << ",";
    ss << "\n";
    string student = ss.str();
    return student;
}

// ? Getters and Setters

int student::getRoll() const {
    return roll;
}

void student::setRoll(int roll) {
    student::roll = roll;
}

const string &student::getName() const {
    return name;
}

void student::setName(const string &name) {
    student::name = name;
}

const string &student::getDob() const {
    return dob;
}

void student::setDob(const string &dob) {
    student::dob = dob;
}

const string &student::getCourse() const {
    return course;
}

void student::setCourse(const string &course) {
    student::course = course;
}

const string &student::getContact() const {
    return contact;
}

void student::setContact(const string &contact) {
    student::contact = contact;
}

const string &student::getAddress() const {
    return address;
}

void student::setAddress(const string &address) {
    student::address = address;
}

// ? Destructor
student::~student() {

}
