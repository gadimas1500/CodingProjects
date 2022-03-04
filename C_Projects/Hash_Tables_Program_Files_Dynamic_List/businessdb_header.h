#pragma once
#include <stdbool.h>

//create a struct for a hash table
//our hash table should hold the number of things it has and should 
//create functions we are going to use
typedef struct Person{
	char *email;
	char *name;
	char *shoe_size;
	char *fav_food;
	int hash;
	int at_stored_size;
	struct Person *next;

} Person;


typedef struct HashTable{
	int size;
	Person **customers;	//this is a 2d array
	Person *top;
} HashTable;

HashTable *create_hash_table(int size);
//creates a new hash table for us

HashTable *add_one_spot(HashTable *hashtable);
//reallocates another slot to the current hash table
//also increments the size of the table
//returns that hash table with previous values saved

void add_person(HashTable *hashtable, char *email, char *name, char *shoe_size, char *favfood);
//we need to realloate new memory to store this new person if their hash it greater than the number of buckets we currently have

Person *look_up(HashTable *hashtable, char *email);	
//looks up a person by their email, we have to call its hash
//if we can't find that person, tell the user
//display this person in a very nice way

bool delete_person(HashTable *hashtable, char *email);
//returns true if we found and deleted the person else false if either of them are not true
//we have to look up using their hash

void print_list(HashTable *hashtable);
//prints every person's info
//format it the same way as lookup

bool save_progress(HashTable *hashtable, char *filename);
//currently takes in no parameters, but may change later
//this saves the progress into a log to avoid deletions

unsigned long hash(char *email);
//hashes the email using the size of the list
//with this implementation, we can also change the size of the list if we need to
//changing the size of the list comes if we have a hash that wants a larger value

bool free_memory(HashTable *hashtable);
//frees the memory of the hash table and all of its contents
//returns true if we completed it

void load_hash_table(HashTable *hashtable, char *filename, int *size);
//loads all the values of the file into the hash table and loads the size with the number of people in the list

HashTable *load_from_hash_table(HashTable *hashtable, int size);
//takes in one hash table and returns another of the same size wiht the new hash values of the new size

bool isNumber(char *s);
//checks if a string is a number







