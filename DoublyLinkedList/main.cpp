#include "DoubleLinkedList.h"

int main()
{
	dLinkedList<int> L;
	dLinkedList<int> L1;
	//cout <<"Is Empty : "<< L.isEmpty() << endl;
	L.InsertAtHead(20);
	L.InsertAtHead(10);
	L.InsertAtTail(30);
	/*L1.InsertAtHead(2);
	L1.InsertAtHead(1);*/
	//L.Print();
	//L1.InsertAtTail(3);
	//L1.Print();
	//L.Splice(L1,30);
	//L.Print();
	cout << "With forward iterator " << endl;
	for (dLinkedList<int>::fiterator i = L.fbegin(); i != L.fend();i++)
	{
		cout << *i << "<----->";
	}
	cout << "NULL"<<endl;

	cout << "With reverse iterator " << endl;
	for (dLinkedList<int>::riterator i = L.rbegin(); i != L.rend();i++)
	{
		cout << *i << "<----->";
	}
	cout << "NULL" << endl;

	/*cout << "With general iterator " << endl;
	for (dLinkedList<int>::giterator i = L.begin();i != L.end()->next;i++)
	{
		cout << *i << "<----->";
	}
	cout << "NULL" << endl;*/
	////cout <<"Is Empty : "<< L.isEmpty() << endl;
	//L.Print();
	//L.InsertAtTail(30);
	//L.InsertAtTail(40);
	//L.Print();
	//L.InsertAfter(20,25);
	//L.Print();
	//L.InsertBefore(40, 35);
	//L.Print();
	//L.InsertBefore(10, 5);
	//L.Print();
	//L.RemoveFromFront();
	//L.Print();
	//L.RemoveAt(20);
	//L.Print();
	return 0;
}