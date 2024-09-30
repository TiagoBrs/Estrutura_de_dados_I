#ifndef LINKEDLIST
#define LINKEDLIST
#include <stdbool.h>
typedef struct _list LinkedList;

LinkedList* Create_LList();

bool Insert_End(LinkedList*, int);
bool Insert_Begin(LinkedList*, int);

int Square_Digit_List(LinkedList*);
int Last_Int(LinkedList*);
void Clear_List(LinkedList*);

void Print_LList(LinkedList*);


#endif