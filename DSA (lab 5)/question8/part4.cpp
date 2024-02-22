#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;

int TriSum(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n <= 3)
    {
        return n;
    }
    if (vec[n] != -1)
    {
        return vec[n];
    }
    return vec[n] = TriSum(n - 1) + TriSum(n - 2) + TriSum(n - 3);
}

int main()
{
    int n = 20;
    vec.resize(n + 1, -1);
    int result = TriSum(n);
    cout << result << endl;
    return 0;
}
