#include <iostream>
#include <stack>

using namespace std;

string decodeString(string s)
{
    stack<string> stringStack;
    stack<int> numberStack;
    string ans = "";
    int num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num = 10 * num + s[i] - '0';
        }
        else if (s[i] == '[')
        { 
            stringStack.push(ans);
            ans = "";
            numberStack.push(num);
            num = 0;
        }
        else if (s[i] == ']')
        { 
            string temp = ans;
            ans = stringStack.top();
            stringStack.pop();
            int times = numberStack.top();
            numberStack.pop();
            while (times--)
            {
                ans += temp;
            }
        }
        else
        { 
            ans += s[i];
        }
    }
    return ans;
}

int main()
{
    string s = "9[leetcode]";
    cout << decodeString(s);
    return 0;
}