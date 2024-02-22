// #pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    string data;
    Node *up;
    Node *down;
    Node *right;
    Node *left;

    Node(string val)
    {
        data = val;
        up = down = right = left = nullptr;
    }
};

class Starting_Range
{
public:
    int row, col;
    Starting_Range(int r, int c)
    {
        row = r;
        col = c;
    }
};

class Ending_Range
{
public:
    int row, col;
    Ending_Range(int r, int c)
    {
        row = r;
        col = c;
    }
};

class Excel
{
public:
    Node *excel;
    Node *head;
    Node *current;
    int row, column;
    vector<string> myVector;

    Excel()
    {
        row = column = 0;
        excel = head = current = nullptr;
        createFirstRow();
        for (int i = 2; i <= 5; i++)
        {
            Add_Row_Below();
        }
        row = column = 5;
    }
    void createFirstRow()
    {
        for (int col = 1; col <= 5; col++)
        {
            Node *newNode = new Node("0");
            if (excel == nullptr)
            {
                excel = newNode;
                head = newNode;
                current = newNode;
            }
            else
            {
                current->right = newNode;
                newNode->left = current;
                current = current->right;
            }
        }
        row++;
    }
    void Add_Row_Below()
    {
        Node *temp = this->current;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        Node *firstNode = new Node("0");

        if (temp->down == nullptr)
        {
            temp->down = firstNode;
            firstNode->up = temp;
        }
        else
        {
            temp->down->up = firstNode;
            firstNode->down = temp->down;
            firstNode->up = temp;
            temp->down = firstNode;
        }
        temp = temp->right;
        Node *temp2 = firstNode;
        while (temp != nullptr)
        {

            Node *node = new Node("0");
            if (temp->down == nullptr)
            {
                temp->down = node;
                node->up = temp;
                temp2->right = node;
                node->left = temp2;
            }
            else
            {
                temp->down->up = node;
                node->down = temp->down;
                node->up = temp;
                temp->down = node;
                node->left = temp2;
                temp2->right = node;
            }
            temp2 = temp2->right;
            temp = temp->right;
            current = temp2;
        }
        row++;
    }

