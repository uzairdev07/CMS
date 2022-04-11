//
// Created by Mr. Uzair on 4/10/2022.
//

#ifndef CMS_TIME_H
#define CMS_TIME_H

#include <iostream>
using namespace std;

class Time
{
public:
    // * Default Constructor
    Time(int = 0, int = 0, int = 0);

    // * Methods
    Time &setTime(int, int, int);
    void printMilitary() const;
    void printStandard() const;

    // ? Getters and Setters

    // * + Set Functions
    Time &setHour(int);
    Time &setMinute(int);
    Time &setSecond(int);

    // * + Get Functions
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    ~Time();

private:
    // * Data Members
    int hour;       // ? 0 - 23
    int minute;     // ? 0 - 59
    int second;     // ? 0 - 59
};


#endif //CMS_TIME_H
