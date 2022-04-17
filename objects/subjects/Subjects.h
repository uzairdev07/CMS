//
// Created by Mr. Uzair on 2/24/2022.
//

#ifndef UNI_PROJECT_SUBJECTS_H
#define UNI_PROJECT_SUBJECTS_H

#include <iostream>
#include <vector>
#include "../../CSVParser/CSVParser.h"
#include "subject.h"
using namespace std;


class Subjects {
private:
    // * Attributes
    vector<string> options {
            "Add New",
            "Update",
            "Delete",
            "Search",
            "Display All"
    };
    vector<string> searchOptions {
            "Search By Id",
            "Search By Name",
            "Search By Course Name"
    };
    // * Header Cols
    vector<string> col_names = {
            "Id",
            "Name",
            "Course Name"
    };
public:
    // * Constructor
    Subjects();

    // * Overloaded Constructor

    // * Operator Overloading

    // * Methods
    void getTotalSubjects() const;
    void searchById(int id);
    void searchByName(string name);
    void searchByCourse(string);
    int getSize() const;
    void printSubjects(vector<CSVRow> records) const;

    // ? Get Course By Id
    string getCourseName(int id) const;

    // ? Get Subject ID
    int getSubjectId(const string subject_name) const;

    // ? Menu
    void displayMenu() const;
    void displaySearchMenu() const;
    void select();

    // * Destructors
    ~Subjects();
};


#endif //UNI_PROJECT_SUBJECTS_H