    class Iterator
    {
    public:
        Node *iter;
        Iterator(Node *i)
        {
            iter = i;
        }
        Iterator operator++(int)
        {

            return iter = iter->right;
        }
        Iterator operator--(int)
        {
            return iter = iter->left;
        }
        Iterator operator--()
        {
            return iter = iter->up;
        }
        Iterator operator++()
        {
            return iter = iter->down;
        }
    };
    void Add_Row_Above_Node()
    {
        Node *temp = this->current;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        Node *firstNode = new Node("r");

        if (temp->up == nullptr)
        {
            temp->up = firstNode;
            firstNode->down = temp;
            head = firstNode;
        }
        else
        {
            temp->up->down = firstNode;
            firstNode->up = temp->up;
            firstNode->down = temp;
            temp->up = firstNode;
        }
        temp = temp->right;
        Node *temp2 = firstNode;

        while (temp != nullptr)
        {

            Node *newNode = new Node("r");
            if (temp->up == nullptr)
            {
                temp->up = newNode;
                newNode->down = temp;
                temp2->right = newNode;
                newNode->left = temp2;
            }
            else
            {
                temp->up->down = newNode;
                newNode->up = temp->up;
                newNode->down = temp;
                temp->up = newNode;
                newNode->left = temp2;
                temp2->right = newNode;
            }
            temp2 = temp2->right;
            temp = temp->right;
            current = temp2;
        }
        row++;
    }
    void InserRowAbove()
    {
        Node *node = current;
        while (node->left != nullptr)
        {
            node = node->left;
        }

        while (node != nullptr)
        {
            Node *newNode = new Node("");
            newNode->up = node->up;
            if (node->up != nullptr)
            {
                node->up->down = newNode;
            }
            newNode->down = node;
            node->up = newNode;
            if (node->left != nullptr)
            {
                newNode->left = node->left->up;
                if (node->left->up != nullptr)
                {
                    node->left->up->right = newNode;
                }
            }
            node = node->right;
        }
        if (head->up != nullptr)
        {
            head = head->up;
        }
        row++;
    }
    void InsertRowBelow()
    {
        Node *node = current;
        while (node->left != nullptr)
        {
            node = node->left;
        }

        while (node != nullptr)
        {
            Node *newNode = new Node("   ");
            newNode->down = node->down;
            if (node->down != nullptr)
            {
                node->down->up = newNode;
            }
            newNode->up = node;
            node->down = newNode;
            if (node->left != nullptr)
            {
                newNode->left = node->left->down;
                if (node->left->down != nullptr)
                {
                    node->left->down->right = newNode;
                }
            }
            node = node->right;
        }
        row++;
    }
    void printExcel()
    {
        char c = 242;
        system("cls");
        HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *current = temp;
            while (current != nullptr)
            {
                cout << "+" << c << c << c << c << c << c;
                current = current->right;
            }
            cout << "+" << endl;

            current = temp;
            while (current != nullptr)
            {
                if (current == this->current)
                {

                    cout << "|";
                    SetConsoleTextAttribute(H, 4);
                    if (current->data.length() < 4)
                    {
                        for (int i = current->data.length(); i <= 4; i++)
                        {
                            cout << " ";
                        }
                        cout << current->data << " ";
                    }
                    else if (this->current->data.length() == 4)
                    {
                        cout << " ";
                        cout << current->data << " ";
                    }
                    else
                    {
                        string sub = current->data.substr(0, 4);
                        cout << " " << sub << " ";
                    }
                    SetConsoleTextAttribute(H, 7);
                }
                else
                {
                    cout << "|";
                    if (current->data.length() < 4)
                    {
                        for (int i = current->data.length(); i <= 4; i++)
                        {
                            cout << " ";
                        }
                        cout << current->data << " ";
                    }
                    else if (this->current->data.length() == 4)
                    {
                        cout << " ";
                        cout << current->data << " ";
                    }
                    else
                    {
                        string sub = current->data.substr(0, 4);
                        cout << " " << sub << " ";
                    }
                }
                current = current->right;
            }
            cout << "|" << endl;
            temp = temp->down;
        }
        Node *current = head;
        while (current != nullptr)
        {
            cout << "+" << c << c << c << c << c << c;
            current = current->right;
        }
        cout << "+" << endl;
    }
    void insertColumnToRight()
    {
        Node *temp = this->current;
        while (temp->up != nullptr)
        {
            temp = temp->up;
        }
        Node *firstNode = new Node("c");
        if (temp->right == nullptr)
        {
            temp->right = firstNode;
            firstNode->left = temp;
        }
        else
        {
            temp->right->left = firstNode;
            firstNode->right = temp->right;
            firstNode->left = temp;
            temp->right = firstNode;
        }
        temp = temp->down;
        Node *temp2 = firstNode;

        while (temp != nullptr)
        {
            Node *node = new Node("c");
            if (temp->right == nullptr)
            {
                temp->right = node;
                node->left = temp;
                node->up = temp2;
                temp2->down = node;
            }
            else
            {
                temp->right->left = node;
                node->right = temp->right;
                node->left = temp;
                temp->right = node;
                temp->up = temp2;
                temp2->down = node;
            }
            temp2 = temp2->down;
            temp = temp->down;
            current = temp2;
        }
        this->column++;
    }
    void insertColumnToLeft()
    {
        Node *temp = this->current;
        while (temp->up != nullptr)
        {
            temp = temp->up;
        }
        Node *firstNode = new Node("c");
        if (temp == head)
        {
            head = firstNode;
        }
        if (temp->left == nullptr)
        {
            temp->left = firstNode;
            firstNode->right = temp;
        }
        else
        {
            temp->left->right = firstNode;
            firstNode->left = temp->left;
            firstNode->right = temp;
            temp->left = firstNode;
        }
        temp = temp->down;
        Node *temp2 = firstNode;

        while (temp != nullptr)
        {
            Node *node = new Node("c");
            if (temp->left == nullptr)
            {
                temp->left = node;
                node->right = temp;
                node->up = temp2;
                temp2->down = node;
            }
            else
            {
                temp->left->right = node;
                node->left = temp->left;
                node->right = temp;
                temp->left = node;
                node->up = temp2;
                temp2->down = node;
            }
            temp2 = temp2->down;
            temp = temp->down;
        }
        this->column++;
    }
    void insertFirstColumn()
    {
        Node *temp = head;
        Node *firstNode = new Node("f");
        temp->left = firstNode;
        firstNode->right = temp;
        head = firstNode;
        Node *chase = firstNode;
        temp = temp->down;
        while (temp != nullptr)
        {
            Node *node = new Node("f");
            node->up = chase;
            chase->down = node;
            node->right = temp;
            temp->left = node;
            temp = temp->down;
            chase = chase->down;
        }
    }
    void insertLastColumn()
    {
        Node *last = head;
        while (last->right != nullptr)
        {
            last = last->right;
        }

        Node *firstNode = new Node("l");
        last->right = firstNode;
        firstNode->left = last;
        last = last->down;
        Node *chase = firstNode;
        while (last != nullptr)
        {
            Node *node = new Node("l");
            node->up = chase;
            chase->down = node;
            last->right = node;
            node->left = last;

            last = last->down;
            chase = chase->down;
        }
    }
    void insertFirstRow()
    {
        Node *temp = head;
        Node *firstNode = new Node("u");
        temp->up = firstNode;
        firstNode->down = temp;
        head = firstNode;
        Node *chase = firstNode;
        temp = temp->right;
        while (temp != nullptr)
        {
            Node *node = new Node("u");
            node->left = chase;
            chase->right = node;
            temp->up = node;
            node->down = temp;

            temp = temp->right;
            chase = chase->right;
        }
    }
    void insertLastRow()
    {
        Node *last = head;
        while (last->down != nullptr)
        {
            last = last->down;
        }
        Node *firstNode = new Node("l");
        last->down = firstNode;
        firstNode->up = last;
        last = last->right;
        Node *chase = firstNode;
        while (last != nullptr)
        {
            Node *node = new Node("d");
            node->left = chase;
            chase->right = node;
            node->up = last;
            last->down = node;

            last = last->right;
            chase = chase->right;
        }
    }
    void insertCellByUpShift()
    {
        insertFirstRow();
        Node *first = this->current;
        while (first->up != nullptr)
        {
            first = first->up;
        }

        Node *chase = first;
        while (chase != current)
        {
            chase->data = chase->down->data;
            chase = chase->down;
        }
        this->current->data = " ";
        this->row++;
    }
    void insertCellByRightShift()
    {
        insertLastColumn();
        Node *last = this->current;
        while (last->right != nullptr)
        {
            last = last->right;
        }
        Node *chase = last;
        while (chase != current)
        {
            chase->data = chase->left->data;
            chase = chase->left;
        }
        this->current->data = " ";
        this->column++;
    }
    void insertCellByLeftShift()
    {
        insertFirstColumn();
        Node *first = this->current;
        while (first->left != nullptr)
        {
            first = first->left;
        }
        Node *chase = first;
        while (chase != current)
        {
            chase->data = chase->right->data;
            chase = chase->right;
        }
        this->current->data = " ";
        this->column++;
    }
    void insertCellByDownShift()
    {
        insertLastRow();
        Node *last = this->current;
        while (last->down != nullptr)
        {
            last = last->down;
        }
        Node *chase = last;
        while (chase != current)
        {
            chase->data = chase->up->data;
            chase = chase->up;
        }
        this->current->data = " ";
        this->row++;
    }
    void deleteCellByLeftShift()
    {
        if (this->current->right == nullptr)
        {
            this->current = nullptr;
            this->current->data = "";
        }
        else
        {
            Node *temp = this->current;
            while (temp->right->right != nullptr)
            {
                temp->data = temp->right->data;
                temp = temp->right;
            }

            temp->right->data = "";
        }
    }
    void deleteCellByUpShift(Node *c)
    {
        if (c->up == nullptr && c->down == nullptr && c->right != nullptr)
        {
            Node *lef = c->left;
            Node *righ = c->right;
            while (lef != nullptr)
            {
                lef->right = righ;
                righ->left = lef;
                righ = righ->down;
                lef = lef->down;
            }
        }
        else if (c->down == nullptr)
        {
            c = nullptr;
        }
        else
        {
            Node *temp = c;
            while (temp->down->down != nullptr)
            {
                temp->data = temp->down->data;
                temp = temp->down;
            }
            if (temp->down->left != nullptr && temp->down->right != nullptr)
            {
                temp->down->left->right = nullptr;
                temp->down->right->left = nullptr;
            }
            temp->down = nullptr;
        }
    }

    void deleteColumn()
    {
        Node *temp = this->current;
        while (temp->up != nullptr)
        {
            temp = temp->up;
        }
        if (this->current->left == nullptr && head->right != nullptr)
        {
            head = head->right;
            this->current = this->current->right;
        }
        if (this->current->left != nullptr && this->current->right != nullptr)
        {
            temp = temp->left;
            while (temp != nullptr)
            {
                temp->right->right->left = temp;
                temp->right = temp->right->right;
                temp = temp->down;
            }

            this->current = this->current->left;
        }
        else if (this->current->right == nullptr)
        {
            temp = temp->left;
            while (temp != nullptr)
            {
                temp->right = nullptr;
                temp = temp->down;
            }
            this->current = this->current->left;
        }
        else if (this->current->left == nullptr)
        {
            while (temp != nullptr)
            {
                temp->right->left = nullptr;
            }
            this->current = this->current->right;
        }
        this->column--;
    }

    void deleteRowCurrent()
    {
        Node *temp = this->current;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        if (temp == head && head->down != nullptr)
        {
            this->current = this->current->down;
            head = head->down;
            temp = temp->down;
            while (temp != nullptr)
            {
                temp->up = nullptr;
                temp = temp->right;
            }
        }
        else if (this->current->down == nullptr)
        {
            temp = temp->up;
            this->current = this->current->up;
            while (temp != nullptr)
            {
                temp->down = nullptr;
                temp = temp->right;
            }
        }
        else
        {
            temp = temp->up;
            this->current = this->current->up;
            while (temp != nullptr)
            {
                temp->down->down->up = temp;
                temp->down = temp->down->down;
                temp = temp->right;
            }
        }
        this->row--;
    }

    void ClearRow()
    {
        Node *temp = this->current;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        while (temp != nullptr)
        {
            temp->data = "0";
            temp = temp->right;
        }
    }

    void ClearColumn()
    {
        Node *temp = current;
        while (temp->up != nullptr)
        {
            temp = temp->up;
        }
        while (temp != nullptr)
        {
            temp->data = "0";
            temp = temp->down;
        }
    }

    // selected sum
    double GetRangeSum(Starting_Range start, Ending_Range end)
    {
        double sum = 0;
        Iterator iterator(this->head);
        for (int i = 1; i < start.row; i++)
        {
            if (iterator.iter == nullptr)
            {
                return 0.0;
            }
            iterator++;
        }

        for (int i = 1; i < start.col; i++)
        {
            if (iterator.iter == nullptr)
            {
                return 0.0;
            }
            ++iterator;
        }

        for (int row = start.row; row <= end.row; row++)
        {
            for (int col = start.col; col <= end.col; col++)
            {
                if (iterator.iter == nullptr)
                {
                    return 0.0;
                }

                sum += stod(iterator.iter->data);
                iterator++;
            }
            for (int i = end.col; i >= start.col; i--)
            {
                if (iterator.iter == nullptr)
                {
                    return 0.0;
                }
                iterator--;
            }
            ++iterator;
        }

        return sum;
    }
    
    double GetRangeAverage(Starting_Range start, Ending_Range end)
    {
        int cellCount = (end.row - start.row + 1) * (end.col - start.col + 1);
        double sum = GetRangeSum(start, end);
        double average = sum / cellCount;

        return average;
    }
    int getSelectedCount(Starting_Range start, Ending_Range end)
    {
        int cellCount = (end.row - start.row + 1) * (end.col - start.col + 1);
        return cellCount;
    }

    double GetRangeMinimum(Starting_Range start, Ending_Range end)
    {
        double minimum = INT64_MAX;
        Iterator iterator(this->head);
        for (int i = 1; i < start.row; i++)
        {
            if (iterator.iter == nullptr)
            {
                return 0.0;
            }
            iterator++;
        }

        for (int i = 1; i < start.col; i++)
        {
            if (iterator.iter == nullptr)
            {
                return 0.0;
            }
            ++iterator;
        }

        for (int row = start.row; row <= end.row; row++)
        {
            for (int col = start.col; col <= end.col; col++)
            {
                if (iterator.iter == nullptr)
                {
                    return 0.0;
                }

                minimum = min(stod(iterator.iter->data), minimum);
                iterator++;
            }
            for (int i = end.col; i >= start.col; i--)
            {
                if (iterator.iter == nullptr)
                {
                    return 0.0;
                }
                iterator--;
            }
            ++iterator;
        }

        return minimum;
    }
    double GetRangeMaximum(Starting_Range start, Ending_Range end)
    {
        double maximum = INT64_MIN;
        Iterator iterator(this->head);
        for (int i = 1; i < start.row; i++)
        {
            if (iterator.iter == nullptr)
            {
                return 0.0;
            }
            iterator++;
        }

        for (int i = 1; i < start.col; i++)
        {
            if (iterator.iter == nullptr)
            {
                return 0.0;
            }
            ++iterator;
        }

        for (int row = start.row; row <= end.row; row++)
        {
            for (int col = start.col; col <= end.col; col++)
            {
                if (iterator.iter == nullptr)
                {
                    return 0.0;
                }

                maximum = max(stod(iterator.iter->data), maximum);
                iterator++;
            }
            for (int i = end.col; i >= start.col; i--)
            {
                if (iterator.iter == nullptr)
                {
                    return 0.0;
                }
                iterator--;
            }
            ++iterator;
        }

        return maximum;
    }
    void RangeCopySelect(Starting_Range start, Ending_Range end)
    {
        Iterator iterator(this->head);
        for (int i = 1; i < start.row; i++)
        {
            if (iterator.iter == nullptr)
            {
                return;
            }
            iterator++;
        }

        for (int i = 1; i < start.col; i++)
        {
            if (iterator.iter == nullptr)
            {
                return;
            }
            ++iterator;
        }

        for (int row = start.row; row <= end.row; row++)
        {
            for (int col = start.col; col <= end.col; col++)
            {
                if (iterator.iter == nullptr)
                {
                    return;
                }
                myVector.push_back(iterator.iter->data);
                iterator++;
            }
            myVector.push_back("$$$");
            for (int i = end.col; i >= start.col; i--)
            {
                if (iterator.iter == nullptr)
                {
                    return;
                }
                iterator--;
            }
            ++iterator;
        }
        myVector.pop_back();
    }
    void RangeCutSelect(Starting_Range start, Ending_Range end)
    {
        Iterator iterator(this->head);
        for (int i = 1; i < start.row; i++)
        {
            if (iterator.iter == nullptr)
            {
                return;
            }
            iterator++;
        }

        for (int i = 1; i < start.col; i++)
        {
            if (iterator.iter == nullptr)
            {
                return;
            }
            ++iterator;
        }

        for (int row = start.row; row <= end.row; row++)
        {
            for (int col = start.col; col <= end.col; col++)
            {
                if (iterator.iter == nullptr)
                {
                    return;
                }
                myVector.push_back(iterator.iter->data);
                iterator.iter->data = "";
                iterator++;
            }
            myVector.push_back("$$$");
            for (int i = end.col; i >= start.col; i--)
            {
                if (iterator.iter == nullptr)
                {
                    return;
                }
                iterator--;
            }
            ++iterator;
        }
        myVector.pop_back();
    }

    void paste()
    {
        if (this->myVector.empty())
        {
            return;
        }
        else
        {
            Node *temp = this->current;

            for (int i = 0; i < myVector.size(); i++)
            {
                if (myVector[i] == "$$$" && this->current->down != nullptr)
                {
                    this->current = this->current->down;
                    temp = this->current;
                    temp->data = myVector[i];
                }
                else if (myVector[i] == "$$$" && this->current->down == nullptr)
                {
                    InsertRowBelow();
                    this->current = this->current->down;
                    temp = this->current;
                }
                else
                {
                    temp->data = myVector[i];

                    if (i < myVector.size() - 1 && myVector[i + 1] != "$$$" && temp->right == nullptr)
                    {
                        insertLastColumn();
                    }

                    temp = temp->right;
                }
            }
        }
    }
};
