#include <iostream>
#include <string>
#include <stack>

using namespace std;

string decodeString(string s)
{
    string n = "";
    string temp = "";
    string finalstring = "";
    stack<string> myStack;
    for (int i = (s.length() - 1); i >= 0; i--)
    {
        if (s[i] != '[')
        {
            myStack.push(string(1, s[i]));
        }
        else
        {
            while (myStack.top() != "]")
            {
                temp += myStack.top();
                myStack.pop();
            }
            myStack.pop();
            i--;

            int size = stoi(string(1, s[i]));

            for (int j = 0; j < size; j++)
            {
                n.append(temp);
            }
            myStack.push(n);
            // finalstring = n;
            temp = "";
            n = "";
        }
    }
    if (!myStack.empty())
    {
        finalstring = myStack.top() + finalstring;
        myStack.pop();
    }

    return finalstring;
}

int main()
{
    cout << decodeString("2[a2[b]]e");
    return 0;
}