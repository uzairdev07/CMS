//
// Created by Mr. Uzair on 2/24/2022.
//

#ifndef UNI_PROJECT_TEACHERS_H
#define UNI_PROJECT_TEACHERS_H

#include <iostream>
#include <vector>
#include "teacher.h"
using namespace std;

class Teachers {
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
            "Search By DOB",
            "Search By Contact",
            "Search By Address",
            "Search By Role",
            "Search By Subject Name"
    };
public:
    // * Constructor
    Teachers();

    // * Overloaded Constructor

    // * Operator Overloading

    // * Methods
    void getTotalTeachers() const;
    void searchById(int id);
    vector<teacher> searchTeacher(string data, int index);
    void searchByName(string name);
    void searchByDob(string dob);
    void searchByContact(string contact);
    void searchByAddress(string address);
    void searchByRole(string role);
    void searchBySubject(string subject_name);
    int getSize() const;

    // ? Get Subject By Id
    string getSubjectName(int id) const;

    // ? Menu
    void displayMenu() const;
    void displaySearchMenu() const;
    void select();

    // * Destructors
    ~Teachers();
};


#endif //UNI_PROJECT_TEACHERS_H
