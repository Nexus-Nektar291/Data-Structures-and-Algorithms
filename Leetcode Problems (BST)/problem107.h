#include <vector>
#include <queue>

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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root)
    {
        std::vector<std::vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }

        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            std::vector<int> level;

            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }

            result.insert(result.begin(), level);
        }

        return result;
    }
};
