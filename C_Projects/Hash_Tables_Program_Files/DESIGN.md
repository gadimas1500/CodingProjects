# HomeWork 7: Hash Tables, I/O & Strings

## Header File "businessdb_header.h"

**add_person**
 
 @params: the hash table, string email, string name, string shoe size, string fav_food

_Implementation_

- we create a new person 
- we get the hash of the the new person's email 
- we store all the values of this person into the new person we created 
- go to that hash index in the table 
	- if no person exists there yet, then add them there
	- else move down the linked list to the last person and add them there 


**look_up**

 @params: the hash table, the char array holding the email

_Implementation_

- take the hash of the email 
- create a pointer to that person 
- create a do-while loop that compares the email we pass and the email of the people at that hash index we found from that person 
- if the strcmp() func returns 0, then return that person we stopped at 
- else we continue until we find that person at that hash 
- if we can't find then, return null 



**delete_person**

 @params: the hash table, the email of the person 

_Implementation_

- we take the hash of the email passed, go to the position, and delete that person 
- we delete (free) that memory from the linked list 
- we have to set the previous pointer to the pointer that the current person is pointing to 


 
**print_list**

 @params: the hash table
 
_Implementation_

- for all the elements in the list that contain a person 
 - print all the values and go onto the next person of their next person pointer is not null 
- this does not return any value, it just prints directly to the user 




**save_progress**

 @params: the hash table, the file we are working with 
 
_Implementation_

- this takes in the hash table, goes through the entire table and adds values to the file 
- after we open the file, we use fprintf to print to the file in the format we want 
- after each value, we have to ensure we ad a \t char to correctly space the values 
- at the last value, we use a \n value 
- this runs contiuously until the end of the has table 
- close the file and return true  


**hash**

 @params: string array 
 
_Implementation_

- we use this function to has an email 
- this uses the functio we built in class to return a special result of the string 

**free_memory**

 @params: the hash table 
 
_Implementation_

- we will pass a hashtable and iterate through every bucket to make sure to clear the linked list and also the list itself 
- we also need to clean the hash table itself and set its value to null 



**load_hash_table**

 @params: the hash table we are implementing to, the filesname, the size of the file 
 
_Implementation_

- This takes function loads values from an existing files into a hash table. 
- I do string manipulation with the strtok() func to separate the string from the \t 
character and from the \n char. 
- I will use a counter and a switch statement to ensure that all the values are 
accounted for and that they are stored in the correct way in the hash table 


**isNumber**

 @params: a char array
 
_Implementation_

- returns true if the char array is all integer vales, else false 


## MAIN "hw7.c"

- This is mainly the administrative part (the from end part of the program) 
- This just calls the functions based on what the user wants to do 
- we can call the following functions 
	- add 
	- lookup 
	- delete 
	- list 
	- save 
	- quit





























