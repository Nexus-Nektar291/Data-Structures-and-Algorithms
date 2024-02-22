#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void actualPrint(Node *temp);
void printReverseList_Recursive(Node *temp);

class LinkedList
{

public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }
    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        return false;
    }
    int getFront()
    {
        if (isEmpty())
        {
            cout << "The list is empty! " << endl;
            return 0;
        }
        return head->data;
    }
    int getTail()
    {
        if (isEmpty())
        {
            cout << "The list is empty! " << endl;
            return 0;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    Node *search(int key)
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data == key)
                return temp;
        }
        return nullptr;
        // while (temp->next->next == nullptr && temp->next->data != key)
        // {
        //     temp = temp->next;
        // }
        // if (temp->next->next == nullptr)
        // {
        //     cout << "The key " << key << " is not found in the list!" << endl;
        //     return NULL;
        // }
        // return temp->next;
    }
    void insert(int val)
    {
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    void insert_after(int key, int val)
    {
        if (isEmpty())
        {
            cout << "The list is empty! " << endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr && temp->data != key)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Key not found in the list!" << endl;
            return;
        }

        Node *newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void insert_before(int key, int val)
    {
        if (isEmpty())
        {
            cout << "The list is empty! " << endl;
            return;
        }
        if (head->data == key)
        {
            Node *newnode = new Node(val);
            newnode->next = head;
            head = newnode;
            return;
        }

        Node *temp1 = head;
        Node *temp2 = head->next;
        while (temp2 != nullptr && temp2->data != key)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp2 == nullptr)
        {
            cout << "Key " << key << " not found in the list!" << endl;
            return;
        }

        Node *newnode = new Node(val);
        temp1->next = newnode;
        newnode->next = temp2;
    }
    void insertAtFront(int val)
    {
        Node *newnode = new Node(val);
        newnode->next = head;
        head = newnode;
    }
    void insertAtTail(int val)
    {
        Node *newnode = new Node(val);
        if (isEmpty())
        {
            head = newnode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    void insertAtMid(int val)
    {
        Node *newnode = new Node(val);

        if (isEmpty())
        {
            head = newnode;
            return;
        }

        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        temp = head;
        for (int i = 0; i < (count / 2) - 1; i++)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    void deleteAt(int val)
    {
        if (isEmpty())
        {
            cout << "The list is empty!" << endl;
            return;
        }
        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp1 = head;
        Node *temp2 = head->next;
        while (temp2 != nullptr && temp2->data != val)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp2 == nullptr)
        {
            cout << "Value " << val << " not found in the list." << endl;
            return;
        }

        temp1->next = temp2->next;
        delete temp2;
    }
    void delete_front()
    {
        if (isEmpty())
        {
            cout << "The list is empty!" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void delete_tail()
    {
        if (isEmpty())
        {
            cout << "The list is empty!" << endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    void delete_middle()
    {
        if (isEmpty())
        {
            cout << "The list is empty!" << endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        int count = 0;
        Node *temp1 = head;
        while (temp1 != NULL)
        {
            count++;
            temp1 = temp1->next;
        }
        if (count % 2 != 0)
        {
            count++;
        }

        // cout << "count is : " << count << endl;
        temp1 = head;
        Node *temp2 = head->next;
        for (int i = 0; i < (count / 2) - 2; i++)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        delete temp2;
    }
    void display()
    {

        if (isEmpty())
        {
            cout << "The list is empty!" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ----> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
    int findMiddle()
    {
        if (isEmpty())
        {
            cout << "The list is empty!" << endl;
            return 0;
        }
        if (head->next == nullptr)
        {
            return head->data;
        }

        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        if (count % 2 != 0)
        {
            count++;
        }

        temp = head;
        for (int i = 0; i < (count / 2) - 1; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    bool isListCircular()
    {
        if (isEmpty())
        {
            return false;
        }

        Node *slow = head;
        Node *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }

    void printRecursive()
    {
        actualPrint(head);
        cout << endl;
    }
    void reverseRecursive()
    {
        printReverseList_Recursive(head);
        cout << endl;
    }
    friend void actualPrint(Node *temp);
    friend void printReverseList_Recursive(Node *temp);
};

void actualPrint(Node *temp)
{
    if (temp == nullptr)
    {
        cout << "Null";
        return;
    }
    cout << temp->data << " ----> ";
    actualPrint(temp->next);
}

void printReverseList_Recursive(Node *temp)
{
    if (temp != nullptr)
    {
        printReverseList_Recursive(temp->next);
        cout << temp->data << "     ";
    }
}

int main()
{
    LinkedList l1;
    // l1.getFront();
    l1.insert(10);
    l1.insert(20);
    l1.insert(30);
    l1.insert(40);
    l1.display();
    Node *temp = l1.head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = l1.head;
    cout << l1.isListCircular() << endl;

    // l1.insertAtMid(25);
    // l1.display();
    // l1.insertAtMid(22);
    // l1.display();
    // l1.insertAtMid(24);
    // l1.display();

    // l1.insertAtFront(15);
    // l1.display();
    // cout << "Front element is : " << l1.getFront() << endl;
    // l1.deleteAt(40);
    // l1.display();
    // cout << "Last element is : " << l1.getTail() << endl;
    // l1.delete_front();
    // l1.display();
    // l1.delete_tail();
    // l1.display();
    // l1.delete_tail();
    // l1.display();
    // // l1.display();
    // l1.insert_after(20, 21);
    // l1.display();

    // l1.insert_before(25, 22);
    // l1.display();

    // l1.insertAtFront(13);
    // l1.display();
    // l1.insertAtFront(21);
    // l1.display();

    // l1.insertAtTail(79);
    // l1.display();
    // l1.insertAtTail(89);
    // l1.display();

    // l1.deleteAt(10);
    // l1.display();

    // l1.delete_middle();
    // l1.display();
    // l1.delete_middle();
    // l1.display();
    // cout << "*************************" << endl;
    // l1.printRecursive();
    // l1.reverseRecursive();
    // cout << l1.findMiddle() << endl;

    return 0;
}