#include <iostream>
#include <string>

#include "date.h"

Date::Date(int day, int month, int year)
{
    if (day < 1 || day > 31)
        throw std::runtime_error("Invalid day!");
    if (month < 1 || month > 12)
        throw std::runtime_error("Invalid month!");
    if (year < 1900 || year > 2100)
        throw std::runtime_error("Invalid year!");
    this->day = day;
    this->month = month;
    this->year = year;
}

std::string Date::format_string()
{
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}
