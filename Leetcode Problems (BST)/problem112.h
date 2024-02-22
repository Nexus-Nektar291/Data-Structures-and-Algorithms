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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr && targetSum - root->val == 0)
        {
            return true;
        }
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
