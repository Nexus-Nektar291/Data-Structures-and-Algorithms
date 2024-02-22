#include <iostream>
#include <vector>
using namespace std;

void Subarrays(const vector<int> &arr, int index, vector<int> &current, vector<vector<int>> &result)
{
    if (index == arr.size())
    {
        result.push_back(current);
        return;
    }
    Subarrays(arr, index + 1, current, result);
    current.push_back(arr[index]);
    Subarrays(arr, index + 1, current, result);
    current.pop_back();
}

void display(const vector<int> &arr)
{
    vector<int> current;
    vector<vector<int>> result;
    Subarrays(arr, 0, current, result);

    for (const vector<int> &subarray : result)
    {
        cout << "(";
        for (int num : subarray)
        {
            cout << num << "";
        }
        cout << ")";
    }
    cout << endl;
}

int main()
{
    vector<int> input = {1, 2, 3};
    display(input);

    return 0;
}
