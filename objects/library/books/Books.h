//
// Created by Mr. Uzair on 2/24/2022.
//

#ifndef UNI_PROJECT_BOOKS_H
#define UNI_PROJECT_BOOKS_H

#include <iostream>
#include <vector>
#include "book.h"
#include "../../../CSVParser/CSVParser.h"
using namespace std;

class Books {
private:
    // * Attributes
    vector<string> options{
            "Add New",
            "Update",
            "Delete",
            "Search",
            "Lend Book",
            "Return Book",
            "Display All"
    };
    vector<string> searchOptions{
            "Search By Id",
            "Search By Author",
            "Search By Title",
            "Search By Pages",
    };
public:
    // * Constructor
    Books();

    // * Overloaded Constructor

    // * Operator Overloading

    // * Methods
    void getTotalBooks() const;

    void searchById(int);
    vector<CSVRow> searchBook(string, int);
    vector<CSVRow> searchBook(int, int);
    void searchByAuthor(string);
    void searchByTitle(string);
    void searchByPages(int);
    int getSize() const;
    void printBooks(vector<CSVRow> records) const;
    void lendBook(int book_id, int student_id);
    void returnBook();

    // ? Menu
    void displayMenu() const;

    void displaySearchMenu() const;

    void select();

    // * Destructors
    ~Books();
};

#endif //UNI_PROJECT_BOOKS_H