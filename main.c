#include "Static_List.h"


int main()
{
	StaticList* mySlist = Create_SList(10);

	Insertion_Order(mySlist, 4);
	Insertion_Order(mySlist, 0);
	PrintSList(mySlist);
	

	return 0;
}