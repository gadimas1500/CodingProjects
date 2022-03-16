#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct{
	char val;
	struct Operand *next;

} Operand;

typedef struct{
	Operand *top;
	int size;
	
}	Equation;

Equation *create_equation(int size);
//create the equation for the program

Equation *change_to_postfix(Equation *eq, char *equation);
//the way a computer would see it where all the operands are on the end

bool load_file(Equation *eq, char *filename);
//loads a file into the equation we have (if applicable)

bool save_file(Equation *eq, char *filename);
//saves the written equation into the current file

void print_equation(Equation *eq);
