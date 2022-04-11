//
// Created by Mr. Uzair on 4/10/2022.
//

#ifndef CMS_DATE_H
#define CMS_DATE_H

#include <iostream>
using namespace std;

class Date {
private:
    // * Attributes
    int day;    // ? 1 - 31 based on month
    int month;  // ? 1 - 12
    int year;   // ? any year
    static int days[];
    
public:
    // * Constructors
    Date(int = 1, int = 1, int = 1900); // ? Default
    // * Overloading Constructor

    // * Operator Overloading

    // ? Increment and Decrement Operators
    // * Pre Method
    Date operator++();
    Date operator--();
    // * Post Method
    Date operator++(int);
    Date operator--(int);
    // ? Assignment Operator
    Date operator=(const Date &rhs);
    // ? Equality Operator
    bool operator==(const Date &rhs);
    bool operator!=(const Date &rhs);
    // ? Insertion Operator
    friend istream &operator>>(istream &is, Date &date);
    // ? Extraction Operator
    friend ostream &operator<<(ostream &os, const Date &date);

    // * Methods

    void setDate(int d, int m, int y);
    void now();
    // ? Print Date in Day-Month-Year
    void print() const;
    // ? Increment Help
    void increment();
    void decrement();
    // ? Determines if the day is the end of the month
    int endOfMonth(int d);
    // ? Determines if the day is the start of the month
    int startOfMonth(int d);
    // ? Determines if the year is the leap year
    int leapYear(int y);

    // ? Getters and Setters
    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

    // * Destructors
    ~Date();
};


#endif //CMS_DATE_H
