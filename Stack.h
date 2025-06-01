/**
Lab #3
	Group CPP2
	Team Memebers: Jesus Urias, Nhung Vo
	Purpose: The purpose of this lab is implement a modular ADT for any currency
**/
#pragma once

#include "SinglyLinkedList.h"

class Stack : SinglyLinkedList {
public:
	Stack()=default;
	~Stack() {
		emptyStack();
	}

	void push(Currency* obj);
	Currency* pop();
	Currency* peek();
	std::string stringifyStack();
	void emptyStack();
};
/**
Method push(obj)
	-Will add a currency obj to the end of the stack
	Pre:obj - a currency objcet
	Post: count - will increment by one
		  end - will change to another LinkNode holding the new currency obj
		  start - Will change if it is the first LinkNode being added or LinkNode->next will change if it is the second node
	Return:
**/
void Stack::push(Currency* obj) {
	// get the new top's index which is count
	int index = countCurrency();

	// add this object to the end (top) of the stack
	addCurrency(obj, index);
}
/**
Method pop()
	-Will remove the LinkNode from the top(end) of the list and return its currency
	Pre:
	Post: count - will decrement by one if the stack is not empty
		  end - will change pointer to next node or nullptr or no change if it
		  start - will change if it is the last item being removed, the next will also change if 2nd node is removed.
	Return: currency - will remove the currency from the top of the list.
**/
Currency* Stack::pop() {
	// get the top's index which is count - 1
	int index = countCurrency() - 1;

	// remove the top and return the data
	return removeCurrency(index);
}
/**
Method peek()
	-Will return what is at the top of the stack without removing it.
	Pre:
	Post:
	Return: currency - will return the currency at the top of the list
**/
Currency* Stack::peek() {
	// get the top's index which is count - 1
	int index = countCurrency() - 1;

	// peek the top and return data
	return getCurrency(index);
}
/**
Method stringifyStack()
	-Will take every data from each node on the Stack and convert it into a string.
	Pre:
	Post:
	Return: string - a concatinated string of all the data.
**/
std::string Stack::stringifyStack() {
	return stringifyList();
}
/**
Method emptyStack()
	-This function will empty the complete stack while deleting all the pointer references.
	Pre:
	Post: count - goes to 0
		  start - set to nullptr
		  end - set to nullptr
	Return:
**/
void Stack::emptyStack() {
	emptyList();
}

