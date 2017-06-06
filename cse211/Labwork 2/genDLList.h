#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>

template <class T>
class DLLNode
{
public:
	DLLNode()
	{
		next = prev = 0;
	}

	DLLNode(const T& el, DLLNode<T>* n = 0, DLLNode<T>* p = 0)
	{
		info = el;
		next = n;
		prev = p;
	}

	T info;
	DLLNode<T> *next, *prev;
};

template <class T>
class DoublyLinkedList
{
public:
	DoublyLinkedList()
	{
		head = tail = 0;
	}

	void addToDLLTail(const T&);
	T deleteFromDLLTail();

	~DoublyLinkedList()
	{
		clear();
	}

	bool isEmpty() const
	{
		return head == 0;
	}

	void clear();

	void setToNull()
	{
		head = tail = 0;
	}

	void addToDLLHead(const T&);
	T deleteFromDLLHead();
	T& firstEl();
	T* find(const T&) const;

	void append(const DoublyLinkedList<T>& el);
	DoublyLinkedList<T>* split();


	void reset_to_zero();
protected:
	DLLNode<T> *head, *tail;

	friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& dll)
	{
		for (DLLNode<T>* tmp = dll.head; tmp != 0; tmp = tmp->next)
			out << tmp->info << ' ';
		return out;
	}
};

template <class T>
void DoublyLinkedList<T>::addToDLLHead(const T& el)
{
	if (head != 0)
	{
		head = new DLLNode<T>(el, head, 0);
		head->next->prev = head;
	}
	else head = tail = new DLLNode<T>(el);
}

template <class T>
void DoublyLinkedList<T>::addToDLLTail(const T& el)
{
	if (tail != 0)
	{
		tail = new DLLNode<T>(el, 0, tail);
		tail->prev->next = tail;
	}
	else head = tail = new DLLNode<T>(el);
}

template <class T>
T DoublyLinkedList<T>::deleteFromDLLHead()
{
	T el = head->info;
	if (head == tail)
	{ // if only one DLLNode on the list;
		delete head;
		head = tail = 0;
	}
	else
	{ // if more than one DLLNode in the list;
		head = head->next;
		delete head->prev;
		head->prev = 0;
	}
	return el;
}

template <class T>
T DoublyLinkedList<T>::deleteFromDLLTail()
{
	T el = tail->info;
	if (head == tail)
	{ // if only one DLLNode on the list;
		delete head;
		head = tail = 0;
	}
	else
	{ // if more than one DLLNode in the list;
		tail = tail->prev;
		delete tail->next;
		tail->next = 0;
	}
	return el;
}

template <class T>
T* DoublyLinkedList<T>::find(const T& el) const
{
	DLLNode<T>* tmp = head;
	for (; tmp != 0 && !(tmp->info == el); // overloaded ==
	       tmp = tmp->next);
	if (tmp == 0)
		return 0;
	else return &tmp->info;
}

template <class T>
T& DoublyLinkedList<T>::firstEl()
{
	return head->info;
}

template <class T>
void DoublyLinkedList<T>::clear()
{
	for (DLLNode<T>* tmp; head != 0;)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

template <class T>
void DoublyLinkedList<T>::reset_to_zero()
{
	DLLNode<T>* current = head;

	while (current != nullptr)
	{
		current->info = (T)0;
		current = current->next;
	}
}


template <class T>
void DoublyLinkedList<T>::append(const DoublyLinkedList<T>& el)
{
	if (el.head != nullptr)
	{
		DLLNode<T>* temp_el = el.head;

		while (temp_el != el.tail)
		{
			tail->next = new DLLNode<T>;
			tail->next->prev = tail;
			tail->next->info = temp_el->info;
			tail = tail->next;
			temp_el = temp_el->next;
		}

		tail->next = new DLLNode<T>;
		tail->next->prev = tail;
		tail->next->info = temp_el->info;
		tail = tail->next;
	}
}

template <class T>
DoublyLinkedList<T>* DoublyLinkedList<T>::split()
{
	DoublyLinkedList<T>* el = new DoublyLinkedList<T>;
	int size, mid;
	DLLNode<T>* temp = head;

	for (size = 0; temp != tail; temp = temp->next)size++;
	mid = size % 2 ? size / 2 + 1 : size / 2;
	temp = head;
	for (int i = 0; i < mid; i++) temp = temp->next;


	el->head = temp->next;
	el->head->prev = nullptr;
	el->tail = tail;

	tail = temp;
	tail->next = nullptr;
	

	return el;
}
#endif
