//
// Created by Mr. Uzair on 2/24/2022.
//

#include "Teachers.h"

/*
 *  Constructors
 *  Operator Overloading
 *  Methods
 *  Destructor
*/

// ? Constructor
Teachers::Teachers() {}

// * Methods

// ? Display All Teachers
void Teachers::getTotalTeachers() const {
    CSVParser parser;
    vector<CSVRow> header = parser.getHeader(TEACHERS_FILE);
    vector<CSVRow> teachers = parser.read(TEACHERS_FILE);
    for (auto col : header)
        cout << setw(15) << col.getString(0)
             << setw(15) << col.getString(1)
             << setw(15) << col.getString(2)
             << setw(15) << col.getString(3)
             << setw(15) << col.getString(4)
             << endl;
    printLine();
    for (auto teacher: teachers)
        cout << setw(15) << teacher.getInt(0)
             << setw(15) << teacher.getString(1)
             << setw(15) << teacher.getString(2)
             << setw(15) << teacher.getString(3)
             << setw(15) << teacher.getString(4)
             << endl;
}

// ? Search by Teacher Id
teacher Teachers::searchTeacher(int id) {
    CSVParser parser;
    vector<CSVRow> teachers = parser.read(TEACHERS_FILE);
    for (CSVRow row : teachers)
        if (id == row.getInt(0))
            return teacher (
                    row.getInt(0),
                    row.getString(1),
                    row.getString(2),
                    row.getString(3),
                    row.getString(4)
            );
}

// ? Search by Teacher Name
vector<teacher> Teachers::searchTeacher(string name) {
    CSVParser parser;
    vector<CSVRow> teachers = parser.read(TEACHERS_FILE);
    vector<teacher> ts;
    for (CSVRow row : teachers)
        if (name == row.getString(1))
            ts.push_back (
                    teacher (
                            row.getInt(0),
                            row.getString(1),
                            row.getString(2),
                            row.getString(3),
                            row.getString(4)
                    )
            );
    return ts;
}

// ? Get Number of Teachers
int Teachers::getSize() const {
    CSVParser parser;
    vector<CSVRow> teachers = parser.read(TEACHERS_FILE);
    return teachers.size();
}

// ? Print Header Bottom Line
void Teachers::printLine() const {
    cout << setw(8);
    for (int i = 0; i < 75; i++)
        (i < 74) ? (cout << "_") : (cout << endl);
}

// Destructors
Teachers::~Teachers() {

}
