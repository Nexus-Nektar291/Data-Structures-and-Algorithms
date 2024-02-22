#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node<T> *next;
	Node<T> *previous;

	Node(T value)
	{
		data = value;
		next = nullptr;
		previous = nullptr;
	}
};

template <typename T>
class DoubleLinkedList
{
private:
	Node<T> *head;
	Node<T> *tail;
	int size;

public:
	DoubleLinkedList()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	Node<T> *fbegin()
	{
		return head;
	}

	Node<T> *fend()
	{
		return tail->next;
	}

	Node<T> *rbegin()
	{
		return tail;
	}

	Node<T> *rend()
	{
		return head->previous;
	}

	Node<T> *begin()
	{
		return head;
	}

	Node<T> *end()
	{
		return tail;
	}

	class ForwardIterator
	{
	public:
		Node<T> *iter;
		ForwardIterator(Node<T> *n)
		{
			iter = n;
		}

		Node<T> *operator++(int)
		{
			return iter = iter->next;
		}

		bool operator!=(ForwardIterator n)
		{
			return iter != n.iter;
		}

		bool operator==(ForwardIterator n)
		{
			return iter == n.iter;
		}

		T operator*()
		{
			return iter->data;
		}
	};

	class ReverseIterator
	{
	public:
		Node<T> *iter;
		ReverseIterator(Node<T> *n)
		{
			iter = n;
		}

		bool operator!=(ReverseIterator n)
		{
			return iter != n.iter;
		}

		Node<T> *operator++(int)
		{
			return iter = iter->previous;
		}

		bool operator==(ReverseIterator n)
		{
			return iter = n.iter;
		}

		T operator*()
		{
			return iter->data;
		}
	};

	class GeneralIterator
	{
	public:
		Node<T> *iter;
		GeneralIterator(Node<T> *n)
		{
			iter = n;
		}

		bool operator!=(GeneralIterator n)
		{
			return iter != n.iter;
		}

		bool operator==(GeneralIterator n)
		{
			return iter == n.iter;
		}

		Node<T> *operator++(int)
		{
			return iter = iter->next;
		}

		Node<T> *operator--(int)
		{
			return iter = iter->previous;
		}

		T operator*()
		{
			return iter->data;
		}
	};

	Node<T> *GetHead()
	{
		return head;
	}

	Node<T> *GetTail()
	{
		return tail;
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

	void InsertAtTail(T value)
	{
		Node<T> *new_node = new Node<T>(value);
		if (isEmpty())
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			new_node->previous = tail;
			tail = new_node;
		}
		size++;
	}

	void InsertAtFront(T value)
	{
		Node<T> *new_node = new Node<T>(value);
		if (isEmpty())
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			new_node->next = head;
			head->previous = new_node;
			head = new_node;
		}
	}

	void RemoveAtTail()
	{
		if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			tail->previous->next = nullptr;
			tail = tail->previous;
		}
	}

	void RemoveAtHead()
	{
		if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			head->next->previous = nullptr;
			head = head->next;
		}
	}

	void InserAfter(T value, T key)
	{
		Node<T> *new_node = new Node<T>(value);
		Node<T> *temp = head;
		while (temp->data != key)
		{
			temp = temp->next;
		}
		if (temp == tail)
		{
			InsertAtTail(value);
		}
		else
		{
			temp->next->previous = new_node;
			new_node->next = temp->next;
			temp->next = new_node;
			new_node->previous = temp;
		}
	}

	void InsertBefore(T value, T key)
	{
		Node<T> *new_node = new Node<T>(value);
		Node<T> *temp = head;
		int count = 0;
		while (temp->data != key)
		{
			count = 1;
			temp = temp->next;
		}
		if (count == 0)
		{
			InsertAtFront(value);
		}
		else
		{
			new_node->next = temp;
			temp->previous->next = new_node;
			new_node->previous = temp->previous;
			temp->previous = new_node;
		}
	}

	void Display()
	{
		Node<T> *temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << "------->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}

	void removeAtSpecificPosition(T key)
	{
		Node<T> *newPtr = head;
		while (newPtr != nullptr)
		{
			if (newPtr->data == key)
			{
				if (newPtr != head && newPtr != tail)
				{
					newPtr->previous->next = newPtr->next;
					newPtr->next->previous = newPtr->previous;
				}
				if (newPtr == head)
				{
					RemoveAtHead();
				}
				if (newPtr == tail)
				{
					RemoveAtTail();
				}
			}
			newPtr = newPtr->next;
		}
	}

	void deleteDataWithIndex(int idx)
	{
		if (idx > size or idx < 0)
			return;
		else if (idx == 0)
			this->head = nullptr;
		else
		{
			Node<T> *temp = head;
			for (int i = 0; i < idx - 1; i++)
			{
				temp = temp->next;
			}
			temp->previous->next = temp->next;
			temp->next->previous = temp->previous;
			// return true;
		}
		size--;
	}
};

template <typename T>
void Splice(DoubleLinkedList<T> &l1, DoubleLinkedList<T> &l2, T iter)
{
	Node<T> *temp = l1.GetHead();
	Node<T> *L1_Tail = l1.GetTail();
	Node<T> *L2_Head = l2.GetHead();
	Node<T> *L2_Tail = l2.GetTail();
	while (temp->data != iter)
	{
		temp = temp->next;
	}
	if (temp == L1_Tail)
	{
		Node<T> *temp1 = l2.GetHead();
		while (temp1 != nullptr)
		{
			l1.InsertAtTail(temp1->data);
			temp1 = temp1->next;
		}
	}
	else
	{
		L2_Tail->next = temp->next;
		temp->next->previous = L2_Tail;
		temp->next = L2_Head;
		L2_Head->previous = temp;
	}
}