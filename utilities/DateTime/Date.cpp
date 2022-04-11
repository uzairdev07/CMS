//
// Created by Mr. Uzair on 4/10/2022.
//

#include "Date.h"

/*
 *  Constructors
 *  Operator Overloading
 *  Methods
 *  Getters and Setters
 *  Destructor
*/

// ? Initialize static data members
int Date::days[13] = {
        0, 31, 28, 31, 30,
        31, 30, 31, 31, 30,
        31, 30, 31
};

int defaultDay = 1;
int defaultMonth = 1;
int defaultYear = 1990;

// ? Constructors
Date::Date(int d, int m, int y) {
    setDate(d, m, y);
}

// ? Overloaded Constructor

// * Operator Overloading

Date Date::operator++() {
    increment();
    return *this;
}

Date Date::operator--() {
    decrement();
    return *this;
}

Date Date::operator++(int) {
    Date temp = *this;
    increment();
    return temp;
}

Date Date::operator--(int) {
    Date temp = *this;
    decrement();
    return temp;
}

Date Date::operator=(const Date &rhs) {
    day = rhs.day;
    month = rhs.month;
    year = rhs.year;
    return *this;
}

bool Date::operator==(const Date &rhs) {
    if (day == rhs.day && month == rhs.month && year == rhs.month)
        return true;
    else
        return false;
}

bool Date::operator!=(const Date &rhs) {
    if (!(day == rhs.day && month == rhs.month && year == rhs.month))
        return true;
    else
        return false;
}

//Date Date::operator>(const Date &rhs) {
//    return Date();
//}
//
//Date Date::operator<(const Date &rhs) {
//    return Date();
//}
//
//Date Date::operator>=(const Date &rhs) {
//    return Date();
//}
//
//Date Date::operator<=(const Date &rhs) {
//    return Date();
//}

// ? Extraction Operator
istream &operator>>(istream &is, Date &date) {
    cout << "Enter Day: ";
    is >> date.day;
    cout << "Enter Month: ";
    is >> date.month;
    cout << "Enter Year: ";
    is >> date.year;
    return is;
}

// ? Insertion Operator
ostream &operator<<(ostream &os, const Date &date) {
    os << date.getDay() << "-" << date.getMonth() << "-" << date.getYear();
    return os;
}

// * Methods

void Date::setDate(int d, int m, int y) {
    month = (m >= 1 && m <= 12) ? m : 1;
    year = (y >= 1900 && y <= 2100) ? y : 1900;
    if (month == 2 && leapYear(year))       // * Test for a leap year
        day = (d >= 1 && d <= 29) ? d : 1;
    else
        day = (d >= 1 && d <= days[month]) ? d : 1;
}

void Date::now() {
    time_t time = time;
    tm *tm = localtime(&time);
    day = tm->tm_mday;
    month = tm->tm_mon;
    year = tm->tm_year;
}

    int Date::endOfMonth(int d) {
    if (month == 2 && leapYear(year))
        return d == 29;                 // * Last day of Feb in leap year
    else
        return d == days[month];
}

int Date::startOfMonth(int d) {
    if (d < 1 && month == 3 && leapYear(year))
        return d == days[month];          // * Last day of month in leap year
    else
        return d == 29;
}

int Date::leapYear(int y) {
    if ((y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)))
        return 1;                           // * A leap y
    else
        return 0;                           // ! Not a leap year
}

void Date::print() const {
    cout << day << "-" << month << "-" << year;
}

void Date::increment() {
    if (endOfMonth(day) && month == 12) {   // * End Year
        day = 1;
        month = 1;
        ++year;
    } else if (endOfMonth(day)) {
        day = 1;
        ++month;
    } else
        ++day;
}

void Date::decrement() {
    if (endOfMonth(day) && month == 12) {   // * End Year
        day = 1;
        month = 1;
        --year;
    } else if (endOfMonth(day)) {
        --month;
        day = days[month];
    } else
        --day;
}

// ? Getters and Setters
int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

// ? Destructor
Date::~Date() {

}