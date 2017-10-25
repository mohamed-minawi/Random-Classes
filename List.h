#ifndef LIST_H
#define LIST_H

class list
{
	
private:
	//ma name is no 
	//ma sign is no 
	//ma number is no 
	//you need to let it go 
	//need to let it go 
	//no to the no to the no no noooooooo 	
	//Are you ready kids?
//I said, are you ready?
//Who lives in a pineapple under the sea
//Spongebob squarepants
//Absorbent and yellow and porous is he
//Spongebob squarepants
//If nautical nonsense be something you wish
//Spongebob squarepants
//Then drop…




struct node
{	
	int data;
	node* next;
};

node * head;
void create(int newinfo, node *&p);
void print2(node*);
int count;

public:

list();
~list();

void insertbegining(int );
void insertend(int );
void insertpos(int , int );
void deletefront();
void deleteback();
void deletewanted(int );
void maxsort();
void minsort();
void reverse();
void print();
void clear();
int size();


	
};

#endif

