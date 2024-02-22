#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> st;
    MinStack()
    {
    }
    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            int k = st.top().second;
            if (k < val)
            {
                st.push({val, k});
            }
            else
            {
                st.push({val, val});
            }
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

int main()
{
    MinStack s;
    s.push(-4);
    s.push(3);
    s.push(2);
    cout << "Top : " << s.top() << endl;
    cout << "Minimum : " << s.getMin() << endl;
    s.push(-5);
    s.push(10);
    cout << "Top : " << s.top() << endl;
    cout << "Minimum : " << s.getMin() << endl;

    return 0;
}