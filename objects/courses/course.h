//
// Created by Mr. Uzair on 2/24/2022.
//

#ifndef UNI_PROJECT_COURSE_H
#define UNI_PROJECT_COURSE_H

#include <iostream>
#include <vector>
using namespace std;

class course {
private:
    // * Attributes
    int id;
    string name;
    float fee;
    string startDate;
    int dep_id;
    // * Header Cols
    vector<string> col_names {
            "Id",
            "Name",
            "Start Date",
            "Depart. Id"
    };
public:
    // * Constructor
    course();
    // * Overloaded Constructor
    course(int id, string name, float fee, string startDate, int dep_id);

    // * Operator Overloading

    // ? Extraction Operator
    friend istream &operator>>(istream &is, course &course);
    // ? Insertion Operator
    friend ostream &operator<<(ostream &os, const course &course);

    // * Methods

    void setCourse();
    string getCourse() const;

    // ? Getters and Setters
    int getId() const;

    void setId(int id);

    const string &getName() const;

    void setName(const string &name);

    float getFee() const;

    void setFee(float fee);

    const string &getStartDate() const;

    void setStartDate(const string &startDate);

    const int &getDepartmentId() const;

    void setDepartmentId(const int dep_id);

    // * Destructor
    ~course();
};


#endif //UNI_PROJECT_COURSE_H
