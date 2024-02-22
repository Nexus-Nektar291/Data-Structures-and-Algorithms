#include <iostream>
#include <stack>
// #include<string>
using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> mystack;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            mystack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (mystack.empty())
            {
                return false;
            }

            char top = mystack.top();
            if (top == '(' && c != ')' || top == '[' && c != ']' || top == '{' && c != '}')
            {
                return false;
            }
            mystack.pop();
        }
    }
    if (mystack.empty())
        return true;
    return false;
}

int main()
{
    cout << isValidParenthesis("{([]])}") << endl;
    return 0;
}