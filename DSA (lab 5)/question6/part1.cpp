#include <iostream>
using namespace std;
int divide(int a, int b)
{
    if (a < b)
    {
        return 0;
    }

    return 1 + divide(a - b, b);
}

int main()
{
    int num1 = 25;
    int num2 = 5;

    int result = divide(num1, num2);
    cout << result << endl;

    return 0;
}
