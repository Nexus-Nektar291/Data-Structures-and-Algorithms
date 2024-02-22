#include <iostream>
#include <stack>

using namespace std;

void SortedElement(stack<int> &stack, int element)
{
    if (stack.empty() || element > stack.top())
    {
        stack.push(element);
        return;
    }
    int top = stack.top();
    stack.pop();
    SortedElement(stack, element);
    stack.push(top);
}

void sortStack(stack<int> &stack)
{
    if (!stack.empty())
    {
        int element = stack.top();
        stack.pop();
        sortStack(stack);
        SortedElement(stack, element);
    }
}

void display(stack<int> temp)
{
    sortStack(temp);
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> stack;

    stack.push(3);
    stack.push(1);
    stack.push(4);
    stack.push(2);

    display(stack);

    return 0;
}
