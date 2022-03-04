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

void add_person(HashTable *hashtable, char *email, char *name, char *shoe_size, char *favfood){	//finished
	int int_hash;
	Person *newperson = (Person*)calloc(1, sizeof(Person));	//creates a new person
	if(hash(email) % hashtable->size+1 >= hashtable->size){	//creates a new bucket if needed
		hashtable->size++;
		hashtable = (HashTable*)realloc(hashtable, 400*hashtable->size);	//making a new bucket

	}
	//printf("OUTIF What we want: %lu\n", hash(email) % hashtable->size);
	int_hash = hash(email) % hashtable->size;	//this is the index to put the person in
	newperson->email = email;
	newperson->name =name;
	newperson->shoe_size = shoe_size;
	newperson->fav_food = favfood;
	newperson->hash = int_hash;
	printf("We have a %d size and want to access %d -> %s\n", hashtable->size, int_hash, newperson->name);
	if(hashtable->customers[int_hash] == NULL){	//if we are adding a person to the bucket for the first time
		hashtable->customers[int_hash] = newperson;
	} else{	//we are adding a person with other customers
	//we need to iterate until we get to the last person in that bucket
		Person *current = hashtable->customers[int_hash];	//start off with the first person

		while(current->next != NULL){	//keep moving down the list 
			current = current->next;	
		}
		current->next = newperson;	//add this new person as the new customer
	}
}

Person *look_up(HashTable *hashtable, char *email){
 Person *find;
 return find;
}

bool delete_person(HashTable *hashtable, char *email){
	return false;

}

void print_list(HashTable *hashtable){				//finished
	for(int i = 0; i < hashtable->size; i++){
		Person *current = hashtable->customers[i];
		if(current == NULL){continue;}
		do{
			printf("Name: %s\n Email: %s\n Fav Food: %s\n Shoe Size: %s\n\n", current->name, current->email, current->fav_food, current->shoe_size);
			if(current->next == NULL){break;}
			current = current->next;
			
		}while(1);
	}
}

bool save_progress(HashTable *hashtable, char* filename){	//finished
	FILE *infile;
	infile = fopen(filename, "w");	//open for writing
	//fprintf(fptr,"%d",num);
	if(infile == NULL){return false;}
	for(int i = 0; i < hashtable->size; i++){
		Person *current = hashtable->customers[i];
		if(current == NULL){continue;}
		do{
			fprintf(infile, "%s", current->email);
			fprintf(infile, "%c", '\t');
			fprintf(infile, "%s", current->name);
			fprintf(infile, "%c", '\t');
			fprintf(infile, "%s", current->shoe_size);
			fprintf(infile, "%c", '\t');
			fprintf(infile, "%s", current->fav_food);
			fprintf(infile, "%c", '\t');
			fprintf(infile, "%lu", current->hash);
			fprintf(infile, "%c", '\n');
			if(current->next == NULL){break;}
			current = current->next;
		}while(1);

	}
	fclose(infile);
	return true;
}

bool free_memory(HashTable *hashtable){
	return false;
}

void load_hash_table(HashTable *hashtable, char *filename, int *size){	
	char *out = NULL;
	FILE* infile;
	int byte_size = 100;
	char buf[byte_size];
	infile = fopen(filename, "r");
	size_t nums = 0;

	for(int i = 0; fgets(buf, byte_size, infile) != NULL; i++){
		char *email, *favfood;
		char *name;
		char *shoe_size;
		out = strndup(buf, byte_size);					//temp var to hold the string
		char* token = strtok(out, "\t");		//temp var to hold a piece of the string
		int count = 0;								//holds where we are in the string
		while(token != NULL){					//checks the string
			switch(count){
				case 0:
					email = token;					//assigns the email
					break;
				case 1:
					name = token;
					break;
				case 2:
					shoe_size = token;	//we've already gone here, so just use it
					break;
				case 3:
					token[strlen(token) - 1] = '\0';	//removes a trailing \n
					favfood = token;				//assigns the favorite food
					break;
				default:
					break;
			}
			count++;
			token = strtok(NULL, "\t");	//separates the word based on the tab
		}
		nums++;
		add_person(hashtable, email, name, shoe_size, favfood);
	}

	*size = nums;
	fclose(infile);
	
}





























