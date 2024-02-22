#include <iostream>
using namespace std;

void merge(int arr[], int arr1[], int arr2[], int si, int ei)
{
    int i, j, k;
    i = j = k = 0;
    while (i < si && j < ei)
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
    while (i < si)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < ei)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[], int size)
{
    if (size > 1)
    {

        int halfsize = size / 2;
        int *arr1 = new int[size];
        int *arr2 = new int[halfsize];
        for (int i = 0; i < halfsize; i++)
        {
            arr1[i] = arr[i];
        }

        for (int i = 0; i < size - halfsize; i++)
        {
            arr2[i] = arr[i + halfsize];
        }
        merge_sort(arr1, halfsize);
        merge_sort(arr2, size - halfsize);
        merge(arr, arr1, arr2, halfsize, size - halfsize);
    }
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = 10;
    cout << endl;
    merge_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
    return 0;
}