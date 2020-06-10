#include <bits/stdc++.h>

using namespace std;

class Timer {
    // To replace with the full timer class definition
    // inside this folder: LearnCpp9_18_timeSortArray.cpp
};


// Node of a doubly linked list
template<class T>
class Node  {
public:
	T data;
	Node<T> *prev, *next;
	static Node<T>* getnode(int data) {
		Node<T>* n = new Node<T>;
		n->data = data;
		n->prev = n->next = nullptr;
		return n;
	}
};

// A doubly linked list deque
template<class T>
class Deque {
	Node<T> *head, *tail, *copy;
	int size;

	// deep copy helper, this private helper creates a local duplicated Deque pointed by *copy
	void deepCopy( const Deque<T> & rhs );
public:
	Deque():head(nullptr), tail(nullptr), size(0) { }
	Deque( const Deque<T> & rhs ); // copy constructor
	Deque( Deque<T> && rhs );		// move constructor

	Deque<T> & operator= ( Deque<T> & rhs ); // copy operator=
	Deque<T> & operator= ( Deque<T> && rhs ); // move operator=

	// Operations on Deque
	void pushHead(T data);
	void pushTail(T data);
	void popHead();
	void popTail();

	void erase();
	T getFront();
	T getRear();
	int _size() { return size; }
	bool isEmpty() { return !head; }
	T& operator[] (const int &sub);
};

template<class T>
void Deque<T>::deepCopy( const Deque<T> & rhs ) {
	Node<T> *newNode = new Node<T>;
	Node<T> *current = rhs.head; //current points to the list to be copied
	size = rhs.size;//copy the head node
	copy = newNode; //create the node
	copy->data = current->data; //copy the info
	copy->next = current->next; //set the link field of the node to nullptr
	copy->prev = current->prev;
	tail = head; //make tail point to the head node

	current = current->next; //make current point to the next node
	//copy the remaining list
	while (current != nullptr) {
		newNode = new Node<T>; //create a node
		newNode->data = current->data; //copy the info
		newNode->next = current->next;
		newNode->prev = current->prev;
		tail->next = newNode;
		tail = newNode;
		current = current->next;
	}
}
// complete the rest of definitions below







// Driver program to test the Link List Deque class
int main() {
	Deque<int> dq;
	cout << "\nInsert item '5' at tail";
	dq.pushTail(5);

	cout << "\nInsert item '10' at tail";
	dq.pushTail(10);
	cout << "\nRear item: " << dq.getRear();

	dq.popTail();
	cout << "\nAfter deleting tail item, new tail is "
	     << dq.getRear();

	cout << "\nInserting item '15' in head";
	dq.pushHead(15);
	cout << "\nFront item: " << dq.getFront()
		 << "\nNumber of items in Deque: " << dq._size();

	dq.popHead();
	cout << "\nAfter deleting head item new head is "
		 << dq.getFront();

	dq.popHead();
	cout << "\nAfter deleting head item new head is "
		 << dq.getFront();

	cout << "\nInitializing a 10000 item Deque.";
	Timer t1;
	for(int i=1; i<=10000; i++) dq.pushTail(i);
	cout << "\nAdd 1~10000, dq now has "
		<< dq._size() << " items.";
	double run1 = t1.elapsed();
	cout << "\nTime elipsed: " << run1 << " seconds";

	cout << "\nDeep Copy construct dq2";
	Timer t2;
	Deque<int> dq2( dq );
	double run2 = t2.elapsed();
	cout << "\nTime elipsed: " << run2 << " seconds"
		 << "\ndq2 front to rear: " << dq2.getFront()
		 << " to " << dq2.getRear();
	cout << "\ndq2[0] is " << dq2[0]
		 << ", dq2[1000] is " << dq2[1000];

	cout << "\nMove construct dq3";
	Timer t3;
	Deque<int> dq3(std::move(dq));
	double run3 = t3.elapsed();
	cout << "\nTime elipsed: " << run3 << " seconds"
		 << "\ndq3 front to rear: " << dq3.getFront()
		 << " to " << dq3.getRear();
	cout << "\ndq3[0] is " << dq3[0]
		 << ", dq3[1000] is " << dq3[1000];

	cout << "\nAt this time, dq size is " << dq._size();
}
