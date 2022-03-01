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
    teacher searchTeacher(int id);
    vector<teacher> searchTeacher(string name);
    int getSize() const;
    void printLine() const;

    // * Destructors
    ~Teachers();
};


#endif //UNI_PROJECT_TEACHERS_H
