//Sorted Linked List
//Michael Viscione

#include <iostream>
using namespace std;
class List {
public:
	bool SortedIsEmpty();
	int SortedGetLength();
	bool SortedFind(int k, int& x);
	int SortedSearch(int key);
	void SortedInsert(int x);
	void SortedDelete(int k, int& x, bool& success);
	void SortedPrint();
	bool CheckDup(int x);

private:
	struct Node {
		int data;
		Node* next;
	};
	Node* head = NULL;
	Node* tail = head;
	int size = 0;
};
