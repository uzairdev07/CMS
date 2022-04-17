//
// Created by Mr. Uzair on 2/28/2022.
//

#ifndef UNI_PROJECT_CSVPARSER_H
#define UNI_PROJECT_CSVPARSER_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "CSVRow.h"

class CSVParser {
public:
    // * Constructor
    CSVParser();

    // ? Methods
    vector<CSVRow> read(string file, bool isHeader = false);
    void write(string file, string data, vector<string> header_cols);
    vector<CSVRow> getHeader(string file, bool isHeader = true);
    void setHeader(string file, vector<string> headerCols, bool isHeader = true);
    // ? Search Int Data
    vector<CSVRow> search(string file, int data, int index, bool isHeader = false);
    // ? Search Float Data
    vector<CSVRow> search(string file, float data, int index, bool isHeader = false);
    // ? Search String Data
    vector<CSVRow> search(string file, string data, int index, bool isHeader = false);

    // ? Search String without case-sensitivity
    size_t findCaseInsensitive(std::string data, std::string toSearch, size_t pos = 0)
    {
        // Convert complete given String to lower case
        std::transform(data.begin(), data.end(), data.begin(), ::tolower);
        // Convert complete given Sub String to lower case
        std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
        // Find sub string in given string
        return data.find(toSearch, pos);
    }

};


#endif //UNI_PROJECT_CSVPARSER_H
