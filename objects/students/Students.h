//
// Created by Mr. Uzair on 2/24/2022.
//

#ifndef UNI_PROJECT_STUDENTS_H
#define UNI_PROJECT_STUDENTS_H
#include <iostream>
#include <vector>
#include "student.h"
#include "../../CSVParser/CSVParser.h"
using namespace std;

class Students {
private:
    // * Attributes
    vector<string> options {
            "Add New",
            "Update",
            "Delete",
            "Search",
            "Take Attendance",
            "Display All"
    };
    vector<string> searchOptions {
            "Search By Id",
            "Search By Name",
            "Search By DOB",
            "Search By Phone",
            "Search By Address",
            "Search By Course Name",
    };
public:
    // * Constructor
    Students();

    // * Overloaded Constructor

    // * Operator Overloading

    // * Methods
    void getTotalStudents() const;
    void searchById(int);
    vector<CSVRow> searchStudent(string, int);
    void searchByName(string);
    void searchByDob(string);
    void searchByContact(string);
    void searchByAddress(string);
    void searchByCourse(string);
    int getSize() const;
    void printStudents(vector<CSVRow> records) const;
    void takeAttendance();

    // ? Get Course By Id
    string getCourseName(int id) const;

    // ? Menu
    void displayMenu() const;
    void displaySearchMenu() const;
    void select();

    // * Destructors
    ~Students();

};


#endif //UNI_PROJECT_STUDENTS_H
