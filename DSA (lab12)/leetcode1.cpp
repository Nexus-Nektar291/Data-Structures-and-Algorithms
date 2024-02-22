#include <iostream>
#include <cmath>
#include <vector>
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
class Solution
{
public:
    Node *root;
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