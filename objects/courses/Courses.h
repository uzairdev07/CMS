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
public:
    // * Constructor
    Courses();

    // * Overloaded Constructor

    // * Operator Overloading

    // * Methods
    void getTotalCourses() const;
    course searchCourse(int id);
    vector<course> searchCourse(string name);
    int getSize() const;

    // * Destructors
    ~Courses();
};


#endif //UNI_PROJECT_COURSES_H
