#ifndef OCTET_BAG
#define OCTET_BAG

class Octetbag
{
public:
	
	Octetbag(const Octetbag  &);
	Octetbag();
	~Octetbag();

	bool add(unsigned int);
	bool remove(unsigned int);
	int size();
	bool checkifbelong(unsigned int);
	int countof(unsigned int);
	void clearbag();

	void operator+=(const Octetbag &);
	Octetbag& operator+ (const Octetbag &);
	Octetbag& operator= (const Octetbag &);

private:

	bool ifRightfit(unsigned int);
	
	unsigned int* memory;
	int sizeofbag;

};

#endif 

