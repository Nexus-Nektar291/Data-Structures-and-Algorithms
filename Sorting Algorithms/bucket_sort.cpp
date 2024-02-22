#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort(vector<float> &bucket)
{
    int n = bucket.size();
    for (int i = 1; i < n; ++i)
    {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j = j - 1;
        }
        bucket[j + 1] = key;
    }
}

void bucketSort(vector<float> &arr)
{
    int n = arr.size();

    vector<vector<float>> buckets(n);

    for (int i = 0; i < n; ++i)
    {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < buckets[i].size(); ++j)
        {
            arr[index++] = buckets[i][j];
        }
    }
}

int main()
{
    vector<float> arr = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};

    cout << "Original array: ";
    for (float num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    bucketSort(arr);

    cout << "Sorted array: ";
    for (float num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
