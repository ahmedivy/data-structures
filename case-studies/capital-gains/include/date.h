#pragma once

enum class Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

class Date
{
private:
    int date;
    Month month;
    int year;

public:
    Date() = default;
    Date(int day, int month, int year);
       
};