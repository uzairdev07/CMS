//
// Created by Mr. Uzair on 2/26/2022.
//

#ifndef UNI_PROJECT_TEACHER_H
#define UNI_PROJECT_TEACHER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class teacher {
private:
    // * Attributes
    int id;
    string name;
    string dob;
    string contact;
    string address;
    int subject_id;

public:
    // * Constructor
    teacher();
    // * Overloaded Constructor
    teacher(int id, string name, string dob, string contact, string address, int subject_id);

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

    int getSubjectId() const;

    void setSubjectId(int subjectId);

    // * Destructor
    ~teacher();
};


#endif //UNI_PROJECT_TEACHER_H
