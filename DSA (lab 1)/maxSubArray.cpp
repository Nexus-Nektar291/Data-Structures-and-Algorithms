#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class MaxSubArray
{
public:
    int findMax(vector<int> &nums)
    {
        int maxSum = INT_MIN;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            currSum = max(currSum + nums[i], nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
int main()
{
    MaxSubArray o1;
    vector<int> nums = {-1};
    cout << o1.findMax(nums);
    return 0;
}