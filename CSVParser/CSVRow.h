//
// Created by Mr. Uzair on 2/28/2022.
//

#ifndef UNI_PROJECT_CSVROW_H
#define UNI_PROJECT_CSVROW_H

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class CSVRow {
    vector<string> values;
public:
    // * Constructor
    CSVRow();
    // * Copy Constructor
    CSVRow(const CSVRow &obj);

    // * Operator Overloading

    // ? Assignment Operator
    CSVRow operator=(const CSVRow &rhs);

    // ? Methods
    void parseRow(string row, char delimiter = ',');
    vector<string> parseHeader(string row, char delimiter = ',');
    template<class T>
    T getColumn(int index);

    // ! Destructor

};


#endif //UNI_PROJECT_CSVROW_H
