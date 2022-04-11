//
// Created by Mr. Uzair on 4/10/2022.
//

#include "Lend.h"

Lend::Lend(int bookId, const Date &issueDate, const Date &returnDate, int studentId)
        : bookId(bookId), issueDate(issueDate), returnDate(returnDate), studentId(studentId)
{}

// * Methods
void Lend::lendBook(int book_id, int student_id) {
    bookId = book_id;
    issueDate.now();
    returnDate = issueDate.getDay() + 7;
    studentId = student_id;
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