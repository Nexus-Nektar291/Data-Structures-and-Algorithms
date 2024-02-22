#include <iostream>
#include <deque>
using namespace std;
class FrontMiddleBackQueue
{
public:
    deque<int> d1, d2;
    int n1, n2;
    FrontMiddleBackQueue()
    {
        n1 = n2 = 0;
    }

    void pushFront(int val)
    {
        d1.push_front(val);
        if (n1 == n2)
        {
            n1++;
        }
        else
        {
            d2.push_front(d1.back());
            d1.pop_back();
            n2++;
        }
    }

    void pushMiddle(int val)
    {
        if (n1 == n2)
        {
            d1.push_back(val);
            n1++;
        }
        else
        {
            d2.push_front(d1.back());
            d1.pop_back();
            d1.push_back(val);
            n2++;
        }
    }

    void pushBack(int val)
    {
        d2.push_back(val);
        if (n2 < n1)
        {
            n2++;
        }
        else
        {
            d1.push_back(d2.front());
            d2.pop_front();
            n1++;
        }
    }

    int popFront()
    {
        if (n1 == 0 && n2 == 0)
        {
            return -1;
        }
        int ans = d1.front();
        d1.pop_front();
        n1--;
        if (n1 < n2)
        {
            d1.push_back(d2.front());
            d2.pop_front();
            n2--;
            n1++;
        }
        return ans;
    }

    int popMiddle()
    {
        if (n1 == 0 && n2 == 0)
        {
            return -1;
        }
        int ans = d1.back();
        d1.pop_back();
        n1--;
        if (n1 < n2)
        {
            d1.push_back(d2.front());
            d2.pop_front();
            n2--;
            n1++;
        }
        return ans;
    }

    int popBack()
    {
        if (n1 == 0 && n2 == 0)
        {
            return -1;
        }
        if (n2 == 0)
        {
            int ans = d1.back();
            d1.pop_back();
            n1--;
            return ans;
        }

        int ans = d2.back();
        d2.pop_back();
        n2--;
        if (n2 + 1 < n1)
        {
            d2.push_front(d1.back());
            d1.pop_back();
            n2++;
            n1--;
        }
        return ans;
    }
};

int main()
{
    FrontMiddleBackQueue q;
    q.pushFront(4);
    q.pushMiddle(6);
    q.pushBack(5);
    cout << "Pop middle : " << q.popMiddle() << endl;
    q.pushMiddle(7);
    cout << "Pop middle : " << q.popMiddle() << endl;
    q.pushFront(9);
    q.pushMiddle(3);
    q.pushBack(0);
    cout << "Pop back : " << q.popBack() << endl;
    cout << "Pop front : " << q.popFront() << endl;
    cout << "Pop middle : " << q.popMiddle() << endl;

    return 0;
}