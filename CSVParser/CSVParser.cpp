//
// Created by Mr. Uzair on 2/28/2022.
//

#include "CSVParser.h"
#include "../helpers/Const.cpp"

CSVParser::CSVParser() {}

vector<CSVRow> CSVParser::read(string file, bool isHeader) {
    vector<CSVRow> rows {};
    ifstream inputFile;
    inputFile.open(file);
    string row {};
    if (!inputFile)
        cerr << "Error! Unable to open file..." << endl;
    if (!isHeader)
        getline(inputFile, row);
    while (getline(inputFile, row)) {
        CSVRow csvRow;
        csvRow.parseRow(row);
        rows.push_back(csvRow);
    }
    inputFile.close();
    return rows;
}

void CSVParser::write(string file, string data) {
    ofstream outputFile;
    outputFile.open(file, ios::out | ios::app);
    if (!outputFile)
        cerr << "Error! Unable to open file..." << endl;
    outputFile << data;
    outputFile.close();
}

vector<CSVRow> CSVParser::getHeader(string file, bool isHeader) {
    vector<CSVRow> header {};
    ifstream inputFile;
    inputFile.open(file);
    string h_row {};
    if (isHeader) {
        getline(inputFile, h_row);
        CSVRow csvRow;
        csvRow.parseHeader(h_row);
        header.push_back(csvRow);
    }
    inputFile.close();
    return header;
}
