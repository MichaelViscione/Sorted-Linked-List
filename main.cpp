//Sorted Linked List
//Michael Viscione

#include <iostream> 
#include <string>
#include "Header.h"
using namespace std;

int main() {
	string command, dup;
	List myList;
	bool success;
	int x = 0, k;
	cout << "This program creates and sorts a linked list. In the commands, the letter" << endl;
	cout << "x represents an integer and k represents the kth place of the list." << endl;
	cout << "Commands : Insert x, Delete k, Print, Find k, Length, Search x, and Exit." << endl << endl;

	
	do {
		cout << "Allow Duplicates? ";
		cin >> dup;

		if (dup != "yes" && dup != "no")
			cout << "Please enter 'yes' or 'no'.\n";
	} while (dup != "yes" && dup != "no");

	cout << "Enter a command.\n";
	cin >> command;

	while (command != "Exit") { //loops commands until "Exit"
		if (myList.SortedIsEmpty() == true && command != "Insert") //checks if List is empty before commands
			cout << "The list is empty. Please insert a number.\n";
		else {														//the rest format according to the command
			if (command == "Insert") {
				cin >> x;
				if (dup == "no") {									//checks for duplicates if not allowed
					if (myList.CheckDup(x))
						cout << "Value is already in the list.\n";
					else
						myList.SortedInsert(x);
				}
				else
					myList.SortedInsert(x);
			}
			else if (command == "Delete") {
				cin >> k;
				myList.SortedDelete(k, x, success);
				if (success == true) cout << "-Success\n";
				else cout << "-Fail\n";
			}
			else if (command == "Print") {
				myList.SortedPrint();
			}
			else if (command == "Find") {
				cin >> k;
				if (myList.SortedFind(k, x))
				cout << x << endl;
				else
					cout << "The list does not have " << k << " values." << endl;
			}
			else if (command == "Length") {
				cout << myList.SortedGetLength() << endl;
			}
			else if (command == "Search") {
				cin >> x;
				if (myList.SortedSearch(x) != -1)
					cout << myList.SortedSearch(x) << endl;
				else
					cout << "Value not found in the list.\n";
			}
			else
				cout << "Invalid Input\n"; //if command is not recognized
		}
		cin >> command; //asks for new command
	}

	system("pause");
	return 0;
}