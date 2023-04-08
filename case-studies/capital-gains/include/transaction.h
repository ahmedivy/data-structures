#pragma once

#include "date.h"

class Transaction
{
public:
    int count;
    int price;
    Date date;
    Transaction() = default;
    Transaction(int count, int price, Date date);
    void set_count(int count);
    int get_count();
};
