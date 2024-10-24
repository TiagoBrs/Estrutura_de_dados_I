#include "DoubleLlist.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	struct node* next;
	struct node* prev;
	int info;
}Node;

struct dl_list
{
	Node* begin;
	Node* end;
	unsigned int len; 
};

DoubleLlist* Create_DLinked_List(){
	DoubleLlist* DLlist = malloc(sizeof(DoubleLlist));

	if(DLlist != NULL){
		DLlist->begin = NULL;
		DLlist->end = NULL;
		DLlist->len = 0;
	}

	return DLlist;
}


Node* Create_Node(int info){
	Node* new_node = malloc(sizeof(Node));

	if(new_node != NULL){
		new_node->next = NULL;
		new_node->prev = NULL;
		new_node->info = info;
	}

	return new_node;
}

bool Insert_End(DoubleLlist* list, int info){
	Node* new_node = Create_Node(info);

	if(!new_node) return false;

	if(list->begin == NULL){

		list->begin = new_node;
		list->end = new_node;
	}

	else{
		list->end->next = new_node;
		new_node->prev = list->end; 
		list->end = new_node;


	}
	list->len++;
	return true;
}

bool Insert_Begin(DoubleLlist* list, int info){
	Node* new_node = Create_Node(info);

	if(!new_node) return false;

	if(list->begin == NULL){

		list->begin = new_node;
		list->end = new_node;
	}

	else{

		list->begin->prev = new_node;
		new_node->next = list->begin;
		list->begin = new_node;

	}
	list->len++;
	return true;
}

void Remove(DoubleLlist* list, int index){
	if(index > Length(list) || index < 1) return;

	Node* toRemove=NULL;

	if(index == Length(list)){

		toRemove = list->end;
		list->end = toRemove->prev;
		toRemove->prev->next = NULL;
	}

	else{
		toRemove = list->begin;

		if(index == 1){
			list->begin = toRemove->next;
		}
		else{
			
			for(int i=1; i<index; i++){
				toRemove = toRemove->next;
			}

			toRemove->prev->next = toRemove->next;
			toRemove->next->prev = toRemove->prev;
		}

		
	}
	free(toRemove);
	list->len--;
}

void Print_List(DoubleLlist* list){
	if(list->len == 0) return;

	Node* aux = list->begin;

	while(aux != NULL){
		printf(" <-- %d --> ", aux->info);
		aux = aux->next;
	}
	putchar('\n');
	
	//Exemplo do aux atualizando: aux = aux->direction;
}

void Print_List_Reverse(DoubleLlist* list){
	if(list->len == 0) return;

	Node* aux = list->end;

	while(aux != NULL){
		printf(" <-- %d --> ", aux->info);
		aux = aux->prev;
	}
	putchar('\n');
	
	//Exemplo do aux atualizando: aux = aux->direction;
}


unsigned int Length(DoubleLlist* list){
	return list->len;
}
