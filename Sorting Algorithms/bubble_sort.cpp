#include <iostream>
using namespace std;

class Bubble_Sort
{
public:
    void sortArray(int arr[], int size)
    {
        int count = 0;
        for (int i = 0; i < size - 1; i++)
        {
            bool flag = true;
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    flag = false;
                }
                count++;
            }
            if (flag)
            {
                break;
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
    cout << endl;
    Bubble_Sort b;
    b.sortArray(arr, size);
    return 0;
}