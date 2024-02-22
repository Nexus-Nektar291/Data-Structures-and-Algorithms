#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
    Node()
    {
        data = -1;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty()
    {
        if (head == nullptr && tail == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void InsertAtHead(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
    }

    void InsertAtTail(int value)
    {
        Node *new_node = new Node(value);
        if (tail == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    Node *GetHead()
    {
        return head;
    }
};

void DisplayRecursivelyInReverse(Node *temp)
{
    if (temp == nullptr)
    {
        return;
    }
    DisplayRecursivelyInReverse(temp->next);
    cout << temp->data << "------>";
}

void display(Node *temp)
{
    while (temp != nullptr)
    {
        cout << temp->data << "------->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void DisplayRecursively(Node *temp)
{
    if (temp == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }
    cout << temp->data << "------>";
    DisplayRecursively(temp->next);
}

Node *mergeTwoLists(Node *list1, Node *list2)
{
    if (list1 == nullptr && list2 == nullptr)
    {
        return NULL;
    }
    else if (list1->next == nullptr)
    {
        return list2;
    }
    else if (list2->next == nullptr)
    {
        return list1;
    }
    Node *merged = new Node();
    Node *temp = merged;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data <= list2->data)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if (list1 != nullptr)
    {
        temp->next = list1;
    }
    if (list2 != nullptr)
    {
        temp->next = list2;
    }
    return merged->next;
}

Node *removeNthFromEnd(Node *head, int n) // completed
{
    Node *temp = head;
    Node *temp2 = head;
    int i = 0;
    while (temp != nullptr)
    {
        temp = temp->next;
        i++;
    }
    if (i < n)
    {
        return NULL;
    }
    else if (i == n)
    {
        head = head->next;
        return head;
    }
    else
    {
        int j = i - n;
        int k = 1;
        while (k != j)
        {
            temp2 = temp2->next;
            k++;
        }
        temp2->next = temp2->next->next;
        return head;
    }
}

Node *swapPairs(Node *head)
{
    Node *current = head;
    Node *temp = nullptr;
    Node *next = nullptr;
    Node *previous = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        if (next->next != nullptr)
        {
            temp = next->next;
        }
        else
        {
            temp = nullptr;
        }
        next->next = current;

        current->next = temp;
        current = temp;
    }
    return head;
}

Node *reverseBetween(Node *head, int left, int right)
{
    Node *temp = head;
    Node *temp2 = head;
    int iteration1 = 1, iteration2 = 1;
    int count1 = 0;
    Node *prev1 = head;
    while (iteration1 != left)
    {
        temp = temp->next;
        if (count1 == 1)
        {
            prev1 = prev1->next;
            count1 = 0;
        }
        count1++;
        iteration1++;
    }

    while (iteration2 != right)
    {
        temp2 = temp2->next;
        iteration2++;
    }

    Node *previous = nullptr;
    Node *next = nullptr;
    Node *current = temp;
    Node *temp2_next = temp2->next;

    while (current != temp2)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    current->next = previous;
    temp->next = temp2_next;
    if (temp != prev1)
    {
        prev1->next = current;
    }
    else
    {
        head = temp2;
    }

    return head;
}

class MyLinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    MyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index)
    {
        int iteration = 0;
        Node *temp = head;
        while (iteration != index)
        {
            temp = temp->next;
            if (temp == nullptr)
            {
                return -1;
            }
            iteration++;
        }
        if (temp == nullptr)
        {
            return -1;
        }
        return temp->data;
    }

    void addAtHead(int val)
    {
        Node *new_node = new Node(val);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
        size++;
    }

    void addAtTail(int val)
    {
        Node *new_node = new Node(val);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0 && head == nullptr)
        {
            addAtHead(val);
        }
        else if (index == 0 && head != nullptr)
        {
            addAtHead(val);
            head->data = val;
        }
        else
        {

            int iteration = 0;
            Node *temp = head;
            Node *prev = head;
            int count = 0;
            if (temp != nullptr)
            {

                while (iteration != index)
                {
                    temp = temp->next;
                    if (count == 1)
                    {
                        prev = prev->next;
                        count = 0;
                    }
                    if (temp == nullptr)
                    {
                        break;
                    }
                    count++;
                    iteration++;
                }
                if (temp == nullptr)
                {
                    addAtTail(val);
                }
                else
                {
                    Node *new_node = new Node(val);
                    new_node->next = prev->next;
                    prev->next = new_node;
                }
            }
        }
    }

    void deleteAtIndex(int index)
    {
        if (index == 0)
        {
            head = head->next;
        }
        else
        {
            int iteration = 0;
            Node *temp = head;
            int count = 0;
            Node *prev = head;
            while (iteration != index)
            {
                temp = temp->next;
                if (count == 1)
                {
                    prev = prev->next;
                    count = 0;
                }
                if (temp == nullptr)
                {
                    break;
                }
                count++;
                iteration++;
            }
            if (temp != nullptr)
            {

                prev->next = temp->next;

                if (temp == tail)
                {
                    tail = prev;
                }
            }
            else
            {
                cout << "Invalid" << endl;
            }
        }
    }
    Node *GetHead()
    {
        return head;
    }
};
