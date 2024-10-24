#include "TcircList.h"
#include <stdio.h>
int main(){
	TcircList* MyList = Circ_list_create();
	Insert_End(MyList, 1);
	Insert_End(MyList, 2);
	Insert_End(MyList, 3);

	Insert_Begin(MyList, 4);
	Insert_Begin(MyList, 5);

	Print_List(MyList);
	
	Print_List(MyList);
}