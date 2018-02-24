//Sorted Linked List
//Michael Viscione

#include "Header.h"
#include <iostream>
using namespace std;

bool List::SortedIsEmpty() { //Checks if the list is empty
	if (head == NULL)
		return true;
	else
		return false;
}

int List::SortedGetLength() { //gets Length
	size = 1;
	Node* cur = head;
	if (head == NULL)
		size = 0;
	else {
		while (cur->next != NULL) {
			size++;
			cur = cur->next;
		}
	}
	return size;
}

bool List::SortedFind(int k, int& x) { //Finds value of the kth element
	int count = 1;
	Node* cur = head;
	while (count != k && cur->next != NULL)
	{
		cur = cur->next;
		count++;
		
		if (count == k) {
			x = cur->data;
			return true;
		}
	}

	return false;

}

int List::SortedSearch(int key) { //Searches for position of element
	int index = 1;
	for (Node* cur = head; cur->data != key; index++) {
		cur = cur->next;
		if (!cur)
			return -1;
	}
	return index;
}

void List::SortedInsert(int x) {
	Node* cur = head;
	if (SortedIsEmpty() == true) {   //if List is Empty
		head = new Node;			//create new Node for head
		head->data = x;				//data of head is x
		head->next = NULL;			//head point to NULL
		tail = head;
	}
	else {
		Node* tmp = new Node;		//creates new Node

		if (x >= tail->data) {		 //if x is greater than tail
			tmp->data = x;			//put tmp after tail and set tail = tmp
			tmp->next = NULL;
			tail->next = tmp;
			tail = tmp;
		}
		else if (x < head->data) {		//if x is less than head
			tmp->data = head->data;		//put tmp before head and set head =tmp
			tmp->next = head->next;
			head->data = x;
			head->next = tmp;
			if (tail == head)			//if head is only Node then move tail to 2nd node
				tail = tmp;
		}
		else {
			while (cur != tail) {				//if x > head and x < tail
				if (cur->next->data >= x) {		//puts new Node in the middle of list
					tmp->next = cur->next;
					tmp->data = x;
					cur->next = tmp;
					break;
				}
				cur = cur->next;
			}
		}
	}
}

void List::SortedDelete(int k, int& x, bool& success) {
	Node* cur = head, *tmp, *prev = cur;
	success = 1;
	int count = 1;
	size = SortedGetLength(); //get length of list
	while (count != k && cur != NULL) { //loops until cur is in the kth position or exceeds list
		prev = cur;
		cur = cur->next;
		count++;
	}

	if (cur == tail) { //deletes tail
		delete cur;
		tail = prev;
	}
	else if (cur == head) { //deletes head
		tmp = head;
		head = head->next;
		delete tmp;
	}
	else if (count > 1 && count < size) { //deletes middle
		prev->next = cur->next;
		delete cur;
	}
	else success = 0; //deletes nothing and returns false
}

void List::SortedPrint() { //Print data
	Node* cur = head;
	while (cur != tail->next) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

bool List::CheckDup(int x) {
	Node* cur = head;
	int size = SortedGetLength(), count = 1;
	if (size != 0) {							//Checks for duplicates if the list isnt empty
		while (count <= size) {
			if (cur->data == x)
				return true;				//returns true if duplicate is found 
			cur = cur->next;
			count++;
		}
	}
	return false;
}
