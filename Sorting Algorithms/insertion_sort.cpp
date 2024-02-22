#include <iostream>
using namespace std;
class Insertion_Sort
{
public:
    void sortArray(int arr[], int size)
    {
        int count = 0;
        int temp;
        for (int i = 1; i < size; i++)
        {
            temp = arr[i];
            for (int j = i - 1; j >= 0; j--)
            {
                count++;
                if (arr[j] > temp)
                {
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
                else
                {
                    break;
                }
            }
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "    ";
        }
        cout << endl;
        cout << "Count is : " << count << endl;
    }
};

int main()
{
    // int arr[] = {12, 9, 4, 2, 6, 17, 1, 3, 10, 5};
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = 10;
    Insertion_Sort i;
    i.sortArray(arr, size);
    return 0;
}