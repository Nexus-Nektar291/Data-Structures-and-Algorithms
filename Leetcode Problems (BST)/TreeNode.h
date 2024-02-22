#pragma once
#include <iostream>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val = NULL)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};
