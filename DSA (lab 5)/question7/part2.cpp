#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;

int fibonacci_series(int n)
{
    if (n <= 1)
    {
        return n;
    }
    if (vec[n] != -1)
    {
        return vec[n];
    }
    return vec[n] = fibonacci_series(n - 1) + fibonacci_series(n - 2);
}

int main()
{
    int n = 20;
    vec.resize(n + 1, -1);
    int result = fibonacci_series(n);
    cout << "Fibonacci(" << n << ") = " << result << endl;
    return 0;
}
