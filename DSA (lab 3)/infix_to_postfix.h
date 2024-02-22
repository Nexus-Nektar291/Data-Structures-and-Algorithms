#include <iostream>
#include <stack>

using namespace std;

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    return 0;
}

string infix_to_postfix(const string &s)
{
    stack<char> st;
    string rs = "";

    for (char c : s)
    {
        if (isdigit(c))
        {
            rs += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                rs += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                rs += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        rs += st.top();
        st.pop();
    }

    return rs;
}
