#include <iostream>
#include <queue>

using namespace std;

class StackUsingQueue
{
public:
    queue<int> myQueue;
    void push(int x)
    {
        myQueue.push(x);
        for (int i = 0; i < myQueue.size() - 1; i++)
        {
            myQueue.push(myQueue.front());
            myQueue.pop();
        }
    }
    int pop()
    {
        int k = myQueue.front();
        myQueue.pop();
        return k;
    }
    int top()
    {
        return myQueue.front();
    }
    bool empty()
    {
        return myQueue.empty();
    }
};

int main()
{
    StackUsingQueue s;
    s.push(5);
    s.push(4);
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.empty() << endl;
    cout << s.pop() << endl;
    cout << s.empty() << endl;
    return 0;
}