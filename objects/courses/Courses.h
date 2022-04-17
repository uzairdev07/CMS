//
// Created by Mr. Uzair on 2/26/2022.
//

#ifndef UNI_PROJECT_COURSES_H
#define UNI_PROJECT_COURSES_H

#include <iostream>
#include <vector>
#include "../../CSVParser/CSVParser.h"
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
            "Search By Department Name"
    };

    // * Header Cols
    vector<string> col_names {
            "Id",
            "Name",
            "Fee",
            "Start Date",
            "Department Name"
    };
public:
    // * Constructor
    Courses();

    // * Overloaded Constructor

    // * Operator Overloading

    // * Methods
    void getTotalCourses() const;
    void searchById(int id);
    vector<CSVRow> searchCourse(string, int);
    vector<CSVRow> searchCourse(float, int);
    void searchByName(string);
    void searchByFee(float);
    void searchByStartDate(string);
    void searchByDepartmentName(const string) const;
    int getSize() const;
    void printCourses(vector<CSVRow> records) const;

    // ? Get Course ID by Name
    int getCourseId(const string course_name) const;

    // ? Get Department Name by ID
    string getDepartmentName(int dep_id) const;

    // ? Menu
    void displayMenu() const;
    void displaySearchMenu() const;

    void select();

    // * Destructors
    ~Courses();
};


#endif //UNI_PROJECT_COURSES_H
