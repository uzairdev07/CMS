//
// Created by Mr. Uzair on 4/12/2022.
//

#ifndef CMS_ATTENDANCE_H
#define CMS_ATTENDANCE_H

#include <iostream>
#include <vector>
#include "DateTime/Date.h"
using namespace std;

class Attendance {
private:
    // * Attributes
    int student_id{};
    int status{};     // ? 1 for Preset and 0 for absent
    Date attendance_date;
    vector<string> col_names {
            "Student Id",
            "Status",
            "Date"
    };
public:
    Attendance();
    void takeAttendance(int studentId, int status = 1);

    string getData() const;

    // ? Getters and Setters
    int getStudentId() const;

    void setStudentId(int studentId);

    int getStatus() const;

    void setStatus(int status);

    const Date &getAttendanceDate() const;

    void setAttendanceDate(const Date &attendanceDate);

};


#endif //CMS_ATTENDANCE_H
