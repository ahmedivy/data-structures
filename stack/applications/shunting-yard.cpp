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

    while (*ch)
    {
        if (isdigit(*ch))
        {
            operand += *ch;
        }
        else if (*ch == '.')
        {
            operand += *ch;
        }
        else if (!operand.empty())
        {
            outputQueue.push(operand);
            operand.clear();

            if (isOperator(*ch))
            {
                if (operatorsStack.empty())
                {
                    operatorsStack.push(*ch);
                }
                else
                {
                    while (precedence(operatorsStack.top()) >= precedence(*ch))
                    {
                        outputQueue.push(string(1, operatorsStack.top()));
                        operatorsStack.pop();
                        if (operatorsStack.empty())
                        {
                            break;
                        }
                    }
                    operatorsStack.push(*ch);
                }
            }
            else if (*ch == '(')
            {
                operatorsStack.push(*ch);
            }
            else if (*ch == ')')
            {
                while (operatorsStack.top() != '(')
                {
                    outputQueue.push(string(1, operatorsStack.top()));
                    operatorsStack.pop();
                }
                operatorsStack.pop();
            }
        }
        ch++;
    }

    if (!operand.empty())
    {
        outputQueue.push(operand);
    }

    while (!operatorsStack.empty())
    {
        outputQueue.push(string(1, operatorsStack.top()));
        operatorsStack.pop();
    }

    cout << "Postfix Expression: ";
    while (!outputQueue.empty())
    {
        cout << outputQueue.front() << " ";
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
