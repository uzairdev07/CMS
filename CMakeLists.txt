cmake_minimum_required(VERSION 3.21)
project(CMS)

set(CMAKE_CXX_STANDARD 23)

add_executable(CMS main.cpp CSVParser/CSVParser.cpp CSVParser/CSVParser.h CSVParser/CSVRow.cpp CSVParser/CSVRow.h)
