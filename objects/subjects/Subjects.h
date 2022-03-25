//
// Created by Mr. Uzair on 2/24/2022.
//

#ifndef UNI_PROJECT_SUBJECTS_H
#define UNI_PROJECT_SUBJECTS_H

#include <iostream>
#include <vector>
#include "subject.h"
using namespace std;


class Subjects {
private:
    // * Attributes
    vector<string> options {
            "Add New",
            "Update",
            "Delete",
            "Search By Id",
            "Search By Name",
            "Search By Course Name",
            "Display All"
    };
public:
    // * Constructor
    Subjects();

    // * Overloaded Constructor

    // * Operator Overloading

    // * Methods
    void getTotalSubjects() const;
    subject searchById(int id);
    vector<subject> searchByName(string name);
    vector<subject> searchByCourse(string);
    int getSize() const;

    // ? Get Subject ID
    int getSubjectId(const string subject_name) const;

    // ? Menu
    void displayMenu() const;
    void select();

    // * Destructors
    ~Subjects();
};


#endif //UNI_PROJECT_SUBJECTS_H
