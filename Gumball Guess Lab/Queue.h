

#pragma once

#include <iostream>
#include <queue>

using std::ostream;
using std::shared_ptr;
using std::make_shared;
using std::runtime_error;

template <class T>
struct Node {
	T data;
	shared_ptr<Node<T>> next;
};

template <class T>
class Queue {
public:
	Queue() {};
	Queue(const Queue<T>& q) {}; //copy constuctor
	Queue<T> operator=(const Queue<T>& q);
	void enqueue(T data); //inserts data at the back of the queue
	T peek(); //looks at the value at the front of the queue
	void dequeue(); //removes the front of the queue
	bool isEmpty();
	void clear(int count); //empties the queue
	friend ostream& operator<< (ostream& out, const Queue<T>& q); //returns a stream containing all the items in the queue

protected:
	shared_ptr <Node<T>> front;
	shared_ptr <Node<T>> back;
};

template <class T>
Queue<T> Queue<T>::operator=(const Queue<T>& q) {

}


template <class T>
void Queue<T>::enqueue(T data) {
	auto temp = make_shared<Node<T>>();
	if (!front) {
		front = data;
		back = data;
		back->next = nullptr;
	}
	else {
		back->next = data;
		back->next = nullptr;

	}
}

template <class T>
T Queue<T>::peek() {
	if (!front) {
		throw runtime_error("List is Empty");
	}
	else {
		auto currentNode = front;
		return currentNode;
	}
}

template <class T>
void Queue<T>::dequeue() {
	if (!front) {
		throw runtime_error("List is Empty");
	}
	else {
		front->next = front;
		return;
	}
}

template <class T>
bool Queue<T>::isEmpty() {
	if (!front) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
void Queue<T>::clear(int count) {
	
}

template <class T>
ostream& operator <<(ostream& out, const Queue<T>& q) {

}