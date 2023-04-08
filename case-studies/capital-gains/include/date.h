#pragma once

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date() = default;
    Date(int day, int month, int year);
    std::string format_string();
};