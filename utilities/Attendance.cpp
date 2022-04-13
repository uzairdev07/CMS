//
// Created by Mr. Uzair on 4/12/2022.
//

#include "Attendance.h"
#include <sstream>
#include "../CSVParser/CSVParser.h"
#include "../helpers/Const.cpp"

Attendance::Attendance() {}

void Attendance::takeAttendance(int studentId, int status) {
    this->student_id = studentId;
    this->status = status;
    CSVParser parser;
    parser.write(STUDENTS_ATTENDANCE_FILE, this->getData());
}

string Attendance::getData() const {
    stringstream ss;
    ss << this->getStudentId();
    ss << ",";
    ss << this->getStatus();
    ss << ",";
    ss << this->getAttendanceDate();
    ss << ",";
    ss << endl;
    return ss.str();
}

// ? Getters and Setters

int Attendance::getStudentId() const {
    return student_id;
}

void Attendance::setStudentId(int studentId) {
    student_id = studentId;
}

int Attendance::getStatus() const {
    return status;
}

void Attendance::setStatus(int status) {
    Attendance::status = status;
}

const Date &Attendance::getAttendanceDate() const {
    return attendance_date;
}

void Attendance::setAttendanceDate(const Date &attendanceDate) {
    attendance_date = attendanceDate;
}
