//
// Created by Mr. Uzair on 2/28/2022.
//

#include "CSVParser.h"
#include <iomanip>
#include "../helpers/Const.cpp"
#include "../helpers/style.cpp"

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

// ? Search Int Data
vector<CSVRow> CSVParser::search(string file, int data, int index, bool isHeader) {
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
        if (csvRow.getInt(index) == data)
            rows.push_back(csvRow);
    }
    inputFile.close();
    return rows;
}
// ? Search Float Data
vector<CSVRow> CSVParser::search(string file, float data, int index, bool isHeader) {
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
        if (csvRow.getDouble(index) == data)
            rows.push_back(csvRow);
    }
    inputFile.close();
    return rows;
}

// ? Search String Data
vector<CSVRow> CSVParser::search(string file, string data, int index, bool isHeader) {
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
        size_t pos = findCaseInsensitive(csvRow.getString(index), data);
        if (pos != string::npos) {
            rows.push_back(csvRow);
        }
    }
    inputFile.close();
    return rows;
}
