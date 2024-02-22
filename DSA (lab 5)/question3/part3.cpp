#include <iostream>
using namespace std;

int calMid(int si, int ei)
{
    return (si + ei) / 2;
}

int search(int si, int ei, int num, int arr[])
{
    int mid = calMid(si, ei);
    if (arr[mid] == num)
    {
        return mid;
    }
    else if (arr[mid] < num)
    {
        si = mid + 1;
    }
    else if (arr[mid] > num)
    {
        ei = mid - 1;
    }
    return search(si, ei, num, arr);
}

int main()
{
    int arr[] = {2, 5, 8, 9, 10, 12, 14, 23, 25, 28, 35, 36, 38, 49, 59, 62, 73, 92, 99};
    cout << search(0, 18, 62, arr) << endl;
    return 0;
}