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
    std::vector<int> postorderTraversal(TreeNode *root)
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
            result.insert(result.begin(), node->val);

            if (node->left != nullptr)
            {
                st.push(node->left);
            }
            if (node->right != nullptr)
            {
                st.push(node->right);
            }
        }

        return result;
    }
};
