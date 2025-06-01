/**
Lab #3
	Group CPP2
	Team Memebers: Jesus Urias, Nhung Vo
	Purpose: The purpose of this lab is implement a modular ADT for any currency
**/
#pragma once

#include "Stack.h"

class Queue :  SinglyLinkedList {
public:
	Queue()=default;
	~Queue() {
		emptyQueue();
	}

	void enqueue(Currency* obj);
	Currency* dequeue();
	Currency* peekFront();
	Currency* peekRear();
	std::string stringifyQueue();
	void emptyQueue();
};
/**
Method enqueue(obj)
	-Will add a currency obj to the end of the queue
	Pre:obj - a currency objcet
	Post: count - will increment by one
		  end - will change to another LinkNode holding the new currency obj
		  start - Will change if it is the first LinkNode being added or LinkNode->next will change if it is the second node
	Return:
**/
void Queue::enqueue(Currency* obj)  {
	// get the new rear's index which is count
	int index = countCurrency();

	// add this object to the rear of the queue
	addCurrency(obj, index);
}
/**
Method dequeue()
	-Will delete the Node at the start of the queue and return the currency in it.
	Pre:
	Post: count - will decrement by one if the stack is not empty
		  end - will change if it is the last item being removed, the next will also change if 2nd node is removed.
		  start - will change pointer to next node or nullptr if dequeuing the last item or no change if it
	Return: currency - will remove the currency from the top of the list.
**/
Currency* Queue::dequeue() {
	// remove the start and return the data
	return removeCurrency(0);
}
/**
Method peekFront()
	-Will return what is at the front of the queue without removing it.
	Pre:
	Post:
	Return: currency - will return the currency at the front of the queue
**/
Currency* Queue::peekFront() {
	// peek the front and return data
	return getCurrency(0);
}
/**
Method peekRear()
	-Will return what is at the end of the queue without removing it.
	Pre:
	Post:
	Return: currency - will return the currency at the end of the list
**/
Currency* Queue::peekRear() {
	// get the rear's index which is count - 1
	int index = countCurrency() - 1;

	// peek the rear and return data
	return getCurrency(index);
}
/**
Method stringifyQueue()
	-Will take every data from each node on the list and convert it into a string.
	Pre:
	Post:
	Return: string - a concatinated string of all the data.
**/
std::string Queue::stringifyQueue() {
	return stringifyList();
}
/**
Method emptyQueue()
	-This function will empty the complete queue while deleting all the pointer references.
	Pre:
	Post: count - goes to 0
		  start - set to nullptr
		  end - set to nullptr
	Return:
**/
void Queue::emptyQueue() {
	emptyList();
}
