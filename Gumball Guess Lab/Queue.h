

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
class Queue;
template <class T>
ostream& operator<< (ostream& out, const Queue<T>& q);


template <class T>
class Queue {
public:
	Queue() {};
	Queue(const Queue<T>& q) {}; //copy constuctor
	Queue<T> operator=(const Queue<T>& q); //allows the user to create a deep copy of the queue
	void enqueue(T data); //inserts data at the back of the queue
	T peek(); //looks at the value at the front of the queue
	void dequeue(); //removes the front of the queue
	bool isEmpty();
	void clear(); //empties the queue
	friend ostream& operator<< (ostream& out, const Queue<T>& q) {
		auto curr = q.front;
		while (curr) {
			out << curr->data;
			if (curr->next) {
				out << " ";
			}
			curr = curr->next;
		}
		return out;
	}; //returns a stream containing all the items in the queue

protected:
	shared_ptr <Node<T>> front = nullptr;
	shared_ptr <Node<T>> back = nullptr;
};

//ALLOWS THE USER TO CREATE A DEEP COPY OF THE QUEUE
template <class T>
Queue<T> Queue<T>::operator=(const Queue<T>& q) {
	if (this == &q) {
		return *this;
	}

	clear();

	shared_ptr<Node<T>> current = q.front;
	while (current) {
		enqueue(current->data);
		current = current->next;
	}
	return *this;
}


//INSERTS DATA AT THE BACK OF THE QUEUE
template <class T>
void Queue<T>::enqueue(T data) {
	auto temp = make_shared<Node<T>>(Node<T>{data, nullptr});
	if (front == nullptr) {
		front = temp;
		back = temp;
		back->next = nullptr;
		return;
	}
	else {
		back->next = temp;
		back = temp;
		back->next = nullptr;

	}
}

//LOOKS AT THE VALUE AT THE FRONT OF THE LIST
template <class T>
T Queue<T>::peek() {
	if (!front) {
		throw runtime_error("List is Empty");
	}
	else {
		return front->data;
	}
}

//REMOVES DATA FROM THE FRONT OF THE LIST
template <class T>
void Queue<T>::dequeue() {
	if (front == nullptr) {
		throw runtime_error("List is Empty");
	}
	else {
		front = front->next;
		return;
	}
}

//CHECKS TO SEE IF LIST IS EMPTY
template <class T>
bool Queue<T>::isEmpty() {
	if (front == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

//EMPTIES EVERYTHING IN THE QUEUE
template <class T>
void Queue<T>::clear() {
	front = nullptr;
	back = nullptr;

}
/*
template <class T>
ostream& operator <<(ostream& out, const Queue<T>& q) {
	auto curr = q.front;
	while (curr) {
		out << curr->data;
		if (curr->next) {
			out << " ";
		}
		curr = curr->next;
	}
	return out;
}
*/