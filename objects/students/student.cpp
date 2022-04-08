//
// Created by Mr. Uzair on 2/26/2022.
//

#include "student.h"
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

student::student() {

}

// ? Overloaded Constructor
student::student(int roll, string name, string dob, string contact, string address, int course_id)
        :roll{roll}, name{name}, dob{dob}, contact{contact}, address{address}, course_id{course_id
}
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
    Courses courses;
    courses.getTotalCourses();
    cout << "Enter Course id: ";
    is >> student.course_id;
    return is;
}

// ? Insertion Operator
ostream &operator<<(ostream &os, const student &student) {
    os << setw(COL_WIDTH)
       << student.getRoll() << setw(COL_WIDTH)
       << student.getName() << setw(COL_WIDTH)
       << student.getDob() << setw(COL_WIDTH)
       << student.getContact() << setw(COL_WIDTH)
       << student.getAddress() << setw(COL_WIDTH)
       << student.getCourseId();
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
    ss << this->getCourseId();
    ss << ",";
    ss << "\n";
    string student = ss.str();
    return student;
}

// ? Update Student
void student::updateStudent() {
    CSVParser parser;
    int n = 0, course_id{};
    string name{}, dob{}, contact{}, address{};
    again:
    cout << "Enter number: ";
    cin >> n;
    switch (n) {
        case 1:
            cout << "Enter New Name: ";
            cin >> name;
            this->setName(name);
            break;
        case 2:
            cout << "Enter DOB: ";
            cin >> dob;
            this->setDob(dob);
            break;
        case 3:
            cout << "Enter Address: ";
            cin >> address;
            this->setAddress(address);
            break;
        case 4:
            cout << "Enter Contact: ";
            cin >> contact;
            this->setContact(contact);
            break;
        case 5:
            cout << "Enter Course: ";
            cin >> course_id;
            this->setCourseId(course_id);
            break;
        default:
            cerr << "Invalid Input! ";
            goto again;
            break;
    }

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

const int &student::getCourseId() const {
    return course_id;
}

void student::setCourseId(const int &course_id) {
    this->course_id = course_id;
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
