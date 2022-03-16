#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "inf_to_pos.h"

Equation *create_equation(int size){
	Equation *eq = (Equation *)malloc(sizeof(Equation));
	eq = NULL;
	return eq;
}

Equation *change_to_postfix(Equation *eq, char *equation){

return NULL;

}

bool save_file(Equation *eq, char *filename){
	return false;
}

bool load_file(Equation *eq, char *filename){
	FILE *infile;
	infile = fopen(filename, "r");
	char c;
	c = fgetc(infile);
	while(c != 10){
		strtok(&c, "\n");
		printf("%c\n", c);
		c = fgetc(infile);
		eq->size++;
		eq = realloc(eq, size * sizeof(Operand));
		Operand *cur = eq->top;

	}
	printf("\n");
	fclose(infile);
	return false;
}

void print_equation(Equation *eq){

}
