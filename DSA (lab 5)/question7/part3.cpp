#include <iostream>
using namespace std;
int Fibonacci_series(int num)
{
    if (num <= 1)
    {
        return num;
    }
    int a = 0, b = 1;
    for (int i = 2; i <= num; i++)
    {
        int temp = a;
        a = b;
        b = temp + b;
    }
    return b;
}

int main()
{
    int result = Fibonacci_series(10);
    cout << result << endl;
    return 0;
}
