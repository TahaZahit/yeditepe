#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>

template<class T>
class DLLNode {
public:

	DLLNode() {
		next = prev = 0;
	}
	DLLNode(const T& el, DLLNode<T> *n = 0, DLLNode<T> *p = 0, int pr = 0) {		// NEW
		info = el; next = n; prev = p; priority = pr;
	}
	T info;
	int priority;		// NEW
	DLLNode<T> *next, *prev;
};



template<class T>
class PriorityQueue {
public:
	////
	////
	void enqueue(const T& element, int priority);
	T& dequeue();

	PriorityQueue() {
		head = tail = 0;
	}
	
	~PriorityQueue() {
		clear();
	}
	bool isEmpty() const {
		return head == 0;
	}
	
protected:
	void addToDLLTail(const T&);
	T deleteFromDLLTail();
	void clear();
	void setToNull() {
		head = tail = 0;
	}
	void addToDLLHead(const T&);
	T deleteFromDLLHead();
	T& firstEl();
	T* find(const T&) const;

	DLLNode<T> *head, *tail;
	friend std::ostream& operator<<(std::ostream& out, const PriorityQueue<T>& dll) {
		for (DLLNode<T> *tmp = dll.head; tmp != 0; tmp = tmp->next)
			out << tmp->info << ' ';
		return out;
	}
};

template<class T>
void PriorityQueue<T>::addToDLLHead(const T& el) {
	if (head != 0) {
		head = new DLLNode<T>(el, head, 0);
		head->next->prev = head;
	}
	else head = tail = new DLLNode<T>(el);
}
///
///
template<class T>
void PriorityQueue<T>::enqueue(const T & element, int priority)
{
	DLLNode<T> *tmp = head;


	if (isEmpty()) { 
		addToDLLHead(element);
		head->priority = priority;
		return;
	}

	for (; tmp != 0; tmp = tmp->next) {	
		
		if (priority > tmp->priority) {
			
			if (tmp == head) {
				addToDLLHead(element);
				head->priority = priority;
				return;
			}
			DLLNode<T> *x = new DLLNode<T>;

			x->info = element;
			x->priority = priority;
			tmp->prev->next = x;
			x->next = tmp;
			x->prev = tmp->prev;
			tmp->prev = x;
			return;
		}

		else if (tmp->next == 0) {
			addToDLLTail(element);
			tail->priority = priority;
			return;
		}
	}
}
///
///
template<class T>
T & PriorityQueue<T>::dequeue()
{
	
	return deleteFromDLLHead();
}

template<class T>
void PriorityQueue<T>::addToDLLTail(const T& el) {
	if (tail != 0) {
		tail = new DLLNode<T>(el, 0, tail);
		tail->prev->next = tail;
	}
	else head = tail = new DLLNode<T>(el);
}

template<class T>
T PriorityQueue<T>::deleteFromDLLHead() {
	T el = head->info;
	if (head == tail) { // if only one DLLNode on the list;
		delete head;
		head = tail = 0;
	}
	else {              // if more than one DLLNode in the list;
		head = head->next;
		delete head->prev;
		head->prev = 0;
	}
	return el;
}

template<class T>
T PriorityQueue<T>::deleteFromDLLTail() {
	T el = tail->info;
	if (head == tail) { // if only one DLLNode on the list;
		delete head;
		head = tail = 0;
	}
	else {              // if more than one DLLNode in the list;
		tail = tail->prev;
		delete tail->next;
		tail->next = 0;
	}
	return el;
}

template <class T>
T* PriorityQueue<T>::find(const T& el) const {
	DLLNode<T> *tmp = head;
	for (; tmp != 0 && !(tmp->info == el);  // overloaded ==
		tmp = tmp->next);
	if (tmp == 0)
		return 0;
	else return &tmp->info;
}

template<class T>
T& PriorityQueue<T>::firstEl() {
	return head->info;
}

template<class T>
void PriorityQueue<T>::clear() {
	for (DLLNode<T> *tmp; head != 0; ) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}




#endif
