#include <iostream>
using namespace std;
int memo[10000];

int divide(int A, int B)
{
    if (A == 0)
        return 0;
    if (memo[A] != 0)
        return memo[A];
    if (A < B)
        return 0;
    if (A == B)
        return 1;
    if (A > B)
    {
        int result = 1 + divide(A - B, B);
        memo[A] = result;
        return result;
    }

    return 0;
}

int main()
{
    int A = 10;
    int B = 2;

    int result = divide(A, B);
    cout << "A / B = " << result << endl;

    return 0;
}
