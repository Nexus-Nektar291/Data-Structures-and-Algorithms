#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    int value;
    int height;
    Node *left;
    Node *right;
    Node(int data)
    {
        value = data;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVL
{
private:
    Node *root;

public:
    AVL()
    {
        root = nullptr;
    }

    void InsertInAVL(Node *&node, int value)
    {
        if (node == nullptr)
        {
            Node *new_node = new Node(value);
            node = new_node;
            return;
        }
        if (value < node->value)
        {
            InsertInAVL(node->left, value);
        }
        else if (value > node->value)
        {
            InsertInAVL(node->right, value);
        }
        else
        {
            return;
        }
        node->height = getHeight(node);
        int balance = getBalance(node);
        if (balance > 1 && value < node->left->value)
        {
            RightRotate(node);
        }
        else if (balance < -1 && value > node->right->value)
        {
            LeftRotate(node);
        }
        else if (balance > 1 && value > node->left->value)
        {
            LeftRotate(node->left);
            RightRotate(node);
        }
        else if (balance < -1 && value < node->right->value)
        {
            RightRotate(node->right);
            LeftRotate(node);
        }
    }

    void DeleteInAVL(Node *&node, int value)
    {
        if (node == nullptr)
        {
            return;
        }
        else if (value < node->value)
        {
            DeleteInAVL(node->left, value);
        }
        else if (value > node->value)
        {
            DeleteInAVL(node->right, value);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                node = temp;
                return;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                node = temp;
                return;
            }
            else
            {
                Node *temp = node->right;
                while (temp->left != nullptr)
                {
                    temp = temp->left;
                }

                node->value = temp->value;
                DeleteInAVL(node->right, temp->value);
            }
        }
        node->height = getHeight(node);
        int balance = getBalance(node);
        if (balance > 1 && getBalance(node->left) >= 0)
        {
            RightRotate(node);
        }
        else if (balance < -1 && getBalance(node->right) >= 0)
        {
            LeftRotate(node);
        }
        else if (balance > 1 && getBalance(node->left) < 0)
        {
            LeftRotate(node->left);
            RightRotate(node);
        }
        else if (balance < -1 && getBalance(node->right) > 0)
        {
            RightRotate(node->right);
            LeftRotate(node);
        }
    }

    void RightRotate(Node *&n)
    {
        Node *temp1 = n->left;
        Node *temp2 = temp1->right;

        temp1->right = n;
        n->left = temp2;

        n->height = getHeight(n);
        temp1->height = getHeight(temp1);

        n = temp1;
    }

    void LeftRotate(Node *&n)
    {
        Node *temp1 = n->right;
        Node *temp2 = temp1->left;

        temp1->left = n;
        n->right = temp2;

        n->height = getHeight(n);
        temp1->height = getHeight(temp1);

        n = temp1;
    }

    int getBalance(Node *N)
    {
        if (N == nullptr)
        {
            return 0;
        }
        int left = getHeight(N->left);
        int right = getHeight(N->right);
        return left - right;
    }

    bool isBalanced(Node *N)
    {
        if (N == nullptr)
        {
            return true;
        }
        int left = getHeight(N->left);
        int right = getHeight(N->right);
        int val = abs(left - right);
        if (val == 1 || val == 0)
            return true;
    }

    int getHeight(Node *N)
    {
        if (N == nullptr)
        {
            return 0;
        }
        int left = getHeight(N->left);
        int right = getHeight(N->right);
        return 1 + max(left, right);
    }

    int HeightDifference(Node *N)
    {
        if (N == nullptr)
        {
            return 0;
        }
        int left = getHeight(N->left);
        int right = getHeight(N->right);
        return (right - left);
    }

    void InOrder(Node *root)
    {
        if (root != NULL)
        {
            InOrder(root->left);
            cout << root->value << " ";
            InOrder(root->right);
        }
    }

    Node *&getroot()
    {
        return root;
    }
};

main()
{
    AVL a;
    a.InsertInAVL(a.getroot(), 2);
    a.InsertInAVL(a.getroot(), 3);
    a.InsertInAVL(a.getroot(), 7);
    a.InsertInAVL(a.getroot(), 8);
    a.InsertInAVL(a.getroot(), 6);

    a.InOrder(a.getroot());
    cout << "Endl" << endl;
    a.DeleteInAVL(a.getroot(), 3);

    a.InOrder(a.getroot());
}