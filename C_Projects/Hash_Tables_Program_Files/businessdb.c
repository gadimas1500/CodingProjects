#include "businessdb_header.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

HashTable *create_hash_table(int size){	//finished	
	HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
	ht->size = size;
	ht->customers = (Person **)calloc(size, sizeof(Person*));
	for(int i = 0; i < size; i++){
		ht->customers[i] = (Person *)malloc(sizeof(Person));
		ht->customers[i] = NULL;
	}
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

void add_person(HashTable *hashtable, char *email, char *name, char *shoe_size, char *favfood){
	int int_hash;
	Person *newperson = (Person*)calloc(1, sizeof(Person));	//creates a new person
	//printf("HASH CREATED: %lu\n", hash(email));
	if(hash(email) % hashtable->size+1 >= hashtable->size){	//creates a new bucket if needed
		//printf("INIF What we want: %lu\n", hash(email) % hashtable->size);
		hashtable->size++;
		hashtable = (HashTable*)realloc(hashtable, 400*hashtable->size);	//making a new bucket

	}
	//printf("OUTIF What we want: %lu\n", hash(email) % hashtable->size);
	int_hash = hash(email) % hashtable->size;	//this is the index to put the person in
	newperson->email = email;
	newperson->name =name;
	newperson->shoe_size = shoe_size;
	newperson->fav_food = favfood;
		//printf("HERE\n");
	if(hashtable->customers[int_hash] == NULL){	//if we are adding a person to the bucket for the first time

		hashtable->customers[int_hash] = newperson;
	} else{	//we are adding a person with other customers
	//we need to iterate until we get to the last person in that bucket
		Person *current = hashtable->customers[int_hash];	//start off with the first person

		while(current->next != NULL){	//keep moving down the list 
			current = current->next;	
		}
		hashtable->customers[int_hash]->next = newperson;	//add this new person as the new customer
	}
}

Person *look_up(HashTable *hashtable, char *email){
 Person *find;
 return find;
}

bool delete_person(HashTable *hashtable, char *email){
	return false;

}

void print_list(HashTable *hashtable){
	for(int i = 0; i < hashtable->size; i++){
		Person *current = hashtable->customers[i];
		if(current == NULL){continue;}
		printf("Name: %s\n Email: %s\n Fav Food: %s\n Shoe Size: %s\n\n", current->name, current->email, current->fav_food, current->shoe_size);
		while(current->next != NULL){
			current = current->next;
		}
	}
}

bool save_progress(void){
	return false;
}

bool free_memory(HashTable *hashtable){
	return false;
}

void load_hash_table(HashTable *hashtable, char *filename, int *size){	//FIXME
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
					shoe_size = atoi(token);	//we've already gone here, so just use it
					break;
				case 2:
					favfood = token;				//assigns the fav food
					break;
				default:
					break;
			}
			count++;
			token = strtok(NULL, "\t");	//separates the word based on the tab
		}
		nums++;
		//here is what we do with all the info
		//printf("%s %s %s %d", email, name, favfood, shoe_size);
		
	}
	*size = nums;
	fclose(infile);
	
}





























