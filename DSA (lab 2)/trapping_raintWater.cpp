#include <iostream>
#include <vector>

using namespace std;

int rainWater(vector<int> height)
{
    int size = height.size();
    int *left = new int[size];
    left[0] = height[0];
    int *right = new int[size];
    right[size - 1] = height[size - 1];
    for (int i = 1; i < size; i++)
    {
        left[i] = max(left[i - 1], height[i]);
    }
    for (int i = size - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], height[i]);
    }

    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans += min(left[i], right[i]) - height[i];
    }
    return ans;
}

int main()
{
    vector<int> vec{4, 5, 3, 3, 2, 5, 9};
    cout << rainWater(vec);
    return 0;
}
