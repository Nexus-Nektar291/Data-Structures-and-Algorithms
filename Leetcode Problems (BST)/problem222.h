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
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        if (leftHeight == rightHeight)
        {
            return (1 << leftHeight) - 1; // 2^h - 1
        }
        else
        {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }

    int getLeftHeight(TreeNode *root)
    {
        int height = 0;
        while (root != nullptr)
        {
            height++;
            root = root->left;
        }
        return height;
    }

    int getRightHeight(TreeNode *root)
    {
        int height = 0;
        while (root != nullptr)
        {
            height++;
            root = root->right;
        }
        return height;
    }
};
