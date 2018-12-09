#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include "ListEmpty.h"
#include <QDebug>
using namespace std;

template<typename T>
struct Node {
	T data;														//IN/OUT - list data
	Node *next;													//IN/OUT - next in the list
	Node(T data) : data(data), next(0) {}						//IN/OUT - list data
};

template<typename T>
class LinkedList {
private:
	Node<T>* head;												//IN/OUT - head of list
	Node<T>* tail;												//IN/OUT - tail of list

	int rSum(Node<T>* head) const;								//IN/OUT - head of list
	int rLength(Node<T>* head) const;							//IN/OUT - head of list
public:
	class Iterator
	{
	private:
		Node<T>* current;										//IN/OUT - current node
	public:
		/* CONSTRUCTOR & DESTRUCTOR */
		Iterator();
		Iterator(Node<T>* ptr);									//IN/OUT - pointer to other node
		~Iterator();

		/* MUTATORS */
		Iterator operator++();

		/* ACCESSORS */
		T operator*();
		bool operator==(const Iterator& right)const;			//IN/OUT - other Iterator
		bool operator!=(const Iterator& right)const;			//IN/OUT - other Iterator
	};
	/* CONSTRUCTOR & DESTRUCTOR */
	LinkedList();
    LinkedList(const LinkedList<T>& source);						//IN/OUT - other linked list
    LinkedList& operator=(const LinkedList<T>& source);			//IN/OUT - other linked list
	~LinkedList();

	/* MUTATORS */
	void push_front(const T& value);							//IN/OUT - list data
	void push_back(const T& value);								//IN/OUT - list data
	void pop_front() throw(ListEmpty);
	void clear();
	void select_sort();
	void insert_sorted(const T& value);
	void remove_duplicates();

	/* ACCESSORS */
	void display() const;
	const T& front() const throw(ListEmpty);
	const T& back() const throw(ListEmpty);
	Iterator begin();
	Iterator end();
	int length() const;
	int sum() const;
	bool isEmpty() const;
};

#endif // LINKED_LIST_H

/*
	LinkedList class
	 This is an LinkedList class and
	 an object. It manages 3
	 attributes: IntNode (struct with
	 int data, pointer to the next node),
	 head, and tail.
*/

/*
	Method LinkedList: Class LinkedList
	-------------------------------------
	This function is a constructor, and
	sets the head and tail to NULL.
	------------------------------------
	PRE-CONDITIONS
		None
	POST-CONDITION
		None
*/
template<typename T>
LinkedList<T>::LinkedList() {
	head = NULL;
	tail = NULL;
}

/*
	Method LinkedList: Class LinkedList
	-------------------------------------
	This function is a
	copy constructor that does
	deep copy. It initialize a new
	list with the contents of an
	existing list.
	------------------------------------
	PRE-CONDITIONS
		source - other LinkedList object
		to copy its values.
	POST-CONDITION
		This object gets all
		the values of the
		other list.
*/
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& source) {
    if(source.head == NULL){
        this->head = NULL;
        this->tail = NULL;
    }
    else{
        this->head = new Node<T>(source.head->data);
        this->tail = head;
        Node<T>* current = source.head->next;
        while (current != NULL) {
            this->push_back(current->data);
		current = current->next;
        }
    }
}

/*
	Method operator=: Class LinkedList
	-------------------------------------
	This function is a
	copy constructor that does
	deep copy. It initialize a new
	list with the contents of an
	existing list.
	------------------------------------
	PRE-CONDITIONS
		list - other LinkedList object
		to copy its values.
	POST-CONDITION
		It returns itself but
		with the values of the
		other LinkedList object.
*/
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& source) {
	this->head = new Node<T>(source.head->data);
	this->tail = head;
	Node<T>* current = source.head->next;
	while (current != NULL) {
		this->push_back(current->data);
		current = current->next;
	}
}

/*
	Method ~LinkedList: Class LinkedList
	-------------------------------------
	This function deletes all
	the nodes from the head
	and sets the head and tail
	to NULL.
	------------------------------------
	PRE-CONDITIONS
		None
	POST-CONDITION
		None
*/
template<typename T>
LinkedList<T>::~LinkedList() {
	Node<T>* temp;
	while (head != NULL) {
		temp = head->next;
		delete head;
		head = temp;
	}
	head = NULL;
	tail = NULL;
}

