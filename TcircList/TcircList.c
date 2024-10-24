#include "TcircList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no{
	int info;
	struct no* next;
}TNo;

struct clist{
	TNo* start;
	unsigned int len;
};


TcircList* Circ_list_create(){
	TcircList* list = malloc(sizeof(TcircList));
	if(list != NULL){
		list->start = NULL;
		list->len = 0;
		return list;
	}
}



TNo* No_Create(int info){
	TNo* newNo = malloc(sizeof(TNo));

	if(newNo){
		newNo->info = info;
		(*newNo).next = NULL;
	}
	return newNo;
}

bool Insert_End(TcircList* list, int info){
	TNo* No = No_Create(info);

	if(No == NULL) return false;

	if(list->start == NULL){
		list->start = No;
		No->next = No;
	}
	else{
		TNo* aux = list->start;

		while(aux->next != list->start){
			aux = aux->next;
		}

		aux->next = No;
		No->next = list->start;

	}
	list->len++;
	return true;
}



void Print_List(TcircList* list){
	if(list->len == 0) return;
	TNo* aux = list->start;

	do{
		printf("%d - ", aux->info);
		aux = aux->next;
	}while(aux != list->start);
	putchar('\n');
}

bool Insert_Begin(TcircList* list, int info){
	TNo* No = No_Create(info);

	if(No == NULL) return false;

	if(list->start == NULL){
		list->start = No;
		No->next = No;
	}
	else{
		TNo* aux = list->start;

		while(aux->next != list->start){
			aux = aux->next;
		}

		aux->next = No;
		No->next = list->start;
		list->start = No;
	}
	list->len++;
	return true;
}

bool Remove(TcircList* list, int index){
	if(index > Length(list) || index < 0) return false;

	TNo* ToRemove;
	TNo* aux = list->start;

	if(index == 1){		
		
		while(aux->next != list->start){
			aux = aux->next;
		}

		ToRemove = list->start;
		list->start = ToRemove->next;
		aux->next = list->start;
		
		//printf("%d", ToRemove->info);
		
		free(ToRemove);
	}

	else{

		for(int i=1; i<index-1; i++){
			aux = aux->next;
		}

		ToRemove = aux->next;
		aux->next = ToRemove->next;

		free(ToRemove);
	}
	list->len--;
	return true;
	
}

int Length(TcircList* list){
	return list->len;
}


void clear(){
	//Basta chamar remove e passar 1 como parâmetro em um loop for do tamanho da lista
}









