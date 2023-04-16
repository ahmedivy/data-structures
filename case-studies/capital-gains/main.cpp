#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "date.h"
#include "transaction.h"
#include "dynamic_queue.h"

using Queue = LinkedQueue<Transaction *>;
int find_capital_gains(Queue &bought, Queue &sold);
void loadData(std::string filename, LinkedQueue<Transaction *> &q);

int main()
{
    Queue bought;
    Queue sold;

    loadData("data/bought.txt", bought);
    loadData("data/sold.txt", sold);

    int gains = find_capital_gains(bought, sold);
    std::cout << "Total Gains: " << gains << std::endl;

    return 0;
}

int find_capital_gains(Queue &bought, Queue &sold)
{
    int gains = 0;
    Transaction *buy;
    Transaction *sell;
    while (!bought.isEmpty() && !sold.isEmpty())
    {
        buy = bought.peek();
        sell = sold.peek();
        if (buy->count < sell->count)
        {
            gains += buy->count * (sell->price - buy->price);
            sold.peek()->count -= buy->count;
            bought.dequeue();
        }
        else
        {
            gains += sell->count * (sell->price - buy->price);
            sold.dequeue();
            if (buy->count == sell->count)
                bought.dequeue();
            else
                bought.peek()->count -= sell->count;
        }
    }
    return gains;
}

void loadData(std::string filename, LinkedQueue<Transaction *> &q)
{
    std::ifstream file(filename);

    if (!file)
    {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    int numEntries;
    file >> numEntries;
    file.ignore(); // Ignore newline character

    for (int i = 0; i < numEntries; i++)
    {
        std::string line;
        getline(file, line);
        std::stringstream ss(line);

        std::string quantityStr, priceStr, dateString;
        getline(ss, quantityStr, ',');
        getline(ss, priceStr, ',');
        getline(ss, dateString, ',');

        int quantity = stoi(quantityStr);
        int price = stoi(priceStr);

        int year = stoi(dateString.substr(0, 4));
        int month = stoi(dateString.substr(4, 2));
        int day = stoi(dateString.substr(6, 2));

        Transaction *t = new Transaction(quantity, price, Date(day, month, year));
        q.enqueue(t);
    }

    file.close();
}