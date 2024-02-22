#include <iostream>
using namespace std;

int search(int si, int num, int arr[])
{
    if (arr[si] == num)
    {
        return si;
    }
    return search(si + 1, num, arr);
}

int main()
{
    int arr[] = {2, 5, 8, 9, 43};
    cout << search(0, 9, arr) << endl;
    return 0;
}