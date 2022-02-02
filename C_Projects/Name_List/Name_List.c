#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Name_List.h"

List *make_list(void){
		List *ptr;
		ptr = (List *)calloc(1, sizeof(List)); //just returns a pointer where the list starts		
		return ptr;
}

bool add_number(List *list, int num){
	Number *newtop = (Number *)calloc(1, sizeof(Number));
	if(newtop == NULL){
		return false;
	}
	newtop->value = num;				//newtop.value gets the value we passed
	if(list->top != NULL){	
		newtop->prev = list->top;		//newtop.prev gets the existing top
		list->top->next = newtop;		//existing top.ext gets newtop	
	}
	list->top = newtop;				//this is now the new top
											//now the number has been added to the top
	list->size++; 						//increment the size of the list by 1	
	return true;
	
}
	
int pop_number(List *list){	//returns the popped elt
	if(!check_list(list)){return 0;}
	int popped;
	popped = list->top->value;		//so we can return the old value
	list->top = list->top->prev;	//the new top is the previous of the currect top
	free(list->top->next);			//frees the memory
	list->top->next = NULL;			//sets this to null for clarity and we don't reuse
	list->size--;					//decrements the size of the list
	return popped;
}
	
	
int sum_list(List* list){
	if(!check_list(list)){return 0;}
	int sum = 0;
	Number *curr = list->top;	//address of the first elt
	for(int i = 0; i < list->size; i++){
		sum += curr->value;
		curr = curr->prev;			
	}
	return sum;
}

bool print_list(List *list){
	if(!check_list(list)){printf("Can't print an empty list!\n");return false;}
	int stop = list->size, ctr = 0;		//gets the size of the list
	Number *elt = list->top;				//starts off at the top of the list
	
	while(ctr != stop-1){
		elt = elt->prev; 				//gets the first elt of the list has to circle back
		ctr++;
	}
	for(int i = 0; i < stop; i++)
	{
		printf("Val: %d, Adrs of Current: %p, Adrs of previous: %p, Adrs of Next: %p\n", elt->value, elt, elt->prev, elt->next);
		elt = elt->next;						//goes backwards in the list (from top to bottom of the List)
	}
	return true;
}

bool empty_list(List *list){
	if(!check_list(list)){return false;}
	free(list);
	list->top = NULL;
	printf("The list has been cleared!\n");
	return true;
}

bool check_list(List *list){
	if(list->top == NULL){
		printf("Can't perform this action becuase the list is empty!\n");
		return false;
	}
	return true;
}


//MAIN OF THE PROGRAM
int main(void){
	List *myList;
	myList = make_list();	//this is the top of the list
	empty_list(myList);
	add_number(myList, 2);
	add_number(myList, 52);
	add_number(myList, 5);
	add_number(myList, 7);
	add_number(myList, 13);
	print_list(myList);
	printf("Sum of the list: %d\n", sum_list(myList));
	printf("Popped an elt with val: %d\n", pop_number(myList));
	printf("Popped an elt with val: %d\n", pop_number(myList));
	print_list(myList);
	printf("Sum of the list: %d\n", sum_list(myList));
	empty_list(myList);
	print_list(myList);

	return 0;
}







































