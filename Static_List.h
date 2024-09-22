#ifndef STATICLIST_H
#define STATICLIST_H

#include <stdbool.h>

typedef struct _list StaticList;

StaticList* Create_SList(unsigned int);

bool Insertion_End(StaticList*, int);
//bool Insertion_Beginning(StaticList*, int);
bool Insertion_Order(StaticList*, int);
bool SList_is_full(StaticList*);
bool Insertion_Begin(StaticList*, int, unsigned int);
void PrintSList(StaticList*);


#endif