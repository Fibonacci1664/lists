#include "CustomList.h"

/** Constructor. */
CustomList::CustomList()
{
	_head = nullptr;
	_tail = nullptr;
	_size = 0;
}

/** Destructor. */
CustomList::~CustomList()
{
	CustomListNode* nextNode;

	while (_head != nullptr)
	{
		nextNode = _head->next;
		delete _head;
		_head = nextNode;
	}

	print();
}

void CustomList::print()
{
	std::cout << "Contents:\n";

	CustomListNode* p = _head;

	while (p != nullptr)
	{
		std::cout << "- " << p->item << "\n";
		p = p->next;
	}
}

void CustomList::push_front(const std::string& item)
{
	CustomListNode* newNode = new CustomListNode;
	newNode->item = item;

	// Test size of linked list.
	if (_head == nullptr)
	{
		/*
		 * Empty list, make both _head and_tail point to 'newNode'
		 * as this is the only node in the list.
		 */

		_head = newNode;
		_tail = newNode;
		newNode->next = nullptr;	// Off the end of the list - sentinel value.
	}
	else
	{
		// There is at least 1 node.
		CustomListNode* temp = new CustomListNode;

		temp = _head;			// Save the node that head points to, namely the first node.
		_head = newNode;		// Point the head at the new node to be inserted.
		newNode->next = temp;	// Point the next thing after new node to what you saved in temp, namely the old first node.

		temp = nullptr;
		delete temp;
		temp = nullptr;			// Required?????
	}

	++_size;		// Increment the size of the list.
}

int CustomList::getSize()
{
	return _size;
}