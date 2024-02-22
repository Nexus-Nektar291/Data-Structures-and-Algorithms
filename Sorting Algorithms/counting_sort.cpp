#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int> &arr)
{
    int n = arr.size();

    int maxElement = *max_element(arr.begin(), arr.end());

    vector<int> count(maxElement + 1, 0);

    for (int i = 0; i < n; ++i)
        count[arr[i]]++;

    for (int i = 1; i <= maxElement; ++i)
        count[i] += count[i - 1];

    vector<int> output(n);

    for (int i = n - 1; i >= 0; --i)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

int main()
{
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    countingSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
