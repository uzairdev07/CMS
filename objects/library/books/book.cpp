//
// Created by Mr. Uzair on 2/26/2022.
//

#include "book.h"
#include "../../../CSVParser/CSVParser.h"
#include "../../../helpers/Const.cpp"
#include <iomanip>

/*
 *  Constructors
 *  Operator Overloading
 *  Methods
 *  Getters and Setters
 *  Destructor
*/

// ? Constructors

book::book() {

}

// ? Overloaded Constructor
book::book(int id, string author, string title, int pages)
        :id{id}, author{author}, title{title}, pages{pages}
{}

// * Operator Overloading

// ? Extraction Operator
istream &operator>>(istream &is, book &book) {
    cout << "Enter Id: ";
    is >> book.id;
    cout << "Enter Author Name: ";
    is >> book.author;
    cout << "Enter Title: ";
    is >> book.title;
    cout << "Enter Pages: ";
    is >> book.pages;
    return is;
}

// ? Insertion Operator
ostream &operator<<(ostream &os, const book &book) {
    os << setw(COL_WIDTH)
       << book.getId() << setw(COL_WIDTH)
       << book.getAuthor() << setw(COL_WIDTH)
       << book.getTitle() << setw(COL_WIDTH)
       << book.getPages() << setw(COL_WIDTH)
       << endl;
    return os;
}

// * Methods

// ? Insert book Into File
void book::setBook() {
    CSVParser parser;
    cin >> *this;
    parser.write(BOOKS_FILE, this->getBook());
}

// ? Get book
string book::getBook() const {
    stringstream ss;
    ss << this->getId();
    ss << ",";
    ss << this->getAuthor();
    ss << ",";
    ss << this->getTitle();
    ss << ",";
    ss << this->getPages();
    ss << ",";
    ss << "\n";
    string book = ss.str();
    return book;
}

// ? Update book
void book::updateBook() {
    CSVParser parser;
    int n = 0, course_id{}, pages{};
    string author{}, title{};
    again:
    cout << "Enter number: ";
    cin >> n;
    switch (n) {
        case 1:
            cout << "Enter Author Name: ";
            cin >> author;
            this->setAuthor(author);
            break;
        case 2:
            cout << "Enter Title: ";
            cin >> title;
            this->setTitle(title);
            break;
        case 3:
            cout << "Enter Pages: ";
            cin >> pages;
            this->setPages(pages);
            break;
        default:
            cerr << "Invalid Input! ";
            goto again;
            break;
    }

}

// ? Getters and Setters
int book::getId() const {
    return id;
}

void book::setId(int id) {
    book::id = id;
}

const string &book::getAuthor() const {
    return author;
}

void book::setAuthor(const string &author) {
    book::author = author;
}

const string &book::getTitle() const {
    return title;
}

void book::setTitle(const string &title) {
    book::title = title;
}

int book::getPages() const {
    return pages;
}

void book::setPages(int pages) {
    book::pages = pages;
}

// ? Destructor
book::~book() {

}