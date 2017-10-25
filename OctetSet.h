#ifndef OCTET_SET
#define OCTET_SET

class Octetset
{
public:

	Octetset();
	Octetset(const Octetset &);
	~Octetset();

	void add(unsigned int);				// Function to add a number to set of Octets
	void remove(unsigned int);			// Function
	bool checkifbelong(unsigned int);
//	void printmemory();
	
private:
	unsigned int * memory;
	int size;
	bool ifRightfit(unsigned int);
};

#endif 

