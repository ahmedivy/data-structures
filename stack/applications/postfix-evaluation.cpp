#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string postFix);

int main()
{
    string postFix = "6523+8*+3+*";
    cout << evaluatePostfix(postFix) << endl;
    return 0;
}

int evaluatePostfix(string postFix)
{
    stack<int> st;
    int op1, op2;
    for (int i = 0; i < postFix.length(); i++)
    {
        if (postFix[i] >= '0' && postFix[i] <= '9')
        {
            st.push(postFix[i] - '0');
        }
        else
        {
            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();
            switch (postFix[i])
            {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
                default:
                    break;
            }
        }
    }
    return st.top();
}