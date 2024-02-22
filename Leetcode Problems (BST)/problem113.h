
#include <vector>

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> result;
        vector<int> currentPath;
        pathSumHelper(root, targetSum, result, currentPath);
        return result;
    }

    void pathSumHelper(TreeNode *root, int targetSum, vector<vector<int>> &result, vector<int> &currentPath)
    {
        if (root == nullptr)
        {
            return;
        }

        currentPath.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr && targetSum == root->val)
        {
            result.push_back(currentPath);
        }
        else
        {
            pathSumHelper(root->left, targetSum - root->val, result, currentPath);
            pathSumHelper(root->right, targetSum - root->val, result, currentPath);
        }

        currentPath.pop_back();
    }
};
