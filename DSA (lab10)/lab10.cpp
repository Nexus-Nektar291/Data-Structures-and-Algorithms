#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class BinarySearchTree
{
public:
    Node<T> *root;
    BinarySearchTree()
    {
        root = nullptr;
    }

    void InsertInBST(T data, Node<T> *&node)
    {
        if (node == nullptr)
        {
            Node<T> *newNode = new Node<T>(data);
            node = newNode;
        }

        else if (data < node->data)
        {
            InsertInBST(data, node->left);
        }
        else
        {
            return InsertInBST(data, node->right);
        }
    }

    void PrintTreePreOrder(Node<T> *node)
    {
        if (node != nullptr)
        {
            cout << node->data << "  ";
            PrintTreePreOrder(node->left);
            PrintTreePreOrder(node->right);
        }
    }
    void PrintTreePostOrder(Node<T> *node)
    {
        if (node != nullptr)
        {
            PrintTreePostOrder(node->left);
            PrintTreePostOrder(node->right);
            cout << node->data << "  ";
        }
    }
    void PrintTreeInOrder(Node<T> *node)
    {
        if (node != nullptr)
        {
            PrintTreeInOrder(node->left);
            cout << node->data << "  ";
            PrintTreeInOrder(node->right);
        }
    }

    bool SearchInTree(int data, Node<T> *node)
    {
        if (node != nullptr)
        {
            if (node->data == data)
            {
                return true;
            }
            return SearchInTree(data, node->left) || SearchInTree(data, node->right);
        }
        return false;
    }

    T Start()
    {
        return root->data;
    }

    T End(Node<T> *node)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            return node->data;
        }
        return End(node->left);
        return End(node->right);
    }

    bool AreTreesEqual(Node<T> *node1, Node<T> *node2)
    {
        if (node1 == nullptr && node2 == nullptr)
        {
            return true;
        }

        if (node1->data != node2->data)
        {
            return false;
        }
        return AreTreesEqual(node1->left, node2->left) && AreTreesEqual(node1->right, node2->right);
    }

    int CountEvenNumbers(Node<T> *node, int count)
    {
        if (node == nullptr)
        {
            return count;
        }
        else if (node->data % 2 == 0)
        {
            count++;
        }
        count = CountEvenNumbers(node->left, count);
        count = CountEvenNumbers(node->right, count);
        return count;
    }

    bool IsBST(Node<T> *node)
    {
        if (node == nullptr)
        {
            return true;
        }
        if (node->left != nullptr)
        {
            if (node->left->data > node->data)
            {
                return false;
            }
        }
        if (node->right != nullptr)
        {
            if (node->right->data < node->data)
            {
                return false;
            }
        }
        return IsBST(node->left) && IsBST(node->right);
    }

    int InternalNodesCount(Node<T> *node, int count)
    {
        if (node == nullptr)
        {
            return count;
        }
        if (node->left != nullptr && node->right == nullptr)
        {
            count++;
        }
        if (node->right != nullptr && node->left == nullptr)
        {
            count++;
        }
        count = InternalNodesCount(node->left, count);
        count = InternalNodesCount(node->right, count);
        return count;
    }

    int CountLeaveNodes(Node<T> *node, int count)
    {
        if (node == nullptr)
        {
            return count;
        }
        if (node->right == nullptr && node->left == nullptr)
        {
            count++;
        }
        count = CountLeaveNodes(node->left, count);
        count = CountLeaveNodes(node->right, count);
        return count;
    }

    int Height(Node<T> *node)
    {
        if (node == nullptr)
        {
            return -1;
        }

        int leftHeight = Height(node->left);
        int rightHeight = Height(node->right);

        return max(leftHeight, rightHeight) + 1;
    }
};

int main()
{
    BinarySearchTree<int> BT;
    BinarySearchTree<int> BT1;
    BT.InsertInBST(16, BT.root);
    BT.InsertInBST(6, BT.root);
    BT.InsertInBST(18, BT.root);
    BT.InsertInBST(19, BT.root);
    BT.InsertInBST(4, BT.root);
    BT.InsertInBST(13, BT.root);
    BT.InsertInBST(3, BT.root);
    BT.InsertInBST(14, BT.root);
    BT.InsertInBST(5, BT.root);
    BT.InsertInBST(2, BT.root);
    BT.PrintTreeInOrder(BT.root);
    cout << "\nIs BST :" << BT.IsBST(BT.root);
    cout << "\nInternal nodes count :" << BT.InternalNodesCount(BT.root, 0);
    cout << "\nLeave nodes are :" << BT.CountLeaveNodes(BT.root, 0);
    cout << "\nHeight of tree is :" << BT.Height(BT.root);
    BT1.InsertInBST(15, BT1.root);
    BT1.InsertInBST(5, BT1.root);
    BT1.InsertInBST(18, BT1.root);
    BT1.InsertInBST(19, BT1.root);
    BT1.InsertInBST(4, BT1.root);
    BT1.InsertInBST(13, BT1.root);

    cout << "Pre Order :";
    cout << endl;

    cout << "Even numbers :" << BT.CountEvenNumbers(BT.root, 0);

    cout << "Pre Order :";
    BT1.PrintTreePreOrder(BT1.root);
    cout << endl;

    cout << "Are Equal :" << BT.AreTreesEqual(BT.root, BT1.root);
    cout << "Post Order :";
    BT.PrintTreePostOrder(BT.root);
    cout << endl;
    cout << "In Order :";
    BT.PrintTreeInOrder(BT.root);
    cout << endl;
    cout << "Start :" << BT.Start() << endl;
    cout << "End :" << BT.End(BT.root) << endl;
    cout << "Search :" << BT.SearchInTree(19, BT.root);
    return 0;
}