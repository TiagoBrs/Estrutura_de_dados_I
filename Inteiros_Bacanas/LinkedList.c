#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
	int info;
	struct no* next;
}Tno;

//LinkedList
struct _list
{
	Tno* head;
};





//Função auxiliar que cria um nó

Tno* CreateNo(int info){
	Tno* newNO = malloc(sizeof(Tno));

	if(newNO != NULL)
	{
		newNO->info = info;
		newNO->next = NULL;
	}
	else{
		puts("Erro ao alocar memória para nó.");
	}
	return newNO;

}

LinkedList* Create_LList()
{
	LinkedList* list = malloc(sizeof(LinkedList));

	if(list != NULL){
		list->head = NULL;
	}
	return list;
}

bool Insert_Begin(LinkedList* list, int info){
	Tno* NO = CreateNo(info);

	if(NO == NULL) return false;

	if(list->head != NULL){
		NO->next = list->head;
	}
	list->head = NO;
	return true;
}

bool Insert_End(LinkedList* list, int info){
	Tno* NO = CreateNo(info);

	if(list == NULL) return false;

	if(list->head == NULL){
		list->head = NO;
	}
	else{
		Tno* aux = list->head;

		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = NO;
	}
	return true;

}

void Print_LList(LinkedList* list){
	Tno* aux = list->head;

	while(aux != NULL){
		printf("%d, ", aux->info);
		aux = aux->next;
	}
	putchar('\n');
}

int Square_Digit_List(LinkedList* list){
	Tno* Aux = list->head;
	int number = 0;
	while(Aux != NULL){
		number = number + (Aux->info) * (Aux->info);
		Aux = Aux->next;
	}
	return number;
}

int Last_Int(LinkedList* list){
	Tno* Aux = list->head;

	while(Aux->next != NULL){
		Aux = Aux->next;
	}
	return Aux->info;
}

void Clear_List(LinkedList* list){
	Tno* Aux_atual = list->head;
	Tno* Aux_next;
	while(Aux_atual != NULL){
		Aux_next = Aux_atual->next;
		free(Aux_atual);
		Aux_atual = Aux_next;
	}
	list->head = NULL;

}