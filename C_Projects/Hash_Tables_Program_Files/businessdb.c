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
		ht->customers[i] = (Person *)calloc(1, sizeof(Person));
		ht->customers[i] = NULL;
	}
	return ht;
}

bool isNumber(char *s)	//checks if a string is a complete number FINISHED
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
	int_hash = hash(email) % hashtable->size;	//this is the index to put the person in
	newperson->email = email;
	newperson->name =name;
	newperson->shoe_size = shoe_size;
	newperson->fav_food = favfood;
	newperson->hash = int_hash;
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

Person *look_up(HashTable *hashtable, char *email){	//finished
	int int_hash = hash(email) % hashtable->size;
	Person *locate = hashtable->customers[int_hash];
	if(locate == NULL){return NULL;}
	do{
			if(strcmp(locate->email, email) == 0){
				return locate;
			}
			if(locate->next == NULL){break;}
			locate = locate->next;
		}while(1);
	return NULL;	//if we've gone through that whole linked list
}

bool delete_person(HashTable *hashtable, char *email){	//finsihed
	int int_hash = hash(email) % hashtable->size;
	Person *locate = hashtable->customers[int_hash];
	Person *prevperson = NULL;
	if(locate == NULL){return false;}
	do{
			if(strcmp(locate->email, email) == 0){
				if(prevperson != NULL){	//if it's not the first thing in the list
					prevperson->next = locate->next;
				} else{						//if it's the first thing in the list
					hashtable->customers[int_hash] = locate->next;
				}
				free(locate);
				return true;
			}
			if(locate->next == NULL){break;}
			prevperson = locate;
			locate = locate->next;
		}while(1);
	return false;	//if we've gone through that whole linked list

}

void print_list(HashTable *hashtable){				//finished
	bool populated = false;
	for(int i = 0; i < hashtable->size; i++){
		Person *current = hashtable->customers[i];
		if(current == NULL){continue;}
		do{
			printf("Name: %s\n Email: %s\n Fav Food: %s\n Shoe Size: %s\nHashindx: %d\n\n", current->name, current->email, current->fav_food, current->shoe_size, current->hash);
			populated = true;
			if(current->next == NULL){break;}
			current = current->next;
		}while(1);
	}
	if(!populated){
		printf("There is no one in your list :(\n");
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
			fprintf(infile, "%c", '\n');
			if(current->next == NULL){break;}
			current = current->next;
		}while(1);

	}
	fclose(infile);
	return true;
}

void free_memory(HashTable *hashtable){	//TODO
	for(int i = 0; i < hashtable->size; i++){
		Person *current = hashtable->customers[i];
		Person *next = NULL;
		if(current == NULL){continue;}	//if there is nothing at this node
		
		if(current->next != NULL){			//if there is a person connected to this (next)
			next = current->next;			
			do{
				free(current);
				if(next->next == NULL){break;}
				current = next;
				next = next->next;
			}while(true);
			
				free(next);
		} else{
			//free this node and move on
				free(current);
		}
	}
	free(hashtable->customers);
	free(hashtable);
}

void load_hash_table(HashTable *hashtable, char *filename){	//finished
	FILE* infile;
	char *out = NULL;
	int byte_size = 200;
	char buf[byte_size];
	infile = fopen(filename, "r");
	for(int i = 0; fgets(buf, byte_size, infile) != NULL; i++){
		char *email, *favfood;
		char *name;
		char *shoe_size;
		out = strndup(buf, byte_size);
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
					shoe_size = token;	
					break;
				case 3:
					strtok(token, "\n");			//removes a trailing \n
					favfood = token;				//assigns the favorite food
					break;
				default:
					break;
			}
			count++;
			token = strtok(NULL, "\t");	//separates the word based on the tab
		}
		add_person(hashtable, email, name, shoe_size, favfood);
	}
	fclose(infile);
	//free(out);
}




































