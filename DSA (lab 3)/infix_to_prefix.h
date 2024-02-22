#include <iostream>
#include <stack>

using namespace std;

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    return 0;
}

string infix_to_prefix(const string &s)
{
    stack<char> st;
    string rs = "";
    string reverse_string = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
        {
            reverse_string += ')';
        }
        else if (s[i] == ')')
        {
            reverse_string += '(';
        }
        else
            reverse_string += s[i];
    }

    for (char c : reverse_string)
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
    string fs = "";
    for (int i = rs.length() - 1; i >= 0; i--)
    {
        fs += rs[i];
    }
    return fs;
}
