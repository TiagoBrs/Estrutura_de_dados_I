#include "Static_List.h"
#include <stdlib.h>
#include <stdio.h>

// Type StaticList
struct _list
{
	unsigned int qty;
	unsigned int size;
	int* data;
};

StaticList* Create_SList(unsigned int size)
{
	StaticList* SList = malloc(sizeof(StaticList));

	if(SList != NULL)
	{
		SList->data = (int*) malloc(sizeof(int)*size);
		if(SList->data == NULL)
		{
			free(SList);
			return NULL;
		}
		SList->qty = 0;
		SList->size = size;
	}
	return SList;
}



bool Insertion_End(StaticList* list, int element)
{
	if(SList_is_full(list))
	{
		return false;
	}
	list->data[list->qty++] = element;
	return true;
}



/*
bool Insertion_Beginning(StaticList* list, int element)
{
	if(SList_is_full(list))
	{
		return false;
	}

	for(unsigned int i=(list->qty); i>0; i--)
	{
		list->data[i] = list->data[i-1];
	}
	list->data[0] = element;
	list->qty++;
}
*/


bool Insertion_Begin(StaticList* list, int element, unsigned int start)
{
	if(SList_is_full(list))
	{
		return false;
	}

	for(unsigned int i=(list->qty); i>start; i--)
	{
		list->data[i] = list->data[i-1];
	}
	list->data[start] = element;
	list->qty++;
}


bool Insertion_Order(StaticList* list, int element)
{
	if(SList_is_full(list)) return false;
	if(list->qty == 0)
	{
		list->data[list->qty++] = element;
		return true;
	}
	int i=0;

	while(element > list->data[i])
	{
		i++;
	}

	return Insertion_Begin(list, element, i);

}




bool SList_is_full(StaticList* list)
{
	return list->qty == list->size;
}


void PrintSList(StaticList* list)
{
	for(int i=0; i<list->qty; i++)
	{
		printf("%d - ", list->data[i]);
	}
	putchar('\n');
}



