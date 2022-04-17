//
// Created by Mr. Uzair on 4/9/2022.
//

#ifndef CMS_DEPARTMENTS_H
#define CMS_DEPARTMENTS_H

#include <iostream>
#include <vector>
#include "../../CSVParser/CSVParser.h"
#include "department.h"
using namespace std;

class Departments {
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
    };
    // * Header Cols
    vector<string> col_names = {
            "Id",
            "Name"
    };
public:
    // * Constructor
    Departments();

    // * Overloaded Constructor

    // * Operator Overloading

    // * Methods
    void getTotalDepartments() const;
    void searchById(int id);
    vector<CSVRow> searchDepartment(string, int);
    void searchByName(string);
    int getSize() const;
    void printDepartments(vector<CSVRow> records) const;

    // ? Get Department Id By Name
    int getDepartmentId(const string &name) const;

    // ? Menu
    void displayMenu() const;
    void displaySearchMenu() const;

    void select();

    // * Destructors
    ~Departments();
};


#endif //CMS_DEPARTMENTS_H
