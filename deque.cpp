#include <iostream>


using namespace std;

template<class type>
Deque<type>::Deque(int element)
{
	front = NULL;
	rear = NULL;
	count = 0;
	max = element;
	
}

template<class type>
Deque<type>::~Deque()
{
	
}

template<class type>
void Deque<type>::pushfront(type element)
{
	if (isFull())
	{
		
		return ;
	}
	Node* tmp = new Node();
	tmp->data = element;
	tmp->next = NULL;
	tmp->prev = NULL;
	
	if (isEmpty())
	{
		// Add the first element
		front= tmp;
		rear = tmp;
	}
	else
	{
		// Prepend to the list and fix links
		tmp ->next = front;
		front->prev = tmp;
		front = tmp;
	}

	count++;

}

template<class type>
void Deque<type>::popfront()
{

	if (isEmpty()) {
		
		return;
	}

	// Delete the front node and fix the links
	Node* tmp = front;
	if (front->next != NULL)
	{
		front = front->next;
		front->prev = NULL;
	}
	else
	{
		front = NULL;
	}
	count--;
	delete tmp;

}

template<class type>
void Deque<type>::pushback(type element)
{
	if (isFull())
	{
		return;
	}

	Node* tmp = new Node();
	tmp->data = element;
	tmp->next = NULL;
	tmp->prev = NULL;
	

	if (isEmpty()) {
		// Add the first element
		front = tmp;
		rear = tmp;
	}
	else {
		// Prepend to the list and fix links
		tmp->prev = rear;
		rear->next = tmp;
		rear = tmp;
	}

	count++;

}

template<class type>
void Deque<type>::popback()
{

	if (isEmpty())
	{
		
		return ;
	}

	// Delete the front node and fix the links
	Node* tmp = rear;
	if (rear->prev != NULL)
	{
		rear = rear->prev;
		rear->next = NULL;
	}
	else
	{
		rear = NULL;
	}
	count--;
	delete tmp;

}

template<class type>
type Deque<type>::Front() const
{
	if (isEmpty()) 
	{
		cout << "Deque is empty ";
	}
	return front->data;
}

template<class type>
void Deque<type>::Back(type & element) const
{
	if (isEmpty())
	{
		cout << "Deque is empty ";
	}
	element = rear->data;

}

template<class type>
int Deque<type>::size() const
{
	return count;
}

template<class type>
bool Deque<type>::isEmpty() const
{
	return count == 0;
}

template<class type>
bool Deque<type>::isFull() const
{
	return max==count;
}