// Linked lists lab exercise
// Adam Sampson <a.sampson@abertay.ac.uk>

#include <cassert>
#include <iostream>

#include "CustomList.h"

// Import things we need from the standard library
using std::cin;
using std::cout;
using std::endl;


int main(int argc, char *argv[])
{
	// XXX Put your testing code here...

	// ############# STRING TEST #############

	//CustomList<std::string> myList;

	//myList.print();
	//myList.push_front("Bread");
	//myList.push_front("Milk");
	//myList.push_front("Cookies");
	//myList.push_front("Soup");
	//myList.print();

	//std::cout << "My list size: " << myList.getSize() << '\n';

	////assert(myList.getSize() == 4);

	//std::cout << "pop_front()\n";
	//myList.pop_front();

	//myList.print();

	//std::cout << "My list size: " << myList.getSize() << '\n';

	//std::cout << "push_back()\n";
	//myList.push_back("Bacon");

	//myList.print();

	//std::cout << "My list size: " << myList.getSize() << '\n';

	//std::cout << "pop_back()\n";
	//myList.pop_back();

	//myList.print();

	//std::cout << "My list size: " << myList.getSize() << '\n';

	//int indexPos = 2;

	//std::cout << "Value stored at indexPos " << indexPos << " : " << myList.at(indexPos) << '\n';



	// ############# INT TEST #############

	CustomList<int> myList;

	myList.print();
	myList.push_front(5);
	myList.push_front(7);
	myList.push_front(12);
	myList.push_front(3);
	myList.print();

	std::cout << "My list size: " << myList.getSize() << '\n';

	assert(myList.getSize() == 4);

	std::cout << "pop_front()\n";
	myList.pop_front();

	myList.print();

	std::cout << "My list size: " << myList.getSize() << '\n';

	std::cout << "push_back()\n";
	myList.push_back(16);

	myList.print();

	std::cout << "My list size: " << myList.getSize() << '\n';

	std::cout << "pop_back()\n";
	myList.pop_back();

	myList.print();

	std::cout << "My list size: " << myList.getSize() << '\n';

	int indexPos = 2;

	std::cout << "Value stored at indexPos " << indexPos << " : " << myList.at(indexPos) << '\n';

	cout << "All OK! Press return to exit...\n";
	cin.get();

	return 0;
}