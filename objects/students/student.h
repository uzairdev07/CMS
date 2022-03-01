//
// Created by Mr. Uzair on 2/26/2022.
//

#ifndef UNI_PROJECT_STUDENT_H
#define UNI_PROJECT_STUDENT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "../../CSVParser/CSVParser.h"
#include "../../helpers/const.cpp"
using namespace std;

class student {
private:
    // * Attributes
    int roll;
    string name;
    string dob;
    string course;
    string contact;

public:
    // * Constructors
    student();
    // * Overloading Constructor
    student(int roll, string name, string dob, string contact, string course);

    // * Operator Overloading

    // ? Assignment Operator
    // ? Equality Operator
    // ? Insertion Operator
    friend istream &operator>>(istream &is, student &student);
    // ? Extraction Operator
    friend ostream &operator<<(ostream &os, const student &student);

    // * Methods

    void setStudent();
    string getStudent() const;

    // ? Getters and Setters
    int getRoll() const;

    void setRoll(int roll);

    const string &getName() const;

    void setName(const string &name);

    const string &getDob() const;

    void setDob(const string &dob);

    const string &getCourse() const;

    void setCourse(const string &course);

    const string &getContact() const;

    void setContact(const string &contact);

    // * Destructors
    ~student();

};


#endif //UNI_PROJECT_STUDENT_H
