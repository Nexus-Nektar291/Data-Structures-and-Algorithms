class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
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

        while (levelStart != nullptr)
        {
            Node *current = levelStart;
            Node *dummy = new Node(0);
            Node *tail = dummy;

            while (current != nullptr)
            {
                if (current->left != nullptr)
                {
                    tail->next = current->left;
                    tail = tail->next;
                }
                if (current->right != nullptr)
                {
                    tail->next = current->right;
                    tail = tail->next;
                }
                current = current->next;
            }

            levelStart = dummy->next;
        }

        return root;
    }
};
