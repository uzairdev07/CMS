//
// Created by Mr. Uzair on 4/9/2022.
//

#ifndef CMS_DEPARTMENT_H
#define CMS_DEPARTMENT_H

#include <iostream>
using namespace std;

class department {

private:
    // * Attributes
    int id;
    string name;
public:
    // * Constructor
    department();
    // * Overloaded Constructor
    department(int id, string name);

    // * Operator Overloading

    // ? Extraction Operator
    friend istream &operator>>(istream &is, department &department);
    // ? Insertion Operator
    friend ostream &operator<<(ostream &os, const department &department);

    // * Methods

    void setDepartment();
    string getDepartment() const;

    // ? Getters and Setters

    const int &getId() const;

    void setId(const int &id);

    const string &getName() const;

    void setName(const string &name);

    // * Destructor
    ~department();

};


#endif //CMS_DEPARTMENT_H
