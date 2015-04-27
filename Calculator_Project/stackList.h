#include <iostream>
#include <stdexcept>

using namespace std;

class exception;

template <class T>
class Node
{
private:
	T data;
	Node<T>* next;

public:
	Node() : data(0), next(NULL) {}
	Node(T init) : data(init), next(NULL) {}

	template <class U>
	friend class stackList;
};

template <class T>
class stackList{

private:
	Node<T>* head;

public:
	stackList();
	stackList(T init);
	~stackList();

	void push(T value);
	void pop();
	T top();
	bool empty();
	void print();
};

template <class T>
stackList<T>::stackList()
{
	head = NULL;
}

template <class T>
stackList<T>::stackList(T init)
{
	head = new Node(init);
}

template <class T>
stackList<T>::~stackList()
{
	Node<T>* current = head;
	while (current)
	{
		Node<T>* next = current->next;
		delete current;
		current = next;
	}

	head = 0;
}

template <class T>
void stackList<T>::push(T value)
{
	if (head == NULL){
		head = new Node<T>(value);
	}
	else {
		Node<T>* t = new Node<T>(value);
		t->next = head;
		head = t;
	}
}

template <class T>
void stackList<T>::pop()
{
	Node<T>* temp;
	temp = head->next;

	if (empty())
	{
		throw std::out_of_range("Stack is Empty");
		exit(0);
	}
	if (temp == NULL){
		head = 0;
	}
	head = temp;
}

template <class T>
T stackList<T>::top()
{
	if (head == NULL) throw std::out_of_range("Stack is Empty");
	return head->data;
}

template <class T>
bool stackList<T>::empty()
{
	if (head == NULL)
		return true;
	return false;
}

template <class T>
void stackList<T>::print()
{
	Node<T>* p = head;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
}