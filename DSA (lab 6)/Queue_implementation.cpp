#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

public:
    Node(T val)
    {
        data = val;
        next = nullptr;
    }
};

template <typename T>
class Queue_Using_LinkedList
{
    Node<T> *head;

public:
    Queue_Using_LinkedList()
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
    void Enqueue(T val)
    {
        Node<T> *newnode = new Node<T>(val);
        if (isEmpty())
        {
            head = newnode;
            return;
        }

        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    T Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return 1;
        }
        else
        {
            Node<T> *temp = head;
            head = head->next;
            T result = temp->data;
            delete temp;
            return result;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Null" << endl;
        }
        else
        {
            Node<T> *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ----> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    Queue_Using_LinkedList<int> q;
    cout << q.isEmpty() << endl;
    q.Enqueue(10);
    // q.Enqueue(40);
    q.display();
    cout << q.isEmpty() << endl;

    cout << q.Dequeue() << endl;
    q.display();
    // cout << q.Dequeue() << endl;
    // cout << q.isEmpty() << endl;
    return 0;
}