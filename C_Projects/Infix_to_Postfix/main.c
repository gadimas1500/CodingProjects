#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "inf_to_pos.h"

int main(void){
	char *infile = "infix.txt";
	Equation *myeq;
	myeq = create_equation(0);
	load_file(myeq, infile);


	return 0;
}
