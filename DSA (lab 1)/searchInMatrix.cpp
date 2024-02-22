#include <iostream>
#include <vector>
using namespace std;
class SearchInMatrix
{
public:
    bool search(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int si = 0;
        int ei = rows * cols - 1;
        while (si <= ei)
        {
            int mid = (si + ei) / 2;
            int midvalue = matrix[mid / cols][mid % cols];
            if (midvalue == target)
            {
                return true;
            }
            else if (midvalue < target)
            {
                si = mid + 1;
            }
            else
            {
                ei = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    SearchInMatrix o1;
    int target = 16;
    cout << o1.search(matrix, target);

    return 0;
}