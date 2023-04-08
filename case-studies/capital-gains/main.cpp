#include <iostream>
#include <string>

#include "date.h"
#include "transaction.h"
#include "dynamic_queue.h"

using Queue = LinkedQueue<Transaction*>;
int find_capital_gain(Queue &, Queue &);

int main()
{
    Queue bought;
    Queue sold;

    bought.enqueue(new Transaction(100, 25, Date(15, 3, 2022)));
    bought.enqueue(new Transaction(200, 20, Date(20, 8, 2022)));

    sold.enqueue(new Transaction(60, 30, Date(10, 6, 2022)));
    sold.enqueue(new Transaction(240, 50, Date(25, 10, 2022)));

    int gains = find_capital_gain(bought, sold);
    std::cout << "Total Gains: " << gains << std::endl;

    return 0;
}

int find_capital_gains(Queue &bought, Queue &sold)
{
    int gains = 0;
    Transaction* buy;
    Transaction* sell;
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
