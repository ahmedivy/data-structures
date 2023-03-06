#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype>

using namespace std;

bool isOperator(char c);
int precedence(char op);

int main()
{
    string infixExp;
    cout << "Enter the Infix Expression: ";
    getline(cin, infixExp);

    stack<char> operatorsStack;
    queue<string> outputQueue;

    const char *ch = infixExp.c_str();
    string operand;

    while(*ch != '\0')
    {
        if (isspace(*ch))
        {
            ch++;
            continue;
        }

        if (isdigit(*ch))
        {
            operand += *ch;
            ch++;
            if (!isdigit(*ch))
            {
                outputQueue.push(operand);
                operand = "";
            }
        }
        else if (isOperator(*ch))
        {
            if (operatorsStack.empty())
            {
                operatorsStack.push(*ch);
            }
            else
            {
                if (precedence(*ch) > precedence(operatorsStack.top()))
                {
                    operatorsStack.push(*ch);
                }
                else
                {
                    while (!operatorsStack.empty() && precedence(*ch) <= precedence(operatorsStack.top()))
                    {
                        string op(1, operatorsStack.top());
                        outputQueue.push(op);
                        operatorsStack.pop();
                    }
                    operatorsStack.push(*ch);
                }
            }
            ch++;
        }
        else if (*ch == '(')
        {
            operatorsStack.push(*ch);
            ch++;
        }
        else if (*ch == ')')
        {
            while (operatorsStack.top() != '(')
            {
                string op(1, operatorsStack.top());
                outputQueue.push(op);
                operatorsStack.pop();
            }
            operatorsStack.pop();
            ch++;
        }
        else
        {
            cout << "Invalid Expression" << endl;
            return 0;
        }
    }

    while (!operatorsStack.empty())
    {
        string op(1, operatorsStack.top());
        outputQueue.push(op);
        operatorsStack.pop();
    }

    cout << "Postfix Expression: ";
    while (!outputQueue.empty())
    {
        cout << outputQueue.front();
        outputQueue.pop();
    }
    cout << endl;

    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op)
{
    switch (op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
