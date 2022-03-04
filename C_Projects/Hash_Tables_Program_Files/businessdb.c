#include "businessdb_header.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

HashTable *create_hash_table(int size){	//finished	
	HashTable *ht = (HashTable *)calloc(size, sizeof(HashTable));
	return ht;
}

bool isNumber(char *s)	//checks if a string is a complete number
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]) == 0)
              return false;
    }
    return true;
}

unsigned long hash(char *email){	//finished
	unsigned long hash = 5381;
	int c;
	while(*email != '\0'){
		c = *email;
		hash = ((hash << 5) + hash) + (unsigned char)c;
		email++;
	}
	return hash;
}

void add_person(HashTable *hashtable, char *email, char *name, int shoe_size, char *favfood){
	int int_hash;
	Person *newperson = (Person*)calloc(1, sizeof(Person));	//creates a new person
	if(hash(email) % hashtable->size+1 >= hashtable->size){	//creates a new bucket if needed
		hashtable->size++;
		hashtable = realloc(hashtable, 4*hashtable->size);	//making a new bucket
	}
	int_hash = hash(email) % hashtable->size;	//this is the index to put the person in
	newperson->email = email;
	newperson->name =name;
	newperson->shoe_size = shoe_size;
	newperson->fav_food = favfood;
	hashtable[int_hash].customers = newperson;
}

Person *look_up(HashTable *hashtable, char *email){
 Person *find;
 return find;
}

bool delete_person(HashTable *hashtable, char *email){
	return false;

}

void print_list(HashTable *hashtable){

}

bool save_progress(void){
	return false;
}

bool free_memory(HashTable *hashtable){
	return false;
}

void load_hash_table(HashTable *hashtable, char *filename, int *size){
	char *out = NULL;
	FILE* infile;
	char buf[50];
	infile = fopen(filename, "r");
	size_t nums = 0;

	for(int i = 0; fgets(buf, 50, infile) != NULL; i++){
		char *email, *favfood;
		char *name;
		int shoe_size;
		out = strndup(buf, 50);					//temp var to hold the string
		char* token = strtok(out, "\t");		//temp var to hold a piece of the string
		int count = 0;								//holds where we are in the string
		while(token != NULL){					//checks the string
			switch(count){
				case 0:
					email = token;					//assigns the email
					break;
				case 1:
					name = token;
					token = strtok(NULL, "\t");//goes onto the next word
					while(atoi(token) == 0){	//checks to see if it's a number for shoe sz
						strcat(name, token);
						token = strtok(NULL, "\t");	//goes onto the next word
					}
					shoe_size = atoi(token);
					break;
				case 2:
					favfood = token;				//assigns the fav food
					break;
			}
			count++;
			token = strtok(NULL, "\t");	//separates the word based on the tab
		}
		nums++;
		//here is what we do with all the info
		//printf("%s %s %s\n", email, name, favfood);
		
	}
	*size = nums;
	fclose(infile);
	
}





























