#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "businessdb_header.h"
#define NUM_BUCKETS 30 //this is the initial size of the bucket



int main(void){

//we have to read from a file
//we have to promt the user from the commands until they want to exit
	HashTable *myhash;
	int line_nums;
	load_hash_table(myhash, "customers.tsv", &line_nums);

	char user_input[20];
	do{
		printf("Command: ");
		fgets(user_input, 20, stdin);
		if(strcmp(user_input, "add\n") == 0){
			printf("going to add\n");
		} else if(strcmp(user_input, "lookup\n") == 0){
					printf("going to lookup\n");
		}else if(strcmp(user_input, "delete\n") == 0){
					printf("going to delete\n");
		}else if(strcmp(user_input, "list\n") == 0){
					printf("going to list\n");
		}else if(strcmp(user_input, "save\n") == 0){
					printf("going to save\n");
		}
	}while(strcmp(user_input, "quit\n") != 0);


	return 0;
}
