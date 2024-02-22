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
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        while (root != nullptr)
        {
            if (root->left != nullptr)
            {
                TreeNode *rightMost = root->left;
                while (rightMost->right != nullptr)
                {
                    rightMost = rightMost->right;
                }
                rightMost->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
