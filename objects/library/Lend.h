//
// Created by Mr. Uzair on 4/10/2022.
//

#ifndef CMS_LEND_H
#define CMS_LEND_H

#include <iostream>
#include "../../utilities/DateTime/Date.h"
using namespace std;

class Lend {
private:
    // * Attributes
    int bookId;
    Date issueDate;
    Date returnDate;
    int studentId;
public:
    // * Default Constructor
    Lend(int bookId, const Date &issueDate, const Date &returnDate, int studentId);
    // * Overloaded Constructors

    // * Methods
    void lendBook(int book_id, int student_id);
    // ? Getters and Setters
    int getBookId() const;

    void setBookId(int bookId);

    const Date &getIssueDate() const;

    void setIssueDate(const Date &issueDate);

    const Date &getReturnDate() const;

    void setReturnDate(const Date &returnDate);

    int getStudentId() const;

    void setStudentId(int studentId);
};


#endif //CMS_LEND_H
