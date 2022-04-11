//
// Created by Mr. Uzair on 2/26/2022.
//

#ifndef UNI_PROJECT_BOOK_H
#define UNI_PROJECT_BOOK_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class book {
private:
    // * Attributes
    int id;
    string author;
    string title;
    int pages;

public:
    // * Constructors
    book();
    // * Overloading Constructor
    book(int id, string author, string title, int pages);

    // * Operator Overloading

    // ? Assignment Operator
    // ? Equality Operator
    // ? Insertion Operator
    friend istream &operator>>(istream &is, book &b);
    // ? Extraction Operator
    friend ostream &operator<<(ostream &os, const book &b);

    // * Methods

    void setBook();
    string getBook() const;
    void updateBook();

    // ? Getters and Setters
    int getId() const;

    void setId(int id);

    const string &getAuthor() const;

    void setAuthor(const string &author);

    const string &getTitle() const;

    void setTitle(const string &title);

    int getPages() const;

    void setPages(int pages);

    // * Destructors
    ~book();
};

#endif //UNI_PROJECT_BOOK_H
