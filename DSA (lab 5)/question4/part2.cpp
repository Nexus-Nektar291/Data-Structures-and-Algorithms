#include <iostream>
using namespace std;
int power(int x, int y, int m)
{
    if (y == 0)
    {
        return 1;
    }
    else if (y % 2 == 0)
    {
        int half_power = power(x, y / 2, m);
        return (half_power * half_power) % m;
    }
    else
    {
        int half_power = power(x, y / 2, m);
        return (x * half_power * half_power) % m;
    }
}

int main()
{
    int result = power(3, 5, 7);
    cout << result << endl;
    return 0;
}
