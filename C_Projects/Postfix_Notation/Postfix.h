#pragma once
#include <stdbool.h>

typedef struct Expression Expression;
typedef struct Character Character;
struct Character{
	int data;
	Character *next;
	Character *prev;
};

struct Expression{
	Character *top;
	int size;
};

Expression *make_new_expression(void);

bool add_char(Expression *exp, char num); //adds a number to the expression
													//return true if added successfully, else false

bool check_character(char op);	//checks if we can perform an operation
												//also checks if opperators are in the correct order									

bool print_expression(Expression *exp);	//prints the entire expression


int do_operation(int n1, int n2, char op);		//does the operation
