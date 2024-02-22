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
    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        return buildBST(nums, 0, nums.size() - 1);
    }

    TreeNode *buildBST(std::vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }
};
