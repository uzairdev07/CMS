//
// Created by Mr. Uzair on 2/24/2022.
//

#ifndef UNI_PROJECT_STUDENTS_H
#define UNI_PROJECT_STUDENTS_H
#include <iostream>
#include <vector>
#include "student.h"
using namespace std;

class Students {
private:
    // * Attributes
public:
    // * Constructor
    Students();

    // * Overloaded Constructor

    // * Operator Overloading

    // * Methods
    void getTotalStudents() const;
    student searchStudentById(int id);
    vector<student> searchStudent(string data, int index);
    vector<student> searchStudentByName(string name);
    vector<student> searchStudentByDob(string dob);
    vector<student> searchStudentByAddress(string address);
    vector<student> searchStudentByContact(string contact);
    int getSize() const;
    // * Destructors
    ~Students();

};


#endif //UNI_PROJECT_STUDENTS_H
