#include "OctetSet.h"
#include <cmath>
#include <iostream>
#include <cstdint>
using namespace std;

Octetset::Octetset() :size(8), memory(new unsigned int [8])
{
	for (int i = 0; i < size; i++)
		memory[i] = 0;
}

Octetset::Octetset(const Octetset & old) :size(old.size), memory(new unsigned int[old.size])
{
	for (int i = 0; i < size; i++)
		memory[i] = old.memory[i];
}

Octetset :: ~Octetset()
{
	delete[] memory;
}

void Octetset::add(unsigned int element)
{
	
	if (this->ifRightfit(element))
	{
		if (!this->checkifbelong(element))
		{
			int memorylocation = element / 32;
			int bitlocation = element % 32;
			memory[memorylocation] = ((memory[memorylocation]) | (1 << bitlocation));
		}
		else cout << element<<" is already in the set" << endl;
	}
	else throw string ("The number entered is either larger than 8 bits or negative");
	
}

void Octetset::remove(unsigned int element)
{
	if (this->ifRightfit(element))
	{
		if (this->checkifbelong(element))
		{
			int memorylocation = element / 32;
			int bitlocation = element % 32;
			memory[memorylocation] = ((memory[memorylocation]) ^ (1 << bitlocation));
		}
		else cout << element << " is not in the set" << endl;
	}
	else throw invalid_argument("The number entered is either larger than 8 bits or negative");
	
}
bool Octetset::checkifbelong(unsigned int element)
{
	if (this->ifRightfit(element))
	{
		int memorylocation = element / 32;
		int bitlocation = element % 32;
		if( memory[memorylocation] >> bitlocation & 0x01)
			return true;
		else return false;
	}
	else throw string("The number entered is either larger than 8 bits or negative");
}
bool Octetset::ifRightfit(unsigned int element)
{
	if ( fabs(element / (pow(2, 8))) < 1 )
		return true;
	else return false;
}

//void Octetset::printmemory()
//{
//	for (int i = 0; i < size; i++)
//		std:: cout << memory[i] << "   ";
//	cout << endl;
//}