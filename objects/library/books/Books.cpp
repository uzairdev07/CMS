//
// Created by Mr. Uzair on 2/24/2022.
//

#include "Books.h"
#include "../../courses/Courses.h"
#include "../../../helpers/Const.cpp"
#include "../../../helpers/style.cpp"
#include "../../../utilities/menu.h"
#include <conio.h>

/*
 *  Constructors
 *  Operator Overloading
 *  Methods
 *  Destructor
*/

// ? Constructor
Books::Books() {}

// ? Overloading Constructor

// ? Operator Overloading


// * Methods

// ? Display All Books
void Books::getTotalBooks() const {
    CSVParser parser;
    vector<CSVRow> header = parser.getHeader(BOOKS_FILE);
    vector<CSVRow> books = parser.read(BOOKS_FILE);
    if (!(books.size()) == 0) {
        for ( auto col: header )
            cout << setw(COL_WIDTH) << col.getString(0)
                 << setw(COL_WIDTH) << col.getString(1)
                 << setw(COL_WIDTH) << col.getString(2)
                 << setw(COL_WIDTH) << col.getString(3)
                 << endl;
        printLine(90);
        for ( auto book: books )
            cout << setw(COL_WIDTH) << book.getInt(0)
                 << setw(COL_WIDTH) << book.getString(1)
                 << setw(COL_WIDTH) << book.getString(2)
                 << setw(COL_WIDTH) << book.getInt(3)
                 << endl;
    } else
        cerr << "No Record Founded Ye! ...";
}

// ? Search by Book Id
void Books::searchById(int id) {
    CSVParser parser;
    vector<CSVRow> books = parser.search(BOOKS_FILE, id, 0);
    printBooks(books);
}

// ? Search by Book data
vector<CSVRow> Books::searchBook(string data, int index) {
    CSVParser parser;
    vector<CSVRow> books = parser.search(BOOKS_FILE, data, index);
    if (books.size() == 0) {
        cerr << "No Record Founded Yet! ...";
    }
    return books;
}

// ? Search by Books data
vector<CSVRow> Books::searchBook(int data, int index) {
    CSVParser parser;
    vector<CSVRow> books = parser.search(BOOKS_FILE, data, index);
    if (books.size() == 0) {
        cerr << "No Record Founded Yet! ...";
    }
    return books;
}

// ? Search By Book Author
void Books::searchByAuthor(string author) {
    vector<CSVRow> records = searchBook(author, 1);
    printBooks(records);
}

// ? Search By Book Title
void Books::searchByTitle(string title) {
    vector<CSVRow> records = searchBook(title, 2);
    printBooks(records);
}

// ? Search By Book Pages
void Books::searchByPages(int pages) {
    vector<CSVRow> records = searchBook(pages, 3);
    printBooks(records);
}

// ? Get Number of Books
int Books::getSize() const {
    CSVParser parser;
    vector<CSVRow> books = parser.read(BOOKS_FILE);
    return books.size();
}

void Books::printBooks(vector<CSVRow> records) const {
    if (records.size() != 0) {
        cout << setw(COL_WIDTH) << "Id" << setw(COL_WIDTH) << "Author" << setw(COL_WIDTH) << "Title" << setw(COL_WIDTH)
             << "Pages" << setw(COL_WIDTH) << "Status" << endl;
        for ( auto book: records)
            cout << setw(COL_WIDTH) << book.getInt(0)
                 << setw(COL_WIDTH) << book.getString(1)
                 << setw(COL_WIDTH) << book.getString(2)
                 << setw(COL_WIDTH) << book.getInt(3)
                 << endl;
    } else
        cerr << "No Records founded yet!..." << endl;
}

// ? Display Menu
void Books::displayMenu() const {
    for ( int i = 0; i < options.size(); i++ )
        cout << setw(WIDTH) << i + 1 << ". " << options.at(i) << endl;
}

// ? Display Search Menu
void Books::displaySearchMenu() const {
    for (int i = 0; i < searchOptions.size(); i++)
        cout << setw(WIDTH) << i + 1 << ". " << searchOptions.at(i) << endl;
}

// ? Select Menu
void Books::select() {
    display:
    clear();
    displayMenu();
    int id, key, pages;
    string author, title;
    book b;
    int n;
    again:
    cout << "Enter Number (Press 0 to go back): ";
    n = getche();
    n -= 48;
    if (n == 0)
        Menu m;
    switch (n) {
        case 1:
            clear();
            b.setBook();
            break;
        case 2:
            clear();
            break;
        case 3:
            clear();
            break;
        case 4:
        searchMenu:
            clear();
            displaySearchMenu();
            int n, key;
            cout << "Enter Number (Press 0 to go back): ";
            n = getche();
            n -= 48;
            if (n == 0)
                goto display;
            switch (n) {
                case 1:
                    clear();
                    getTotalBooks();
                    cout << "Enter id: ";
                    cin >> id;
                    searchById(id);
                    break;
                case 2:
                    clear();
                    getTotalBooks();
                    cout << "Enter Author: ";
                    cin >> author;
                    searchByAuthor(author);
                    break;
                case 3:
                    clear();
                    getTotalBooks();
                    cout << "Enter Title: ";
                    cin >> title;
                    searchByTitle(title);
                    break;
                case 4:
                    clear();
                    getTotalBooks();
                    cout << "Enter Pages: ";
                    cin >> pages;
                    searchByPages(pages);
                    break;
            }
            cout << "Press 0 to go back: ";
            key = getche();
            key -= 48;
            if (key == 0)
                goto searchMenu;
            break;
        case 5:
            clear();
            getTotalBooks();
            break;
        default:
            cout << "Invalid Choice! try again..." << endl;
            clear();
            goto again;
    }
    cout << "Press 0 to go back: ";
    key = getche();
    key -= 48;
    if (key == 0)
        goto display;
}

// ? Destructor
Books::~Books() {

}
