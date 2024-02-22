#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;

    while (left < right)
    {
        int length = right - left;
        int currentArea = min(height[left], height[right]) * length;
        maxArea = max(maxArea, currentArea);

        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return maxArea;
}

int main()
{
    vector<int> height{2, 4, 8, 3, 7,3};
    cout << maxArea(height) << endl;
    return 0;
}
