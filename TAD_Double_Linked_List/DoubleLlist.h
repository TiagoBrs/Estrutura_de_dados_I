#ifndef DOUBLELLIST_H
#define DOUBLELLIST_H
#include <stdbool.h> 

typedef struct dl_list DoubleLlist;

DoubleLlist* Create_DLinked_List();

bool Insert_End(DoubleLlist*, int);
bool Insert_Begin(DoubleLlist*, int);

void Print_List(DoubleLlist*);
void Print_List_Reverse(DoubleLlist*);
void Remove(DoubleLlist*, int);

unsigned int Length(DoubleLlist*);

#endif