//
// Created by Mr. Uzair on 2/28/2022.
//

#ifndef UNI_PROJECT_CSVPARSER_H
#define UNI_PROJECT_CSVPARSER_H

#include <iostream>
#include <fstream>
#include "CSVRow.h"

class CSVParser {
public:
    // * Constructor
    CSVParser();

    // ? Methods
    vector<CSVRow> read(string file, bool isHeader = false);
    void write(string file, string data);
    vector<CSVRow> getHeader(string file, bool isHeader = true);

};


#endif //UNI_PROJECT_CSVPARSER_H
