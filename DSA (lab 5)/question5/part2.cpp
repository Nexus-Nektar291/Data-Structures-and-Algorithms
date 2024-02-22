#include <iostream>
using namespace std;

int multiply(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    else if (a % 2 == 1)
    {
        return b + multiply(a / 2, b * 2);
    }
    else
    {
        return multiply(a / 2, b * 2);
    }
}

int main()
{
    int x = 4;
    int y = 8;
    cout << multiply(x, y) << endl;

    return 0;
}
