//Nathan Ashley
/*-- ListLinked.cpp------------------------------------------------------------
   This file implements the ListLinked member functions.
-------------------------------------------------------------------------*/
#include "ListLinked.h"
#include <cstddef>
#include <iostream>
using namespace std;

/* Constructor  */
ListLinked::ListLinked()
{
	first = NULL;
}

/* destructor - clean up memory for remaining nodes in list */
ListLinked::~ListLinked()
{
	Node* temp;
	temp = first;
	while (temp != NULL)
	{
		Node* save = temp;
		temp = temp->next;
		delete save;
	}
}


/* empty */
bool ListLinked::empty()
{
	if (first == NULL)
		return true;
	else
		return false;
}

/* display */
void ListLinked::display()
{
	Node* temp;
	temp = first;
	while (temp != NULL)
	{
		cout << temp->data << ",";
		temp = temp->next;
	}
	cout << endl;
}

/* insert element in position */
void ListLinked::insert(ElementType e, int preptr_value)
{
	
	

	
	
	Node* newptr = new Node(e);
	if (first == NULL) //insert the very first element
	{
		newptr->next = NULL;
		first = newptr;
	}
	else
	{
		
			Node* preptr;
			preptr = first;
			//nav here to node before the node we want to insert
					
			//for (int i = 0; i < preptr_value - 1; i++)
			//new code goes here
			while (preptr!= NULL && preptr->data != preptr_value)
				preptr = preptr->next;
			//insertion code
			if (preptr != NULL)
			{
				newptr->next = preptr->next;
				preptr->next = newptr;
			}
			else
				cout << "Error, No "<< preptr_value << " exists."<<endl;
		}
	
}

/* Remove specified element from the list at a specific position */
void ListLinked::erase(int preptr_value)
{
	if (preptr_value == 0) //delete the first element
	{
		Node* ptr = first;
		first = ptr->next;
		delete(ptr);
	}
	else
	{
		Node* preptr;
		preptr = first;
		
		//Navigate same way as insert 
		while (preptr != NULL && preptr->data != preptr_value)
		{
			preptr = preptr->next;
		}
		//deletion logic this does not change
		Node* ptr = preptr->next;
		preptr->next = ptr->next;
		delete(ptr);
	}
}

