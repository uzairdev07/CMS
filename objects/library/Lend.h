//
// Created by Mr. Uzair on 4/10/2022.
//

#ifndef CMS_LEND_H
#define CMS_LEND_H

#include <iostream>
#include <vector>
#include "../../utilities/DateTime/Date.h"
using namespace std;

class Lend {
private:
    // * Attributes
    int bookId;
    Date issueDate;
    Date returnDate;
    int studentId;
    // * Header Cols
    vector<string> col_names = {
            "Book Id",
            "Issue Date",
            "Return Date",
            "Student Id",
    };
    // * Get Lend Book Data
    string getData() const;
public:
    // * Default Constructor
    Lend(int book_id = 0, const Date &issue_Date = Date(1, 1, 1996), const Date &return_Date = Date(7, 1, 1996), int student_id = 0);
    // * Overloaded Constructors

    // * Methods
    void lendBook(string file, int book_id, int student_id);
    void setLendBook(int book_id, const Date &issue_Date, const Date &return_Date, int student_id);
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
