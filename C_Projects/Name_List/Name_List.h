#pragma once
#include <stdbool.h>
typedef struct Number Number;
typedef struct List List;

struct Number{	//the way to build a Number. A node has a value and a pointer to the next node
	int value; //the value at this node
	Number *next;	//poits to the next number in the list
	Number *prev;

};

struct List{	//The way to build a list
	Number *top;	//the top of the list is a pointer to Number at the top
	int size;
}; 

List *make_list(void);

bool add_number(List *list, int num);

int pop_number(List *list);

int sum_list(List *list);

bool print_list(List *list);

bool empty_list(List *list);

bool check_list(List *list);