/*
	Method push_front: Class LinkedList
	-------------------------------------
	This function inserts a value
	at the head of the list or the front. If
	the head is NULL than it will just set
	the first push_front to head and tail.
	------------------------------------
	PRE-CONDITIONS
		The following needs client defined
		values:
			value = value to insert
	POST-CONDITION
		Retuns nothing. Stores the value
		in the list.
*/
template<typename T>
void LinkedList<T>::push_front(const T& value) {
	Node<T>* temp = new Node<T>(value);
	if (head == NULL) {
		head = temp;
		temp->next = NULL;
		tail = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
}

/*
	Method push_back: Class LinkedList
	-------------------------------------
	This function adds an element
	at the end of the list, and assiging
	tail to this new element.
	------------------------------------
	PRE-CONDITIONS
		The following needs client defined
		values:
			value = value to insert
	POST-CONDITION
		Retuns nothing. Stores the value
		in the list.
*/
template<typename T>
void LinkedList<T>::push_back(const T& value) {
	Node<T>* temp = new Node<T>(value);
	if (tail == NULL) {
		tail = temp;
		head = temp;
	}
	else {
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
}

/*
	Method pop_front: Class LinkedList
	-------------------------------------
	This function deletes a value
	at the front or the head of the list.
	It does nothing if the list is empty.
	------------------------------------
	PRE-CONDITIONS
		Nothing
	POST-CONDITION
		Retuns nothing. Delets
		the first element
*/
template<typename T>
void LinkedList<T>::pop_front() throw(ListEmpty) {
	try {
		if (head == NULL) {
			throw ListEmpty("Pop invalid. Size is 0");
		}
		Node<T>* temp = head;
		if (head->next == NULL) {
			head = NULL;
			tail = NULL;
		}
		else {
			head = head->next;
		}
		delete temp;
	}
	catch (ListEmpty e) {
        e.what ();
        //throw e;
	}
}

/*
	Method clear: Class LinkedList
	-------------------------------------
	This function deletes all
    the nodes from the head
    and sets the head and tail
    to NULL.
	------------------------------------
	PRE-CONDITIONS
		Nothing
	POST-CONDITION
		Retuns nothing. Delets
		all the elemtns
*/
template<typename T>
void LinkedList<T>::clear() {
	Node<T>* temp;
	while (head != NULL) {
		temp = head->next;
		delete head;
		head = temp;
	}
	head = NULL;
	tail = NULL;
}

/*
	Method select_sort: Class LinkedList
	-------------------------------------
	This function sorts all the
	elements in ascending order using
	selection sort algorithm.
	------------------------------------
	PRE-CONDITIONS
		Nothing.
	POST-CONDITION
		Retuns nothing. But changes
		the order of the list.
*/
template<typename T>
void LinkedList<T>::select_sort() {
	Node<T>* searchNode1 = head;
	Node<T>* searchNode2 = NULL;
	Node<T>* minNode = NULL;
	bool foundMin = false;
	T min;
	while (searchNode1 != NULL) {
		searchNode2 = searchNode1;
		min = searchNode1->data;
		while (searchNode2 != NULL) {
			if (searchNode2->data < min) {
				min = searchNode2->data;
				minNode = searchNode2;
				foundMin = true;
			}
			searchNode2 = searchNode2->next;
		}
		if (foundMin) {
			T temp = searchNode1->data;
			searchNode1->data = minNode->data;
			minNode->data = temp;
			foundMin = false;
		}
		searchNode1 = searchNode1->next;
	}
}

/*
	Method insert_sorted: Class LinkedList
	-------------------------------------
	This function adds an element
	or the value in a acending order meaning
	that it checks each element in the list
	and inserts at appropriate position. So
	the values will still be acending order
	after insertion.
	------------------------------------
	PRE-CONDITIONS
		The following needs client defined
		values:
			value = value to be stored
	POST-CONDITION
		Retuns nothing. But changes
		the order of the list.
*/
template<typename T>
void LinkedList<T>::insert_sorted(const T& value) {
    Node<T>* temp = new Node<T>(value);
    Node<T>* headTemp = head;
    Node<T>* current = head;
    if (headTemp == NULL || headTemp->data >= temp->data) {
        temp->next = headTemp;
        head = temp;
        tail = temp;
    }
    else {
        while (current->next != NULL &&
            current->next->data < temp->data) {
            current = current->next;
        }
        if(current->next == NULL){
            tail = temp;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

/*
	Method remove_duplicates: Class LinkedList
	-------------------------------------
	This function removes all
	duplicate value that already exists
	in the list, but not the first
	instance of the element.
	------------------------------------
	PRE-CONDITIONS
		Nothing
	POST-CONDITION
		Retuns nothing. But removes
		some elements.
*/
template<typename T>
void LinkedList<T>::remove_duplicates() {
    Node<T>* currentNode = head;
    Node<T>* searchNode = NULL;
    Node<T>* temp;
    while (currentNode != NULL && currentNode->next != NULL) {
        searchNode = currentNode;
        while (searchNode->next != NULL) {
            if (currentNode->data == searchNode->next->data) {
                temp = searchNode->next;
                searchNode->next = searchNode->next->next;
                delete temp;
            }
            else {
                searchNode = searchNode->next;
            }
            tail = searchNode;
        }
        currentNode = currentNode->next;
    }
}

/*
	Method begin: Class LinkedList
	-------------------------------------
	This function returns an iterator
	which starts at the head
	of the linked list.
	------------------------------------
	PRE-CONDITIONS
		None
	POST-CONDITION
		returns an IntListIterator
		class starting at the head.
*/
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() {
	return Iterator(head);
}

/*
	Method end: Class LinkedList
	-------------------------------------
	This function returns an iterator
	which starts at the end
	of the linked list.
	------------------------------------
	PRE-CONDITIONS
		None
	POST-CONDITION
		returns an IntListIterator
		class starting at the tail.
*/
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() {
	return Iterator(NULL);
}

/*
	Method display: Class LinkedList
	-------------------------------------
	This function displays all
	the elements in the linked list.
	------------------------------------
	PRE-CONDITIONS
		None
	POST-CONDITION
		None
*/
template<typename T>
void LinkedList<T>::display() const {
	Node<T>* temp = head;
	bool firstRun = true;
	while (temp != NULL) {
		firstRun = false;
		temp = temp->next;
	}
}

/*
	Method front: Class LinkedList
	-------------------------------------
	This function returns the
	data in the head of the linked list.
	------------------------------------
	PRE-CONDITIONS
		None
	POST-CONDITION
		returns an int value of
		the head
*/
template<typename T>
const T& LinkedList<T>::front() const throw(ListEmpty) {
	try {
		if (head == NULL) {
			throw ListEmpty("No value. Size is 0");
		}
		return head->data;
	}
	catch (ListEmpty e) {
        e.what ();
		//throw e;
	}
}

/*
	Method back: Class LinkedList
	-------------------------------------
	This function returns the data
	in the tail of the linked list.
	------------------------------------
	PRE-CONDITIONS
		None
	POST-CONDITION
		returns an int value of
		the tail
*/
template<typename T>
const T& LinkedList<T>::back() const throw(ListEmpty) {
	try {
		if (tail == NULL) {
			throw ListEmpty("No value. Size is 0");
		}
		return tail->data;
	}
	catch (ListEmpty e) {
        e.what ();
        throw e;
	}
}

/*
	Method rSum: Class LinkedList
	-------------------------------------
	This function recursively determines
	the sum of all of the elements in the list.
	------------------------------------
	PRE-CONDITIONS
		head - head of the list.
	POST-CONDITION
		returns the sum of all the int values
		in the linked list.
*/
template<typename T>
int LinkedList<T>::rSum(Node<T>* head) const {
	if (head == NULL) {
		return 0;
	}
	else {
		return head->data + rSum(head->next);
	}
}

/*
	Method sum: Class LinkedList
	-------------------------------------
	This function recursively determines
	the sum of all of the elements in the list.
	It calls the rSum with the list head.
	------------------------------------
	PRE-CONDITIONS
		None
	POST-CONDITION
		returns the sum of all the int values
		in the linked list.
*/
template<typename T>
int LinkedList<T>::sum() const {
	return this->rSum(head);
}

/*
	Method rLength: Class LinkedList
	-------------------------------------
	This function recursively
	determines the length of the list.
	------------------------------------
	PRE-CONDITIONS
		head - where the list starts
		to count.
	POST-CONDITION
		returns the length of the
		linked list.
*/
template<typename T>
int LinkedList<T>::rLength(Node<T>* head) const {
	if (head == NULL) {
		return 0;
	}
	else {
		return 1 + rLength(head->next);
	}
}

/*
	Method length: Class LinkedList
	-------------------------------------
	This function calls
	the rLength function with the head
	of the list.
	------------------------------------
	PRE-CONDITIONS
		None
	POST-CONDITION
		returns the length of the
		linked list.
*/
template<typename T>
int LinkedList<T>::length() const {
	return this->rLength(head);
}

/*
	Method isEmpty: Class LinkedList
	-------------------------------------
	This function checks if the linked
	list has any elements.
	------------------------------------
	PRE-CONDITIONS
		None
	POST-CONDITION
		returns true if its empty
		false if not.
*/
template<typename T>
bool LinkedList<T>::isEmpty() const {
	if (head == NULL) {
		return true;
	}
	return false;
}

/*
	Method Iterator: Class Iterator
	-------------------------------------
	This function sets the current
		pointer to null.
	------------------------------------
	PRE-CONDITIONS
		None
	POST-CONDITION
		None
*/
template<typename T>
LinkedList<T>::Iterator::Iterator() {
	current = NULL;
}

/*
	Method Iterator: Class Iterator
	-------------------------------------
	This function sets the current
		pointer to ptr.
	------------------------------------
	PRE-CONDITIONS
		ptr - sets
		the objects member varibales
		to ptr.
	POST-CONDITION
		None
*/
template<typename T>
LinkedList<T>::Iterator::Iterator(Node<T>* ptr) {
	this->current = ptr;
}

/*
	Method ~IntList: Class IntList
	-------------------------------------
	This function deletes the object
	------------------------------------
	PRE-CONDITIONS
		None
	POST-CONDITION
		None
*/
template<typename T>
LinkedList<T>::Iterator::~Iterator() {}

/*
	Method operator++: Class Iterator
	-------------------------------------
	This function moves
	the current pointer to the next
	node in the linked list.
	------------------------------------
	PRE-CONDITIONS
		trash - a dummy variable
	POST-CONDITION
		returns itself with the new pointer
		node.
*/
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++() {
	if (current == NULL) {
		return NULL;
	}
	this->current = current->next;
	return *this;
}

/*
	Method operator*: Class Iterator
	-------------------------------------
	This function returns
	the data at that current node
	------------------------------------
	PRE-CONDITIONS
		none
	POST-CONDITION
		returns a int - data of the node.
*/
template<typename T>
T LinkedList<T>::Iterator::operator*() {
	return current->data;
}

/*
	Method operator==: Class Iterator
	-------------------------------------
	This function checks
	if the other Iterator object
	has the same current node as this
	object.
	------------------------------------
	PRE-CONDITIONS
		right - other iterator object
	POST-CONDITION
		true if they are same current node
	false if not
*/
template<typename T>
bool LinkedList<T>::Iterator::operator==(const Iterator& right)const {
	if (current == right.current) {
		return true;
	}
	return false;
}

/*
	Method operator!=: Class Iterator
	-------------------------------------
	This function checks
	if the other Iterator object
	has the same current node as this
	object.
	------------------------------------
	PRE-CONDITIONS
		right - other iterator object
	POST-CONDITION
		false if they are same current node
		true if not
*/
template<typename T>
bool LinkedList<T>::Iterator::operator!=(const Iterator& right)const {
	if (current == right.current) {
		return false;
	}
	return true;
}
