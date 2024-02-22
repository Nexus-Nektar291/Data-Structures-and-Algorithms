#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        stack<int> st;
        queue<int> qu;

        for (int i = 0; i < students.size() - 1; i++)
        {
            qu.push(students[i]);
            st.push(sandwiches[sandwiches.size() - 1 - i]);
        }
    }
};

int main()
{
    vector<int> student{1, 1, 1, 0, 0, 1};
    vector<int> sandwich{1, 0, 0, 0, 1, 1};
    Solution s;
    cout << s.countStudents(student, sandwich) << endl;
    return 0;
}