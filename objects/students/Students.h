//
// Created by Mr. Uzair on 2/24/2022.
//

#ifndef UNI_PROJECT_STUDENTS_H
#define UNI_PROJECT_STUDENTS_H
#include <iostream>
#include <vector>
#include <iomanip>
#include "../../CSVParser/CSVParser.h"
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
    student searchStudent(int id);
    vector<student> searchStudent(string name);
    int getSize() const;
    void printLine() const;

    // * Destructors
    ~Students();

};


#endif //UNI_PROJECT_STUDENTS_H