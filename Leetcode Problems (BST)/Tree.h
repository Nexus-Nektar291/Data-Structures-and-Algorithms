#pragma once
#include "TreeNode.h"
#include <iostream>
#include <vector>
using namespace std;

class Tree
{
public:
    TreeNode *root;
    Tree()
    {
        root = nullptr;
    }
    void insertion_input()
    {
        int size = 0;
        cout << " Enter the number of nodes: ";
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            int value;
            cout << " Enter value you want to insert : ";
            cin >> value;
            insert(value);
        }
    }
    void insert(int data)
    {
        TreeNode *node = new TreeNode(data);
        if (root == nullptr)
        {
            root = node;
        }
        else
            place_child(root, node);
    }
    void place_child(TreeNode *current, TreeNode *child)
    {
        if (current->val >= child->val && current->left == nullptr)
        {
            current->left = child;
            return;
        }
        else if (current->val <= child->val && current->right == nullptr)
        {
            current->right = child;
            return;
        }
        else if (current->val >= child->val && current->left != nullptr)

        {
            return place_child(current->left, child);
        }
        else
        {
            return place_child(current->right, child);
        }
        return;
    }
};