//
// Created by Mr. Uzair on 2/28/2022.
//

#include "CSVRow.h"

CSVRow::CSVRow() {}

CSVRow::CSVRow(const CSVRow &obj) {
    values = obj.values;
}

CSVRow CSVRow::operator=(const CSVRow &rhs) {
    values = rhs.values;
}

void CSVRow::parseRow(string row, char delimiter) {
    stringstream inRow {row};
    string tempCol {};
    while (getline(inRow, tempCol, delimiter))
        values.push_back(tempCol);
}

vector<string> CSVRow::parseHeader(string row, char delimiter) {
    stringstream header {row};
    string tempHeader {};
    while (getline(header, tempHeader, delimiter))
        values.push_back(tempHeader);
    return values;
}

template<class T>
T CSVRow::getColumn(int index) {
    return values[index];
}
