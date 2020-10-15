#ifndef CUSTOMLIST_H
#define CUSTOMLIST_H

#include <iostream>
#include <string>

/** One node in a linked list of type T. */
template <typename T> struct CustomListNode
{
	T item;
	CustomListNode<T>* next;
};

/** A linked list of type T. */
template <typename T> class CustomList
{
public:
	///** Constructor. */
	//CustomList();

	///** Destructor. */
	//~CustomList();

	///** Print out the items in the list. */
	//void print();

	//// XXX Put more methods here...
	//void push_front(const T& item);
	//void push_back(const T& item);
	//void pop_front();
	//void pop_back();
	//T& at(int position);

	//// Getters/Setters
	//int getSize();



	// ############## Content from .cpp file ##############

	/** Constructor. */
	CustomList::CustomList()
	{
		_head = nullptr;
		_tail = nullptr;
		//_size = 0;
	}

	/** Destructor. */
	CustomList::~CustomList()
	{
		CustomListNode<T>* nextNode;

		while (_head != nullptr)
		{
			nextNode = _head->next;
			delete _head;
			_head = nextNode;
		}
	}

	void CustomList::print()
	{
		std::cout << "Contents:\n";

		CustomListNode<T>* p = _head;

		while (p != nullptr)
		{
			std::cout << "- " << p->item << "\n";
			p = p->next;
		}
	}

	void CustomList::push_front(const T& item)
	{
		CustomListNode<T>* newNode = new CustomListNode<T>;
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
			CustomListNode<T>* temp;		// rtns a pointer.

			temp = _head;			// Save the node that head points to, namely the first node.
			_head = newNode;		// Point the head at the new node to be inserted.
			newNode->next = temp;	// Point the next thing after new node to what you saved in temp, namely the old first node.

			//temp = nullptr;
			//delete temp;
			//temp = nullptr;			// Required?????
		}

		//++_size;		// Increment the size of the list.
	}

	void CustomList::push_back(const T& item)
	{
		CustomListNode<T>* newNode = new CustomListNode<T>;
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
			newNode->next = nullptr;		// Off the end of the list - sentinel value.
		}
		else
		{
			_tail->next = newNode;			// Point the tail at the new node to be inserted.
			newNode->next = nullptr;		// Set the sentinel value off the end of the list.
			_tail = newNode;				// Point the next thing after new node to nullptr.
		}
	}

	void CustomList::pop_front()
	{
		if (_head != nullptr)
		{
			CustomListNode<T>* newHead = _head->next;
			delete _head;
			_head = newHead;
		}
		else
		{
			std::cout << "The list is empty!\n";
		}
	}

	void CustomList::pop_back()
	{
		/*
		 * If the very next thing after the head node is nullptr, we know there is only 1 node.
		 * in which case simply call pop_front();
		 */
		if (_head->next == nullptr)
		{
			std::cout << "1 item only: calling pop_front()\n";
			pop_front();
		}
		else
		{
			std::cout << "More than 1 item.\n";

			// More than 1 node so we must iterate over the list.
			CustomListNode<T>* curr = _head->next;
			CustomListNode<T>* prev = _head;

			// While we have not hit our sentinel value. keep advancing curr & prev.
			while (curr->next != nullptr)
			{
				prev = curr;
				curr = curr->next;
			}

			// Once at the end of the list.
			_tail = prev;					// Point tail to the new last item (1 before the end).
			_tail->next = nullptr;			// Set new sentinel value.
			delete curr;					// Delete the thing that curr points to namely the previous last item in the list.
			curr = nullptr;					// Set to null for error checking.
		}
	}

	T& CustomList::at(int position)
	{
		// We have at least 1 item.
		if (_head != nullptr)
		{
			int count = 0;
			CustomListNode<T>* iter = _head;

			while (count != position)
			{
				iter = iter->next;
				++count;
			}

			return iter->item;
		}

		std::cout << "Zero items in the list!\n";
	}

	int CustomList::getSize()
	{
		int count = 0;
		CustomListNode<T>* p = _head;

		// Iterate over list until we get to the end counting as we go.
		while (p != nullptr)
		{
			++count;
			p = p->next;
		}

		return count;
	}

private:
	/** Pointer to the first item in the list, or nullptr if the list is empty. */
	CustomListNode<T>* _head;
	CustomListNode<T>* _tail;
	//int _size;
};

#endif