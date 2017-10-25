#ifndef HEAP
#define HEAP

#include<iostream>
using namespace std;

class Heap
{
	friend ostream& operator<<(ostream&, const Heap&);

public:

	Heap();
	Heap(int);
	Heap(const Heap &);
	~Heap();

	void insert(int);
	int remove();
	
	Heap& operator+(const Heap &);
	Heap& operator+(const int &);
	Heap& operator=(const Heap &);
	void operator+=(const Heap&);
	void operator+=(const int &);
	int operator[](int);
//	void print();

private:

	int* memory;
	int size, current, maxnumber;

	void upheap(int);
	void downheap(int);
	bool IsEmpty();

	


};
#endif
