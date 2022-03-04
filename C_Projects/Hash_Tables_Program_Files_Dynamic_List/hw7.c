#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "businessdb_header.h"
#define NUM_BUCKETS 1 //this is the initial size of the bucket



int main(void){

//we have to read from a file
//we have to promt the user from the commands until they want to exit
	HashTable *myhash;
	myhash = create_hash_table(NUM_BUCKETS);
	int line_nums;
	load_hash_table(myhash, "customers.tsv", &line_nums);
	HashTable *newtable;
	newtable = load_from_hash_table(myhash, myhash->size);
	myhash = newtable;
	printf("LOADED: %d\n", myhash->size);
	int load_size = 40;
	char user_input[load_size];
	do{
		printf("Command: ");
		fgets(user_input, load_size, stdin);
		printf("\n");
		if(strcmp(user_input, "add\n") == 0){
			printf("going to add\n");
			char *name, *fav_food, *email, *shoe_size;
			
			printf("Enter name: ");
			fgets(user_input, load_size, stdin);
			name = strndup(user_input, load_size);
			strtok(name, "\n");	//removes the \n char
			
			printf("Enter email: ");
			fgets(user_input, load_size, stdin);
			email = strndup(user_input, load_size);
			strtok(email, "\n");	//removes the \n char
			
			printf("Enter favorite food: ");
			fgets(user_input, load_size, stdin);
			fav_food = strndup(user_input, load_size);
			strtok(fav_food, "\n");	//removes the \n char
			
			printf("Enter shoe size: ");
			fgets(user_input, load_size, stdin);
			shoe_size = strndup(user_input, load_size);
			strtok(shoe_size, "\n");	//removes the \n char
			
			add_person(myhash, email, name, shoe_size, fav_food);
			HashTable *newtable;
			newtable = load_from_hash_table(myhash, myhash->size);
			myhash = newtable;
			
		} else if(strcmp(user_input, "lookup\n") == 0){
			char *lookup;
			Person *person;
			printf("Enter email you want to find: ");
			fgets(user_input, load_size, stdin);
			lookup = strndup(user_input, load_size);
			strtok(lookup, "\n");	//removes the \n char
			person = look_up(myhash, lookup);
			if(person != NULL){
				printf("Name: %s\n Email: %s\n Fav Food: %s\n Shoe Size: %s\n\n", person->name, person->email, person->fav_food, person->shoe_size);
			} else{
				printf("There was no such person with that key!\n");
			}
			//TODO we need to make a new hashtable with the new hashes
			
		}else if(strcmp(user_input, "delete\n") == 0){
					printf("going to delete\n");
		}else if(strcmp(user_input, "list\n") == 0){
					printf("going to list\n");
		}else if(strcmp(user_input, "save\n") == 0){
					printf("going to save\n");
					if(save_progress(myhash, "customers.tsv")){
						printf("Your progress has been saved successfully!\n");
					} else{
						printf("There was an error saving your progess!\n");
					}
		}else if(strcmp(user_input, "print\n") == 0){
					print_list(myhash);
		}

	}while(strcmp(user_input, "quit\n") != 0);
	return 0;
}
