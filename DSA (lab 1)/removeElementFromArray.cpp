#include <iostream>
#include <vector>
using namespace std;

class RemoveNumbers
{
public:
    int findSame(vector<int> &nums, int val)
    {
        vector<int> newVector;

        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            if (a != val)
            {
                newVector.push_back(a);
            }
        }
        for (int i = 0; i < newVector.size(); i++)
        {
            cout << newVector[i] << "    ";
        }

        return (newVector.size());
    }
};

int main()
{
    RemoveNumbers o1;
    vector<int> a{3, 2, 2, 3};
    cout << o1.findSame(a, 3);
    return 0;
}
