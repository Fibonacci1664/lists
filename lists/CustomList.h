#ifndef CUSTOMLIST_H
#define CUSTOMLIST_H

#include <iostream>
#include <string>

/** One node in a linked list of strings. */
struct CustomListNode
{
	std::string item;
	CustomListNode* next;
};

/** A linked list of strings. */
class CustomList
{
public:
	/** Constructor. */
	CustomList();

	/** Destructor. */
	~CustomList();

	/** Print out the items in the list. */
	void print();

	// XXX Put more methods here...
	void push_front(const std::string& item);

	// Getters/Setters
	int getSize();

private:
	/** Pointer to the first item in the list, or nullptr if the list is empty. */
	CustomListNode* _head;
	CustomListNode* _tail;
	int _size;
};

#endif