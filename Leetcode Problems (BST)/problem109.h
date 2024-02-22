class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == nullptr)
        {
            return new TreeNode(head->val);
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev != nullptr)
        {
            prev->next = nullptr;
        }

        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
