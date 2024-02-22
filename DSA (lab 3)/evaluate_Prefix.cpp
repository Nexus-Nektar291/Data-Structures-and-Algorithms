#include <iostream>
#include <stack>
#include "infix_to_prefix.h"

using namespace std;

int evaluatePrefix(string c)
{
    stack<int> st;

    for (int i = c.length() - 1; i >= 0; i--)
    {
        if (isdigit(c[i]))
        {
            st.push(c[i] - '0');
        }
        else
        {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            int result = 0;

            if (c[i] == '+')
            {
                result = num1 + num2;
            }
            else if (c[i] == '-')
            {
                result = num1 - num2;
            }
            else if (c[i] == '*')
            {
                result = num1 * num2;
            }
            else if (c[i] == '/')
            {
                if (num2 == 0)
                {
                    cout << "Division with 0 not possible ! " << endl;
                    return 0;
                }
                result = num1 / num2;
            }

            st.push(result);
        }
    }

    return st.top();
}

int main()
{
    string infixExpr = "(2+5)*3+2";
    string prefixExpr = infix_to_prefix(infixExpr);
    cout << "Infix Expression: " << infixExpr << endl;
    cout << "Prefix Expression: " << prefixExpr << endl;
    cout << "Result: " << evaluatePrefix(prefixExpr) << endl;

    return 0;
}
