#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

// Function to check if a character is an operator
bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix expression to postfix expression
string infix_to_postfix(string infix)
{
    stack<char> operator_stack;
    queue<char> output_queue;
    unordered_map<char, int> precedence_map = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'^', 3}};

    for (char c : infix)
    {
        if (isdigit(c))
        {
            output_queue.push(c);
        }
        else if (is_operator(c))
        {
            while (!operator_stack.empty() && is_operator(operator_stack.top()) 
                    && precedence_map[operator_stack.top()] >= precedence_map[c])
            {
                output_queue.push(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.push(c);
        }
        else if (c == '(')
        {
            operator_stack.push(c);
        }
        else if (c == ')')
        {
            while (!operator_stack.empty() && operator_stack.top() != '(')
            {
                output_queue.push(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.pop();
        }
    }

    while (!operator_stack.empty())
    {
        output_queue.push(operator_stack.top());
        operator_stack.pop();
    }

    string postfix = "";
    while (!output_queue.empty())
    {
        postfix += output_queue.front();
        output_queue.pop();
    }

    return postfix;
}

int main()
{
    string infix = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
    string postfix = infix_to_postfix(infix);
    cout << postfix << endl; // Output: 342*15-2^3^^/
    return 0;
}
