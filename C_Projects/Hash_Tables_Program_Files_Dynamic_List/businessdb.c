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

HashTable *add_one_spot(HashTable *hashtable){
	hashtable = (HashTable*)realloc(hashtable, 4 * hashtable->size);	//add a new size to the hash table
	hashtable->size++;
	int size = hashtable->size;
	hashtable->customers[size] = (Person *)malloc(sizeof(Person));
	hashtable->customers[size] = NULL;	
	return hashtable;
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
	int_hash = hash(email) % hashtable->size;	//this is the index to put the person in
	if(int_hash+1 >= hashtable->size){	//creates a new bucket if needed
		printf("%s Wants position: %d\n", name, int_hash);
		hashtable = add_one_spot(hashtable);	//adds a spot to the hash
		int_hash = hash(email) % hashtable->size;	//this is the index to put the person in
	}
	newperson->email = email;
	newperson->name =name;
	newperson->shoe_size = shoe_size;
	newperson->fav_food = favfood;
	newperson->hash = int_hash;
	printf("%s Stored hash: %d\n", newperson->name, newperson->hash);
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
	int int_hash = hash(email) % hashtable->size;
	Person *locate = hashtable->customers[int_hash];
	printf("Looooooking at hash %d which true hash is %d\n", int_hash, hashtable->customers[int_hash]->hash);
	do{
			if(strcmp(locate->email, email) == 0){
				return locate;
			}
			if(locate->next == NULL){break;}
			locate = locate->next;
		}while(1);
	return NULL;	//if we've gone through that whole linked list
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
			fprintf(infile, "%d", current->hash);
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
	int byte_size = 200;
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
		nums++;
		add_person(hashtable, email, name, shoe_size, favfood);
	}

	*size = nums;
	fclose(infile);
}
HashTable *load_from_hash_table(HashTable *hashtable, int size){
	HashTable *newhash = create_hash_table(size);
	for(int i = 0; i < size; i++){
		Person *current = hashtable->customers[i];
		if(current == NULL){continue;}
		do{
			int int_hash = hash(current->email) % size;
			printf("HAD: %d NEW HASH %d\n", current->hash, int_hash);
			if(newhash->customers[int_hash] == NULL){
				newhash->customers[int_hash] = current;
			} else{
				Person *position = newhash->customers[int_hash];	//something already exists there
				do{
					if(position->next == NULL){break;}
					position = position->next;
				}while(1);
				position->next = current;
			}
			if(current->next == NULL){break;}
			newhash->customers[int_hash]->hash = int_hash;
			current = current->next;
		}while(1);
	}
	return newhash;
}




































