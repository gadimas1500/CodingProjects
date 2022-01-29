#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Postfix.h"

Expression *make_new_expression(void){
	Expression *ptr;
	ptr = (Expression *)calloc(1, sizeof(Expression));
	return ptr;
}

bool add_number(Expression *exp, int num){
	//if(!check_expression(exp)){return false;}
	Character *newtop = (Character *)calloc(1, sizeof(Character));
	newtop->intVal = num;			//assigns the number
	newtop->prev = exp->top;	//newtop.prev gets existing top
	if(exp->top != NULL){
		exp->top->next = newtop;	//existing top.next gets new top
	}
	exp->top = newtop;			//assigns the new top
	exp->size++;
	exp->nums++;
	return true;		
}

bool add_operator(Expression *exp, char op){
	//if(!check_expression(exp)){return false;}
	Character *newtop = (Character *)calloc(1, sizeof(Character));
	newtop->opVal = op;			//assigns the number
	newtop->prev = exp->top;	//newtop.prev gets existing top
	if(exp->top != NULL){
		exp->top->next = newtop;	//existing top.next gets new top
	}
	exp->top = newtop;			//assigns the new top
	exp->size++;
	exp->ops++;
	return true;		
}

bool delete_values(Expression *exp, Character *value, int newValue, Expression *initAdrs){
	if(!check_expression(exp)){return false;}
	Expression *newExp = make_new_expression(); //creates the new expresssion with size of original expression - 2
	int stop = exp->size, ctr = 0;		//gets the size of the list
	Character *elt = exp->top;				//starts off at the top of the list
	while(ctr != stop-1){
		elt = elt->prev; 				//gets the first elt of the list has to circle back
		ctr++;
	}	//elt is now the address at the bottom of the stack
	//we now know that the number of integers reduced by 2 and the number of operators reduced by 1
	for(int i = 0; i < exp->nums-2; i++){	
		add_number(newExp, elt->intVal);	
		elt = elt->next;
	}	//adds the current numbers to the list (not evaluated)
	add_number(newExp, newValue);	//adds the new value
	elt = exp->top;					//resets back to the top of the stack
	for(int i = 0; i < exp->ops-1; i++){
		add_operator(newExp, elt->opVal);
		elt = elt->prev;
	}
	
	//make a new expression with the values of the old one and size - 2
	free(exp);//free the memory and assign exp to the new expression
	printf("Adrs of initAdrs: %p, Adrs of newExp: %p\n", initAdrs, newExp);
	*initAdrs = *newExp;
	//*initAdrs = *(Expression *)newExp;
	//*exp = *newExp;	//exp gets the new address of the allocated memory
	printf("Adrs of initAdrs: %p, Adrs of newExp: %p\n", initAdrs, newExp);
	return true;

}



float get_reduced(Expression *exp, Expression **initAdrs){	//initAdrs is the original address of the expression
	if(check_expression(exp)){
		float val;
		Character *value = exp->top;	//takes the first operation added to the list
		for(int i = 0; i < exp->ops-1; i++){
			value = value->prev;
		}	//now value has the very first operation
		Character *temp = value->prev;
		int num2 = temp->intVal;	//gets the second number
		int num1 = temp->prev->intVal;//gets the first number
		val = do_operation(num1, num2, value->opVal);
		delete_values(exp, temp, val, (Expression *)initAdrs);	//is the middle of num1, num2(temp), operator
		return val;
	}
	return 0;
}


float do_operation(int num1, int num2, char op){
	switch(op){
		case '+':
			return num1 + num2;
			break;
		case '-':
			return num1 - num2;
			break;
		case '*':
			return num1 * num2;
			break;
		case '/':
			return num1 / (float)num2;
			break;		
		default:
			return 0;
	}	
	
}

bool print_expression(Expression *exp){
	int stop = exp->size, ctr = 0;		//gets the size of the list
	Character *elt = exp->top;				//starts off at the top of the list
	/*while(ctr != stop-1){
		elt = elt->prev; 				//gets the first elt of the list has to circle back
		ctr++;
	}*/
	//printf("[");
	for(int i = 0; i < stop; i++)
	{
		if(elt->intVal != 0){	//is an integer
			printf("%d, ", elt->intVal);
		} else {
			printf("%c, ", elt->opVal);
		}
		printf("Adrs of Current: %p, Adrs of previous: %p, Adrs of Next: %p\n", elt, elt->prev, elt->next);
		elt = elt->prev;						//goes backwards in the list (from top to bottom of the List)
	}
	//printf("]\n");
	return true;
}


bool check_expression(Expression *exp){
	if(exp->top == NULL){	
		printf("There is something wrong with the top of the stack!\n");
		return false;
	}
	if(exp->nums - 1 != exp->ops){
		printf("Error: mismatch operations and operands!\n");
		printf("%d Numbers, %d Operations\n", exp->nums, exp->ops);
		return false;
	}
	return true;
}




int main(void){
	Expression *myExpression = make_new_expression();
	printf("Original Pointer: %p, Original address: %p\n", myExpression, &myExpression);
	add_number(myExpression, 12);
	add_number(myExpression, 10);
	add_number(myExpression, 2);
	add_operator(myExpression, '/');
	add_operator(myExpression, '-');
	print_expression(myExpression);
	printf("First reduction: %.3f\n", get_reduced(myExpression, &myExpression));
	printf("New address: %p\n", myExpression);
	print_expression(myExpression);
	printf("New Pointer: %p, Original address: %p\n", myExpression, &myExpression);
	printf("Second reduction: %.3f\n", get_reduced(myExpression, &myExpression));
	//print_expression(myExpression);
	

	return 0;
}
