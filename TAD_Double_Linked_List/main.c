#include "DoubleLlist.h"

int main()
{
	DoubleLlist* MyList = Create_DLinked_List();
	Insert_End(MyList, 4);
	Insert_End(MyList, 5);
	Insert_End(MyList, 6);

	Insert_Begin(MyList, 3);
	Insert_Begin(MyList, 2);
	Insert_Begin(MyList, 1);

	Print_List(MyList);
	//Print_List_Reverse(MyList);

	Remove(MyList, 6);
	Remove(MyList, 1);
	Remove(MyList, 3);

	Print_List(MyList);

	return 0;
}