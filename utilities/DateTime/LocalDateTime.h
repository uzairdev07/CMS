//
// Created by Mr. Uzair on 4/10/2022.
//

#ifndef CMS_LOCALDATETIME_H
#define CMS_LOCALDATETIME_H

#include <iostream>
#include <ctime>
#include "Date.h"
#include "Time.h"

class LocalDateTime {
private:
    // * Attributes
    Date date;
    Time time;
public:
    // * Default Constructor
    LocalDateTime(Date &, Time &);
    // * Overloaded Constructors

    // * Methods

    void setDateTime(Date &, Time &);
    // ? Print Local Date Time
    void print();

    // ? Getters and Setters
    const Date &getDate() const;

    void setDate(const Date &date);

    const Time &getTime() const;

    void setTime(const Time &time);
};


#endif //CMS_LOCALDATETIME_H
