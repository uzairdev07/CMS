//
// Created by Mr. Uzair on 4/10/2022.
//

#include "Lend.h"
#include <sstream>
#include "../../CSVParser/CSVParser.h"

Lend::Lend(int book_id, const Date &issue_Date, const Date &return_Date, int student_id)
{
    setLendBook(book_id, issue_Date, return_Date, student_id);
}

// * Methods
void Lend::lendBook(string file, int book_id, int student_id) {
    setLendBook(book_id, issueDate, returnDate, student_id);
    CSVParser parser;
    parser.write(file, getData(), this->col_names);
}

void Lend::setLendBook(int book_id, const Date &issue_Date, const Date &return_Date, int student_id) {
    bookId = book_id;
    issueDate.now();
    returnDate = issueDate.getDay() + 7;
    studentId = student_id;
}

string Lend::getData() const {
    stringstream ss;
    ss << bookId;
    ss << ",";
    ss << issueDate;
    ss << ",";
    ss << returnDate;
    ss << ",";
    ss << studentId;
    ss << ",";
    ss << "\n";
    string data = ss.str();
    return data;
}

// ? Getters and Setters
int Lend::getBookId() const {
    return bookId;
}

void Lend::setBookId(int bookId) {
    bookId = bookId;
}

const Date &Lend::getIssueDate() const {
    return issueDate;
}

void Lend::setIssueDate(const Date &issueDate) {
    Lend::issueDate = issueDate;
}

const Date &Lend::getReturnDate() const {
    return returnDate;
}

void Lend::setReturnDate(const Date &returnDate) {
    Lend::returnDate = returnDate;
}

int Lend::getStudentId() const {
    return studentId;
}

void Lend::setStudentId(int studentId) {
    studentId = studentId;
}