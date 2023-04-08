#include <iostream>
#include <string>

#include "transaction.h"

Transaction::Transaction(int count, int price, Date date)
{
    if (count < 0)
        throw std::runtime_error("Invalid count!");
    if (price < 0)
        throw std::runtime_error("Invalid price!");
    this->count = count;
    this->price = price;
    this->date = date;
}

void Transaction::set_count(int count)
{
    this->count = count;
}

int Transaction::get_count()
{
    return count;
}