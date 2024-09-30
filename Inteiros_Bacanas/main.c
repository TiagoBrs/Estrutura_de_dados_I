#include "LinkedList.h"
#include <stdio.h>
#include <stdbool.h>

void Digit_List_Insert(LinkedList*, int);
int main(){

	LinkedList* digit = Create_LList();
	LinkedList* solution = Create_LList();

	int number;

	puts("Number: ");
	scanf("%d", &number);
	Insert_End(solution, number);

	while(Last_Int(solution) > 10){

		Digit_List_Insert(digit, number);
		
		number = Square_Digit_List(digit);
		
		Insert_End(solution, number); 
		Clear_List(digit);
	}
	Print_LList(solution);
	if(Last_Int(solution) == 1){
		puts("bacana");
	}
	else{
		puts("non-bacana");
	}
	return 0;
}
void Digit_List_Insert(LinkedList* list, int number){
	if(number < 10){
		Insert_Begin(list, number);
	}
	else{
		while(number!=0){
		Insert_Begin(list, number%10);
		number = number/10;
		}
	}
}
