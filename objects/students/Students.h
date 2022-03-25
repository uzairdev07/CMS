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
    vector<string> options {
            "Add New",
            "Update",
            "Delete",
            "Search By Id",
            "Search By Name",
            "Search By DOB",
            "Search By Phone",
            "Search By Address",
            "Search By Course Name",
            "Display All"
    };
public:
    // * Constructor
    Students();

    // * Overloaded Constructor

    // * Operator Overloading

    // * Methods
    void getTotalStudents() const;
    student searchById(int);
    vector<student> searchStudent(string, int);
    vector<student> searchByName(string);
    vector<student> searchByDob(string);
    vector<student> searchByContact(string);
    vector<student> searchByAddress(string);
    vector<student> searchByCourse(string);
    int getSize() const;

    // ? Menu
    void displayMenu() const;
    void select();

    // * Destructors
    ~Students();

};


#endif //UNI_PROJECT_STUDENTS_H
