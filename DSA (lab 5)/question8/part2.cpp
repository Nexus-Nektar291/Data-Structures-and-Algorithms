#include <iostream>
using namespace std;
int TriSum(int n)
{
    if (n == 0)
        return 0;
    if (n <= 3)
        return n;
    return TriSum(n - 1) + TriSum(n - 2) + TriSum(n - 3);
}

int main()
{
    int result = TriSum(10);
    cout << result << endl;
    return 0;
}
