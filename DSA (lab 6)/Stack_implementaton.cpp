#include <iostream>
#include <stack>
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
class Stack_Using_LinkedList
{
    Node<T> *head;

public:
    Stack_Using_LinkedList()
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
    void push(T val)
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
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            // return 0;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return 0;
        }
        Node<T> *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        T result = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return result;
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
    void PrintReverselist()
    {
        stack<T> reverselist;
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            reverselist.push(temp->data);
            temp = temp->next;
        }
        while (!reverselist.empty())
        {
            cout << reverselist.top() << " ----> ";
            reverselist.pop();
        }
        cout << endl;
    }
};

int main()
{
    Stack_Using_LinkedList<int> s;
    // cout << s.isEmpty() << endl;
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.display();
    s.PrintReverselist();
    // cout << s.pop() << endl;
    // s.display();
    // cout << s.isEmpty() << endl;
    return 0;
}