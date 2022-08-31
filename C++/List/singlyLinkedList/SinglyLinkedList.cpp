#include "SinglyLinkedList.h"
#include <iostream>

int main(void)
{
	SinglyLinkedList s1;

    s1.AddTail(10);
    s1.ShowLinkedList();
    s1.AddTail(20);
    s1.ShowLinkedList();
    s1.AddTail(30);
    s1.ShowLinkedList();

    std::cout<<s1.IndexTail()<<std::endl;
    std::cout<<s1.Get(s1.IndexTail())<<std::endl;
    std::cout<<s1.Get(0)<<std::endl;;
    std::cout<<s1.Get(1)<<std::endl;;
    std::cout<<s1.Get(2)<<std::endl;
    

	return 0;
}

SinglyLinkedList::SinglyLinkedList():head(nullptr),tail(nullptr)
{}


SinglyLinkedList::~SinglyLinkedList()
{
	while (!IsEmpty())
		DeleteIndex(IndexTail());
}

int SinglyLinkedList::Get(int index)
{
	Node* Point = head;
	while (index--)
	{
		Point = Point->Next;
	}

	return Point->Value;
}



int SinglyLinkedList::IndexTail()
{

	if (IsEmpty())
		return -1;

	Node* Point = head;
	int index = 0;
	while (Point != tail)
	{
		index++;
		Point = Point->Next;
	}
    return index;
}

void SinglyLinkedList::AddHead(int val)
{
	if (IsEmpty())
	{
		head = new Node;
		tail = head;
	}
	else
	{
		Node* NewHead = new Node;
		NewHead->Next = head;
		head = NewHead;
	}
	head->Value = val;
}

void SinglyLinkedList::AddTail(int val)
{
	if (IsEmpty())
	{
		tail = new Node;
		head = tail;
	}
	else
	{
		Node* NewTail = new Node;
		tail->Next = NewTail;
		tail = NewTail;
	}
	tail->Value = val;
}

void SinglyLinkedList::AddIndex(int index, int val)
{
	if (index > IndexTail())
	{
		std::cout << "index out of bounds" << std::endl;
		return;
	}
	Node* PreNode = head;
	--index;
	while (index--)
	{
		PreNode = PreNode->Next;
	}
	Node* NewNode = new Node;
	NewNode->Value = val;
	NewNode->Next = PreNode->Next;
	PreNode->Next = NewNode;
}

int SinglyLinkedList::DeleteIndex(int index)
{
	if (IsEmpty())
	{
		return -1;
	}
	if (index == 0)
	{
		Node* NextHead = head->Next;
		
		head->Next = nullptr;
		delete head;

		head = NextHead;
	}
	else if (index == IndexTail())
	{
		Node* PreTail = head;
		index--;
		while (index--)
		{
			PreTail = PreTail->Next;
		}
		PreTail->Next = nullptr;
		delete tail;
		tail = PreTail;
	}
	else if(0<index<IndexTail())
	{
		Node* PreNode = head;
		index--;
		while (index--)
		{
			PreNode = PreNode->Next;
		}
		Node* Point = PreNode->Next;

		PreNode->Next = Point->Next;
		
		Point->Next = nullptr;
		delete Point;
	}
	else
	{
		std::cout << "index out of bounds" << std::endl;
	}
	return 0;
}


bool SinglyLinkedList::IsEmpty()
{
	return(head == nullptr && tail == nullptr);
}

void SinglyLinkedList::ShowLinkedList()
{
	Node* Point = head;
	while(Point != tail)
	{
		std::cout << Point->Value << " -> ";
		Point = Point->Next;
	}
	std::cout << Point->Value << "\n";
}
