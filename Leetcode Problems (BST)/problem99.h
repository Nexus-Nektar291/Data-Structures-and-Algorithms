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
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, nullptr, nullptr);
    }

    bool isValidBST(TreeNode *root, TreeNode *minNode, TreeNode *maxNode)
    {
        if (root == nullptr)
        {
            return true;
        }

        if ((minNode != nullptr && root->val <= minNode->val) || (maxNode != nullptr && root->val >= maxNode->val))
        {
            return false;
        }

        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};
