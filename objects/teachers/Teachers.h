//
// Created by Mr. Uzair on 2/24/2022.
//

#ifndef UNI_PROJECT_TEACHERS_H
#define UNI_PROJECT_TEACHERS_H

#include <iostream>
#include <vector>
#include "teacher.h"
using namespace std;

class Teachers {
private:
    // * Attributes
public:
    // * Constructor
    Teachers();

    // * Overloaded Constructor

    // * Operator Overloading

    // * Methods
    void getTotalTeachers() const;
    teacher searchById(int id);
    vector<teacher> searchTeacher(string data, int index);
    vector<teacher> searchByName(string name);
    vector<teacher> searchByDob(string dob);
    vector<teacher> searchByContact(string contact);
    vector<teacher> searchByAddress(string address);
    vector<teacher> searchBySubject(string subject);
    int getSize() const;

    // * Destructors
    ~Teachers();
};


#endif //UNI_PROJECT_TEACHERS_H
