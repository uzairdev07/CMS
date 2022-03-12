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
    course searchById(int id);
    vector<course> searchCourse(string data, int index);
    vector<course> searchCourse(float fee, int index);
    vector<course> searchByName(string name);
    vector<course> searchByFee(float fee);
    vector<course> searchByStartDate(string start_date);
    int getSize() const;

    // * Destructors
    ~Courses();
};


#endif //UNI_PROJECT_COURSES_H
