/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Simeon Aleksandrov
* @idnumber 61916
* @task 2
* @compiler Visual C++
*
*/
#pragma once
#include<iostream>

template<class T>
class Queue
{
public:
	Queue();
	bool isEmpty();
	void enqueue(T data);
	void dequeue();
	T getFirstToEnter(); //peek


private:
	struct Node {
		T date;
		Node *next;
	};

	Node *frontPtr;
	Node *backPtr;
	int count;

};


template<class T>
Queue<T>::Queue()
{
	frontPtr = NULL;
	backPtr = NULL;
	count = 0;
}

template<class T>
bool Queue<T>::isEmpty() {
	return(count == 0);
}


template<class T>
void Queue<T>::enqueue(T data) {
	Node *newOne = new Node;
	newOne->date = data;
	newOne->next = NULL;
	if (isEmpty()) {
		frontPtr = newOne;
	}
	else {
		backPtr->next = newOne;
	}
	backPtr = newOne;
	count++;
}

template<class T>
void Queue<T>::dequeue() {
	if (isEmpty()) {
		std::cout << "Nothing inside" << std::endl;
	}
	else {
		Node *temp = frontPtr;
		if (frontPtr == backPtr) {
			frontPtr = NULL;
			backPtr = NULL;
		}
		else {
			frontPtr = frontPtr->next;
		}
		delete temp;
		count--;
	}
}

template<class T>
T Queue<T>::getFirstToEnter()
{
	T temp = frontPtr->date;
	return temp;
}
