#include <iostream>
using namespace std;

int search(int ei, int num, int arr[])
{
    if (arr[ei] == num)
    {
        return ei;
    }
    return search(ei - 1, num, arr);
}

int main()
{
    int arr[] = {2, 5, 8, 9, 43};
    cout << search(4, 9, arr) << endl;
    return 0;
}