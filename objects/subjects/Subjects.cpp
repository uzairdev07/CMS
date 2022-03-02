//
// Created by Mr. Uzair on 2/24/2022.
//

#include "Subjects.h"
#include "../../CSVParser/CSVParser.h"
#include "../../helpers/Const.cpp"
#include "../../helpers/style.cpp"

/*
 *  Constructors
 *  Operator Overloading
 *  Methods
 *  Destructor
*/

// ? Constructor
Subjects::Subjects() {

}

// ? Overloading Constructor

// ? Operator Overloading

// * Methods

// ? Print all Subjects
void Subjects::getTotalSubjects() const {
    CSVParser parser;
    vector<CSVRow> header = parser.getHeader(SUBJECTS_FILE);
    vector<CSVRow> subjects = parser.read(SUBJECTS_FILE);
    for (auto col : header)
        cout << setw(15) << col.getString(0)
             << setw(15) << col.getString(1)
             << endl;
    printLine(30);
    for (auto subject : subjects)
        cout << setw(15) << subject.getInt(0)
             << setw(15) << subject.getString(1)
             << endl;
}

// ? Search Course by Id
subject Subjects::searchSubject(int id) {
    CSVParser parser;
    vector<CSVRow> subjects = parser.read(SUBJECTS_FILE);
    for (CSVRow row : subjects)
        if (id == row.getInt(0))
            return subject (
                    row.getInt(0),
                    row.getString(1)
            );
}

// ? Search Course by Name
vector<subject> Subjects::searchSubject(string name) {
    CSVParser parser;
    vector<CSVRow> subjects = parser.read(SUBJECTS_FILE);
    vector<subject> st;
    for (CSVRow row : subjects)
        if (name == row.getString(1))
            st.push_back (
                    subject (
                            row.getInt(0),
                            row.getString(1)
                    )
            );
    return st;
}

// ? Get Number of Subjects
int Subjects::getSize() const {
    CSVParser parser;
    vector<CSVRow> subjects = parser.read(SUBJECTS_FILE);
    return subjects.size();
}

// ? Destructor
Subjects::~Subjects() {}