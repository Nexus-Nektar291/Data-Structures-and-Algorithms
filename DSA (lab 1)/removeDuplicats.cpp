#include <iostream>
#include <vector>
using namespace std;
class RemoveDuplicates
{
public:
    int findDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                i++;
            }
            nums[i] = nums[j];
        }
        return i + 1;
    }
};

int main()
{
    vector<int> nums = {0, 2, 2, 5, 7, 9, 9, 10};
    RemoveDuplicates o1;
    cout << o1.findDuplicates(nums);
    return 0;
}