#include "List.h"
#include<iostream>
using namespace std;

list::list()
{
	head=NULL;
	count=0;
}

list::~list()
{+
	
}

void list::create(int newinfo, node* & p)
{
	node* newnode;
	newnode = new node;
	if (newnode == NULL)

		cout << "ERROr in creating the node";
	else 
	{
		newnode->data = newinfo;
		newnode->next = NULL;

	}
	p=newnode;
	count++;

}

void list::insertbegining(int newinfo)
{ 
	node*p;
	create(newinfo,p);
	
	if (head == NULL)
		head = p;
	else
	{
		p->next = head;
		head = p;
	}

}
void list::insertend(int newinfo)
{
	node*p;
	create(newinfo,p);
	node* temp = head;
	if (head == NULL)
		insertbegining( newinfo);
	else {
		while (temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = p;
	}
	


}
void list::insertpos(int pos, int value)
{
	
	if (head == NULL || pos==0)
		insertbegining(value);
	else {
		
		int counter = 0;
		node*p;
		create(value,p);                  
		node *temp=head;

		 if (temp!=NULL)
		{
			if(pos == counter-1)
			{
					p->next = temp->next;
					temp->next = p;
			}
			else 	temp = temp->next;
			counter++;
		}


	}
}

void list::deleteback()
{
	
	node* temp = head;
	node* prev = head;
	if(head->next==NULL)
	deletefront();
	else
	{
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}

	prev->next = NULL;

	delete temp;
	}
}
void list::deletewanted( int wanted)
{

	
	node* temp = head;
	node* prev = head;
	if (head->data == wanted)
		deletefront();

	else {
		while (temp->data != wanted)
		{
			prev = temp;
			temp = temp->next;
		}

		if (temp->data == wanted)
		{
			prev->next = temp->next;

			delete temp;
		}
	}
}

void list::deletefront()
{
	node *temp = head; // to remove the node
	head = head->next;
	delete temp;
}

void list::maxsort() 
{
	node* temp1, *temp2;
	int value;
	if(head==NULL)
	return;
	
	temp1=head;
	while(temp1!=NULL)
	{	temp2=temp1->next;
		while(temp2!=NULL)
		
		{
			if(temp2->data>temp1->data)
			{
				value=temp2->data;
				temp2->data=temp1->data;
				temp1->data=value;
			}
			temp2=temp2->next;
			
		}
		temp1=temp1->next;
	}
	
	
	
}
void list::minsort()
{
	node* temp1, *temp2;
	int value;
	if(head==NULL)
	return;
	
	temp1=head;
	while(temp1!=NULL)
	{	temp2=temp1->next;
		while(temp2!=NULL)
		{
			if(temp2->data<temp1->data)
			{
				value=temp2->data;
				temp2->data=temp1->data;
				temp1->data=value;
			}
			temp2=temp2->next;
			
		}
		temp1=temp1->next;
	}
	
	
	
}
void list::reverse()
{
	node *current=NULL, *prev=NULL, *next=NULL;
	if(head ==NULL)
	return ;
	current=head;
	while (current !=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		
	}
	head=prev;	
}
void list::print()
{
	print2(head);
}
void list::print2(node *head)
{
	if(head==NULL)
	return;

	
	cout << head->data << endl;
	print2(head->next);
	
}
void list::clear()
{
	while(head!=NULL)
	deleteback();
	count=0;
	
}
int list::size()
{
	return count;
}
