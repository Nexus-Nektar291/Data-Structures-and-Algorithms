class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        Node *levelStart = root;

        while (levelStart->left != nullptr)
        {
            Node *curr = levelStart;

            while (curr != nullptr)
            {
                curr->left->next = curr->right;
                if (curr->next != nullptr)
                {
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }

            levelStart = levelStart->left;
        }

        return root;
    }
};
