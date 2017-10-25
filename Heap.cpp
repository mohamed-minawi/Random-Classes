#include "Heap.h"
#include <cmath>
#include <iomanip>

Heap::Heap() : size(500), memory(new int[501]), maxnumber(1000000), current(0)
{
	memory[0] = maxnumber;
}
Heap::Heap(int s):size(s), memory(new int [s+1]), maxnumber(1000000), current(0)
{
	memory[0] = maxnumber;
}
Heap::Heap(const Heap& old)
{
	delete[] memory;
	size = old.size;
	memory = new int[size + 1];
	maxnumber = old.maxnumber;
	current = old.current;
	for (int i = 1; i <=current; i++)
		memory[i] = old.memory[i];
	memory[0] = maxnumber;
}
Heap::~Heap() 
{
	delete [] memory;
}

void Heap::insert(int v)
{	
	if (current < size)
	{
		memory[++current] = v;
		upheap(current);
	}
	else throw invalid_argument("Heap is full, cannot add elements");
}
int Heap::remove()
{
	if (current > 0)
	{
		int v = memory[1];
		memory[1] = memory[current--]; downheap(1);
		return v;
	}
	else throw invalid_argument("No elements in the heap");
}

void Heap::upheap(int k)
{
	int v = memory[k];
	while (memory[k / 2] <= v)
	{
		memory[k] = memory[k / 2];   k = k / 2;
	}
	memory[k] = v;
}
void Heap::downheap(int k)
{
	int j = 2 * k;     int v = memory[k];
	while (j <= current) {
		if ((j < current) && (memory[j] < memory[j + 1])) j++;
		if (v >= memory[j]) break;
		memory[j / 2] = memory[j];     j *= 2;
	}
	memory[j / 2] = v;
}
bool Heap::IsEmpty()
{
	return current == 0;
}

Heap& Heap::operator+(const Heap & old)
{
	Heap *x=new Heap(old.current +current);
	for (int i = 1; i <= current;i++)
		x->insert(memory[i]);
	
	for (int i = 1; i <= old.current; i++)
		x->insert(old.memory[i]);

		return *x;
}
Heap& Heap::operator+(const int & newint) 
{
	Heap *x = new Heap(*this);
	x->insert(newint);
	return *x;
}
Heap& Heap::operator=(const Heap & old) 
{
	delete[] memory;
	size = old.size;
	memory = new int[size + 1];
	maxnumber = old.maxnumber;
	current = old.current;
	for (int i = 1; i <= current; i++)
		memory[i] = old.memory[i];
	memory[0] = maxnumber;

	return *this;
}
void Heap::operator+=(const Heap& old) 
{
	for (int i = 1; i <= old.current; i++)
		insert(old.memory[i]);
}
void Heap::operator+=(const int & newint) 
{
	insert(newint);
}
int Heap::operator[](int z) 
{
	Heap x(*this);
	int hi=-1;
	for (int i = 0; i <z+1; i++)
		hi = x.remove();
	return hi;
}

ostream& operator<<(ostream& out, const Heap & x)
{
	int y = 4*x.current;
	int counter = 0;
	for (int i = 1; i <= log2(x.current)+1; i++)
	{
		for (int j = pow(2, i-1); j < pow(2, i); j++)
			if(j<=x.current)
			out <<setw(y)<< x.memory[j] << "    ";
		y = y / 2;
		out << endl;
	}
	return out;
}