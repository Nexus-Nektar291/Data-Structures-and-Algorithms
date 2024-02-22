#include <iostream>
using namespace std;

int fibonacci_series(int num)
{
    if (num < 2)
    {
        return num;
    }
    return fibonacci_series(num - 1) + fibonacci_series(num - 2);
}

int main()
{
    cout << fibonacci_series(0) << endl;
    return 0;
}