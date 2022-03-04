#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "businessdb_header.h"
#define NUM_BUCKETS 4 //this is the initial size of the bucket



int main(void){

//we have to read from a file
//we have to promt the user from the commands until they want to exit
	HashTable *myhash;
	myhash = create_hash_table(NUM_BUCKETS);
	int line_nums;
	load_hash_table(myhash, "customers.tsv", &line_nums);
	printf("LOADED: %d\n", myhash->size);

	char user_input[20];
	do{
		printf("Command: ");
		fgets(user_input, 20, stdin);
		if(strcmp(user_input, "add\n") == 0){
			printf("going to add\n");
			char *name, *fav_food, *email, *shoe_size;
			//int shoe_size;
			
			printf("Enter name: ");
			fgets(user_input, 20, stdin);
			name = strndup(user_input, 20);
			strtok(name, "\n");	//removes the \n char
			printf("NAME: %s\n", name);
			
			printf("Enter email: ");
			fgets(user_input, 30, stdin);
			email = strndup(user_input, 30);
			strtok(email, "\n");	//removes the \n char
			printf("EMAIL: %s\n", email);
			
			printf("Enter favorite food: ");
			fgets(user_input, 20, stdin);
			fav_food = strndup(user_input, 20);
			strtok(fav_food, "\n");	//removes the \n char
			printf("FAV_FOOD: %s\n", fav_food);
			
			printf("Enter shoe size: ");
			fgets(user_input, 20, stdin);
			shoe_size = strndup(user_input, 20);
			strtok(shoe_size, "\n");	//removes the \n char
			printf("SHOE_SIZE: %s\n", shoe_size);
			
			add_person(myhash, email, name, shoe_size, fav_food);
			
		} else if(strcmp(user_input, "lookup\n") == 0){
					printf("going to lookup\n");
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
