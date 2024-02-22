#include <iostream>
#include <vector>
using namespace std;

class SmallerNumbers
{
public:
    vector<int> findSmall(vector<int> &nums)
    {
        vector<int> newVector(nums.size(), 0);
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            for (int j = 0; j < nums.size(); j++)
            {
                if (a > nums[j])
                {
                    count++;
                }
            }
            newVector[i] = count;
            cout << count;
            count = 0;
        }
        return newVector;
    }
};
int main()
{
    SmallerNumbers o1;
    vector<int> a{5, 9, 4, 3, 12,3};
    o1.findSmall(a);
    return 0;
}
