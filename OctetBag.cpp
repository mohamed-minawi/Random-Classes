#include "OctetBag.h"
#include <iostream>
#include <cmath>
using namespace std;

Octetbag::Octetbag(): sizeofbag(0),memory (new unsigned int[256])
{
	for (int i = 0; i < 256; i++)
		memory[i] = 0;
}
Octetbag::Octetbag(const Octetbag  & old) : sizeofbag(old.sizeofbag), memory(new unsigned int[256])
{
	for (int i = 0; i < 256; i++)
		memory[i] = old.memory[i];
}
Octetbag::~Octetbag()
{
	delete[] memory;
}

bool Octetbag::add(unsigned int x)
{

	if (ifRightfit(x))				 
	{
		if (memory[x] < (pow(2, 8*sizeof(unsigned int)) - 1))
		{
			memory[x]++;
			sizeofbag++;
			return true;
		}
		else return false;
	}
	else throw invalid_argument("The number entered is either larger than 8 bits or negative");

}
bool Octetbag::remove(unsigned int x)
{
	
	if (ifRightfit(x))
	{
		if (checkifbelong(x))
		{
			memory[x]--;
			sizeofbag--;
			return true;
		}
	}
	else throw invalid_argument("The number entered is either larger than 8 bits or negative");
 return false;
}
int Octetbag::countof(unsigned int x)
{
	
	if (ifRightfit(x))
	{
		if (checkifbelong(x))
		{
			return memory[x];
		}
	}
	else throw invalid_argument("The number entered is either larger than 8 bits or negative");
	return 0;
}
int Octetbag::size()
{
	return sizeofbag;
}
void Octetbag::clearbag()
{
	for (int i = 0; i < 256; i++)
		memory[i] = 0;
	sizeofbag = 0;
}
void Octetbag::operator+=(const Octetbag & second)
{
	for (int i = 0; i < 256; i++)
		memory[i] += second.memory[i];
	sizeofbag += second.sizeofbag;
}
Octetbag& Octetbag::operator+ (const Octetbag & second)
{
	Octetbag *x = new Octetbag(second);
	x->sizeofbag += sizeofbag;
	for (int i = 0; i < 256; i++)
		x->memory[i] += memory[i];
	return *x;
}
Octetbag& Octetbag::operator= (const Octetbag & second)
{
	for (int i = 0; i < 256; i++)
		memory[i] = second.memory[i];
	sizeofbag = second.sizeofbag;
	return *this;
}

bool Octetbag::checkifbelong(unsigned int x)
{
	if (ifRightfit(x))
	{
		if (memory[x] > 0)
			return true;
		
	}
	else throw invalid_argument("The number entered is either larger than 8 bits or negative");
	
	return false;
}
bool Octetbag::ifRightfit(unsigned int element)
{
	if (fabs(element / (pow(2, 8))) < 1)
		return true;
	else return false;
}

