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
public:
    // * Constructor
    Subjects();

    // * Overloaded Constructor

    // * Operator Overloading

    // * Methods
    void getTotalSubjects() const;
    subject searchSubject(int id);
    vector<subject> searchSubject(string name);
    int getSize() const;

    // * Destructors
    ~Subjects();
};


#endif //UNI_PROJECT_SUBJECTS_H
