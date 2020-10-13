// Linked lists lab exercise
// Adam Sampson <a.sampson@abertay.ac.uk>

#include <cassert>
#include <iostream>

#include "CustomList.h"

// Import things we need from the standard library
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
	// XXX Put your testing code here...

	CustomList myList;

	myList.print();
	myList.push_front("Bread");
	myList.push_front("Milk");
	myList.push_front("Cookies");
	myList.push_front("Soup");
	myList.print();

	cout << "All OK! Press return to exit...\n";
	cin.get();

	return 0;
}