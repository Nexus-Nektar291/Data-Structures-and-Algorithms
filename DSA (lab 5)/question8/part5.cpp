#include <iostream>
#include <vector>
using namespace std;
vector<int> myVec;
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

    myVec[0] = 0;
    myVec[1] = 1;
    myVec[2] = 2;
    myVec[3] = 3;

    for (int i = 4; i <= n; i++)
    {
        myVec[i] = myVec[i - 1] + myVec[i - 2] + myVec[i - 3];
    }

    return myVec[n];
}

int main()
{
    int n = 10;
    myVec.resize(n + 1);
    int result = TriSum(n);
    cout << result << endl;
    return 0;
}
