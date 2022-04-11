//
// Created by Mr. Uzair on 4/10/2022.
//

#include "LocalDateTime.h"

LocalDateTime::LocalDateTime(Date &date, Time &time) {
    setDateTime(date, time);
}

void LocalDateTime::setDateTime(Date &date, Time &time) {
    date = Date();
    time = Time();
}

void LocalDateTime::print() {
    cout << date.getDay() << "-" << date.getMonth() << date.getYear()
         << " " << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond();
}

// ? Getters and Setters

const Date &LocalDateTime::getDate() const {
    return date;
}

void LocalDateTime::setDate(const Date &date) {
    LocalDateTime::date = date;
}

const Time &LocalDateTime::getTime() const {
    return time;
}

void LocalDateTime::setTime(const Time &time) {
    LocalDateTime::time = time;
}