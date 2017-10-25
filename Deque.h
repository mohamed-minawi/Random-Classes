#ifndef  DEQUE_H
#define DEQUE_H

template<class type>

class Deque
{

public:

	Deque(int element=128);
	~Deque();
	
	void pushfront(type );
	void popfront();
	void pushback(type);
	void popback();
	type Front() const;
	void Back(type &) const;
	int size() const;
	bool isEmpty() const;
	bool isFull() const;


private:
	struct Node
	{

		type data;
		Node* next;
		Node* prev;
	};

	Node* front;
	Node* rear;
	int count;
	int max;

};
#endif 
#include "Deque.cpp"



