#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> result;
    void inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        TreeNode *temp = root;

        while (temp != nullptr || !s.empty())
        {
            while (temp != nullptr)
            {
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            result.push_back(temp->val);
            temp = temp->right;
        }

        display();
    }
    void display()
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << "\t";
        }
        cout << endl;
    }
};
