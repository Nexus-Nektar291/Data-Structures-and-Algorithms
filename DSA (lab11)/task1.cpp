#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

void generate_randomNumbers(vector<int> V)
{
    for (int i = 0; i < V.size(); i++)
    {
        V[i] = rand() % 100;
    }
}

void bubblesort(vector<int> v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}
void bucketSort(vector<int> v, int n)
{
    vector<vector<int>> b(n);

    for (int i = 0; i < n; i++)
    {
        int bi = n * v[i];
        b[bi].push_back(v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sort(b[i].begin(), b[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            v[index++] = b[i][j];
        }
    }
}
void countSort(vector<int> &inputArray)
{
    int N = inputArray.size();
    int M = 0;
    for (int i = 0; i < N; i++)
    {
        M = max(M, inputArray[i]);
    }
    vector<int> countArray(M + 1, 0);
    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];
    vector<int> outputArray(N);

    for (int i = N - 1; i >= 0; i--)
    {
        outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
        countArray[inputArray[i]]--;
    }
    for (int i = 0; i < N; i++)
        inputArray[i] = outputArray[i];
}

class MergeSort
{
public:
    void sort(vector<int> &arr, int size)
    {
        if (size > 1)
        {
            int halfsize = size / 2;
            vector<int> arr1(halfsize);
            vector<int> arr2(size - halfsize);

            for (int i = 0; i < halfsize; i++)
            {
                arr1[i] = arr[i];
            }

            for (int i = 0; i < size - halfsize; i++)
            {
                arr2[i] = arr[i + halfsize];
            }

            sort(arr1, halfsize);
            sort(arr2, size - halfsize);
            Merge(arr, arr1, arr2, halfsize, size - halfsize);
        }
    }

    void Merge(vector<int> &arr, vector<int> &arr1, vector<int> &arr2, int size1, int size2)
    {
        int i = 0, j = 0, k = 0;
        while (i < size1 && j < size2)
        {
            if (arr1[i] <= arr2[j])
            {
                arr[k] = arr1[i];
                i++;
            }
            else
            {
                arr[k] = arr2[j];
                j++;
            }
            k++;
        }

        while (i < size1)
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }

        while (j < size2)
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
};
class HeapSort
{
public:
    void heapify(vector<int> &arr, int N, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < N && arr[l] > arr[largest])
            largest = l;
        if (r < N && arr[r] > arr[largest])
            largest = r;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, N, largest);
        }
    }

    void heapSort(vector<int> &arr, int N)
    {
        for (int i = N / 2 - 1; i >= 0; i--)
            heapify(arr, N, i);
        for (int i = N - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};
class Insertion_Sort
{
public:
    void sortArray(vector<int> arr, int size)
    {
        int temp;
        for (int i = 1; i < size; i++)
        {
            temp = arr[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[j] > temp)
                {
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
                else
                {
                    arr[j + 1] = temp;
                    break;
                }
            }
        }
    }
};
class Selection_Sort
{
public:
    void sortArray(vector<int> arr, int size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            int *temp;
            int min = arr[i];
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < min)
                {
                    min = arr[j];
                    temp = &arr[j];
                }
            }
            if (min != arr[i])
            {
                *temp = arr[i];
                arr[i] = min;
            }
        }
    }
};
int main()
{
    system("clear");
    double size = 1024*100;
    vector<int> v(size);
    generate_randomNumbers(v);
    // cout << "Bucket Sort...." << endl;
    // cout << "Counting Sort...." << endl;
    cout << "Heap Sort...." << endl;
    // cout << "Bubble Sort...." << endl;
    // cout << "Insertion Sort...." << endl;
    // cout << "Selection Sort...." << endl;
    // cout << "Merge Sort...." << endl;
    cout << "Before Sorting :" << time(0) << "\n";
    // Selection_Sort s;
    // s.sortArray(v, v.size());
    // Insertion_Sort s;
    // s.sortArray(v, v.size());
    // bubblesort(v);
    HeapSort s;
    s.heapSort(v, v.size());
    // countSort(v);
    // MergeSort s;
    // s.sort(v, v.size());
    // bubblesort(V);
    // bucketSort(v, v.size());
    cout << "After Sorting :" << time(0) << "\n";

    return 0;
}