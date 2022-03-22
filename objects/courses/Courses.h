//
// Created by Mr. Uzair on 2/26/2022.
//

#ifndef UNI_PROJECT_COURSES_H
#define UNI_PROJECT_COURSES_H

#include <iostream>
#include <vector>
#include "course.h"
using namespace std;

class Courses {
private:
    // * Attributes
    vector<string> options {
            "Add New",
            "Update",
            "Delete",
            "Search By Id",
            "Search By Name",
            "Search By Fee",
            "Search By Start Date",
            "Display All"
    };
public:
    // * Constructor
    Courses();

    // * Overloaded Constructor

    // * Operator Overloading

    // * Methods
    void getTotalCourses() const;
    course searchById(int id);
    vector<course> searchCourse(string, int);
    vector<course> searchCourse(float, int);
    vector<course> searchByName(string);
    vector<course> searchByFee(float);
    vector<course> searchByStartDate(string);
    int getSize() const;

    // ? Menu
    void displayMenu() const;
    void select();

    // * Destructors
    ~Courses();
};


#endif //UNI_PROJECT_COURSES_H
