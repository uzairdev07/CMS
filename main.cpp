#include <iostream>
#include <iomanip>
#include "CSVParser/CSVParser.h"
#include "CSVParser/CSVRow.h"
#include "objects/students/student.h"
#include "objects/students/Students.h"
using namespace std;

int main() {
//    string filePath = "E:\\WorkFiles\\Work\\CMS\\data.csv";
//    CSVParser parser;
//    vector<CSVRow> rows = parser.read(filePath);
//    vector<CSVRow> header = parser.getHeader(filePath);
//    for (auto col : header)
//        cout << setw(15) << col.getString(0)
//             << setw(15) << col.getString(1)
//             << setw(15) << col.getString(2)
//             << setw(15) << col.getString(3) << endl;
//    for (auto col : rows)
//        cout << setw(15) << col.getInt(0)
//             << setw(15) << col.getString(1)
//             << setw(15) << col.getInt(2)
//             << setw(15) << col.getString(3) << endl;

    Students students;
    students.getTotalStudents();
    vector<student> st = students.searchStudent("uzair");
    for (auto student : st)
        cout << student.getRoll() << endl;
    return 0;
}