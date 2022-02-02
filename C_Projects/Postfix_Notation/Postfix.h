#pragma once
#include <stdbool.h>

typedef struct Expression Expression;
typedef struct Character Character;
struct Character{
	int intVal;
	char opVal;						//can be a char or int
	Character *next;
	Character *prev;
};

struct Expression{
	Character *top;
	int size;
	int nums;
	int ops;
};

Expression *make_new_expression(void);

bool add_number(Expression *exp, int num); //adds a number to the expression
													//return true if added successfully, else false

bool add_operator(Expression *exp, char op);

float get_reduced(Expression *exp, Expression **initAdrs);	//returns the reduced form of operation only of first term

bool check_expression(Expression *exp);	//checks if we can perform an operation
												//also checks if opperators are in the correct order									
void clear_expression(Expression *exp);	//clears the expression to make a new one

bool print_expression(Expression *exp);	//prints the entire expression

bool delete_values(Expression *exp, Character *value, int newValue, Expression *initAdrs);		//pops an operator to the list

float do_operation(int n1, int n2, char op);		//does the operation
