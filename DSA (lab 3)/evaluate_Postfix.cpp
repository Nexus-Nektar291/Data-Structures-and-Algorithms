#include <iostream>
#include <stack>
#include "infix_to_postfix.h"

using namespace std;

int evaluatePostfix(string s)
{
    stack<int> st;
    for (char c : s)
    {
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        else
        {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            int rs = 0;

            if (c == '+')
            {
                rs = num1 + num2;
            }
            else if (c == '-')
            {
                rs = num1 - num2;
            }
            else if (c == '*')
            {
                rs = num1 * num2;
            }
            else if (c == '/')
            {
                if (num2 == 0)
                {
                    cout << "Division with 0 not possible ! " << endl;
                    return 0;
                }
                rs = num1 / num2;
            }
            st.push(rs);
        }
    }
    return st.top();
}

int main()
{
    string infixExpr = "(2+5)*3+2";
    string postfixExpr = infix_to_postfix(infixExpr);
    cout << "Infix Expression: " << infixExpr << endl;
    cout << "Prefix Expression: " << postfixExpr << endl;
    cout << "Result: " << evaluatePostfix(postfixExpr) << endl;
    return 0;
}
