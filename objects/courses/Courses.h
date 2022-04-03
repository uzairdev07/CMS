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
    vector<string> options{
            "Add New",
            "Update",
            "Delete",
            "Search",
            "Display All"
    };

    vector<string> searchOptions{
            "Search By Id",
            "Search By Name",
            "Search By Fee",
            "Search By Date",
    };
public:
    // * Constructor
    Courses();

    // * Overloaded Constructor

    // * Operator Overloading

    // * Methods
    void getTotalCourses() const;

    void searchById(int id);

    vector<course> searchCourse(string, int);

    vector<course> searchCourse(float, int);

    void searchByName(string);

    void searchByFee(float);

    void searchByStartDate(string);

    int getSize() const;

    // ? Get Course ID
    int getCourseId(const string course_name) const;

    // ? Menu
    void displayMenu() const;
    void displaySearchMenu() const;

    void select();

    // * Destructors
    ~Courses();
};


#endif //UNI_PROJECT_COURSES_H
