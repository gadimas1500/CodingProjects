#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
typedef struct String String;

struct String{
	int size;
	char *str;
};

String *new_string(char str[]);

void print(String *s);

int length(String *s);

void captilize(String *s);

void capitalize_all(String *s);

bool is_numeric(String *s);

bool is_alpha(String *s);

bool equals(String *s1, String *s2);




//IMPLEMENTATION OF THE HEADINGS
String *new_string(char str[]){	//returns a pointer to the string location
	int size = 0;
	for(int i = 0; str[i] != '\0'; i++){
		size++;
	}
	String *ret = (String *)calloc(1, size);
	ret->size = size;
	ret->str = str; 
	return ret;
}

void print(String *s){
	printf("%s\n", s->str);
}

int length(String *s){
	return s->size;
}

void capitalize(String *s){
	s->str[0] -= 32;

	
	
}

































