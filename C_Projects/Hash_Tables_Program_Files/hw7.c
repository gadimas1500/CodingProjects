#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "businessdb_header.h"
#define NUM_BUCKETS 30 //this is the initial size of the bucket



int main(void){

//we have to read from a file
//we have to promt the user from the commands until they want to exit
	HashTable *myhash;
	myhash = create_hash_table(NUM_BUCKETS);
	load_hash_table(myhash, "customers.tsv");
	int load_size = 40;
	char user_input[load_size];
	do{
		printf("Command: ");
		fgets(user_input, load_size, stdin);
		printf("\n");
		if(strcmp(user_input, "add\n") == 0){							//finished
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

			printf("%s added successfully!\n", name);			
		} else if(strcmp(user_input, "lookup\n") == 0){				//finished
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
				printf("There was no such customer with that email!\n");
			}
		}else if(strcmp(user_input, "delete\n") == 0){				//finsihed
			char *delete;
			printf("Enter email of the customer you wish to delete: ");
			fgets(user_input, load_size, stdin);
			delete = strndup(user_input, load_size);
			strtok(delete, "\n");	//removes the \n char
			if(look_up(myhash, delete) == NULL){
				printf("There exists no customer with that email!\n");
				continue;
			}
			if(delete_person(myhash, delete) && look_up(myhash, delete) == NULL){
				printf("The customer has beed deleted!\n");
			} else{
				printf("There was an error deleting the customer!\n");
			}
		}else if(strcmp(user_input, "list\n") == 0){					//finished
					print_list(myhash);
		}else if(strcmp(user_input, "save\n") == 0){					//finished
					if(save_progress(myhash, "customers.tsv")){
						printf("Your progress has been saved successfully!\n");
					} else{
						printf("There was an error saving your progess!\n");
					}
		}else if(strcmp(user_input, "quit\n") == 0){
			free_memory(myhash);
			break;
		}
		printf("\n");
	}while(true);
	return 0;
}
