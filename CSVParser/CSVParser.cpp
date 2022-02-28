//
// Created by Mr. Uzair on 2/28/2022.
//

#include "CSVParser.h"

CSVParser::CSVParser() {}

vector<CSVRow> CSVParser::read(string file, bool isHeader) {
    vector<CSVRow> rows {};
    ifstream inputFile (file.c_str());
    string row {};
    if (isHeader)
        getline(inputFile, row);
    while (getline(inputFile, row)) {
        CSVRow csvRow;
        csvRow.parseRow(row);
        rows.push_back(csvRow);
    }
    return rows;
}

void CSVParser::write(string file, string data) {
    ofstream outputFile (file, ios_base::app);
    if (!outputFile)
        cerr << "Error! Unable to open file..." << endl;
    outputFile << data;
    outputFile << ",";
    outputFile.close();
}

CSVRow CSVParser::getHeader(string file, bool isHeader) {
    CSVRow header {};
    ifstream inputFile (file.c_str());
    string h_row {};
    if (isHeader) {
        getline(inputFile, h_row);
        header.parseHeader(h_row);
    }
    return header;
}
