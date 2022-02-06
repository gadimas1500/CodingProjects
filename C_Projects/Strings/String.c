#include <stdio.h>
#include "String.h"

int main(void){
	String *water = new_string("hello, World!");
	char some[] = "something in the water";
	some[0] -= 32;
	printf("%s\n", some);
	print(water);
	capitalize(water);
	printf("%d\n", length(water));
	print(water);

	return 0;
}


