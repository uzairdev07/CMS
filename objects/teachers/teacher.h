//
// Created by Mr. Uzair on 2/26/2022.
//

#ifndef UNI_PROJECT_TEACHER_H
#define UNI_PROJECT_TEACHER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "../../CSVParser/CSVParser.h"
#include "../../helpers/const.cpp"

class teacher {
private:
    // * Attributes
    int id;
    string name;
    string dob;
    string contact;
    string address;
    string subject;

public:
    // * Constructor
    teacher();
    // * Overloaded Constructor
    teacher(int id, string name, string dob, string contact, string address, string subject);

    // * Operator overloading

    // ? Extraction Operator
    friend istream &operator>>(istream &is, teacher &teacher);
    // ? Insertion Operator
    friend ostream &operator<<(ostream &os, const teacher &teacher);

    // * Methods
    void setTeacher();
    string getTeacher() const;

    // ? Getters and Setters

    int getId() const;

    void setId(int id);

    const string &getName() const;

    void setName(const string &name);

    const string &getDob() const;

    void setDob(const string &dob);

    const string &getContact() const;

    void setContact(const string &contact);

    const string &getAddress() const;

    void setAddress(const string &address);

    const string &getSubject() const;

    void setSubject(const string &subject);

    // * Destructor
    ~teacher();
};


#endif //UNI_PROJECT_TEACHER_H
