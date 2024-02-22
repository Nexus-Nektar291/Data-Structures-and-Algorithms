#include <cmath>
#include <math.h>
#include <algorithm>
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
    int max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        return b;
    }
    int getHeight(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        int m = abs(l - r);
        if (m == 1 || m == 0)
        {
            return true;
        }
        return false;
    }
};
