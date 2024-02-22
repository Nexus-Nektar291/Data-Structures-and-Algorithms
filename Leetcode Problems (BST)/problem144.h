#include <vector>
#include <stack>

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
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        std::vector<int> result;
        if (root == nullptr)
        {
            return result;
        }

        std::stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            result.push_back(node->val);

            if (node->right != nullptr)
            {
                st.push(node->right);
            }
            if (node->left != nullptr)
            {
                st.push(node->left);
            }
        }

        return result;
    }
};
