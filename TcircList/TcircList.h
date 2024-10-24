#ifndef TCIRCLIST
#define TCIRCLIST
#include <stdbool.h>
typedef struct clist TcircList;

TcircList* Circ_list_create();
bool Insert_End(TcircList*, int);
bool Insert_Begin(TcircList*, int);
bool Remove(TcircList*, int);
int Length(TcircList*);
void Print_List(TcircList*);

#endif