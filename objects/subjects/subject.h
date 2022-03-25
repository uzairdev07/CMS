//
// Created by Mr. Uzair on 2/26/2022.
//

#ifndef UNI_PROJECT_SUBJECT_H
#define UNI_PROJECT_SUBJECT_H

#include <iostream>
using namespace std;

class subject {
private:
    // * Attributes
    int id;
    string name;
    int course_id;
public:
    // * Constructor
    subject();
    // * Overloaded Constructor
    subject(int id, string name, int course_id);

    // * Operator Overloading

    // ? Extraction Operator
    friend istream &operator>>(istream &is, subject &subject);
    // ? Insertion Operator
    friend ostream &operator<<(ostream &os, const subject &subject);

    // * Methods

    void setSubject();
    string getSubject() const;

    // * Getters and Setters
    int getId() const;

    void setId(int id);

    const string &getName() const;

    void setName(const string &name);

    int getCourseId() const;

    void setCourseId(int courseId);

    // * Destructor
    ~subject();

};


#endif //UNI_PROJECT_SUBJECT_H
