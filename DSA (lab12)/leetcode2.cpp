#include <iostream>
#include <math.h>
#include <unistd.h>
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
    Node *balanceBST(Node *root)
    {
        vector<int> sortedValues;
        inOrderTraversal(root, sortedValues);

        return buildBalancedBST(sortedValues, 0, sortedValues.size() - 1);
    }
    void inOrderTraversal(Node *root, vector<int> &values)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrderTraversal(root->left, values);
        values.push_back(root->value);
        inOrderTraversal(root->right, values);
    }

    Node *buildBalancedBST(vector<int> &values, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        Node *root = new Node(values[mid]);

        root->left = buildBalancedBST(values, start, mid - 1);
        root->right = buildBalancedBST(values, mid + 1, end);

        return root;
    }
};