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
    student searchById(int id);
    vector<student> searchStudent(string data, int index);
    vector<student> searchByName(string name);
    vector<student> searchByDob(string dob);
    vector<student> searchByContact(string contact);
    vector<student> searchByAddress(string address);
    vector<student> searchByCourse(string course);
    int getSize() const;
    // * Destructors
    ~Students();

};


#endif //UNI_PROJECT_STUDENTS_H
