#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Postfix.h"

Expression *make_new_expression(void){
	Expression *ptr;
	ptr = (Expression *)calloc(1, sizeof(Expression));
	return ptr;
}

bool add_char(Expression *exp, char car){
	int outcome = car;
	if(!check_character(car)){//if an operator(returns false), then perform an operation
		print_expression(exp);
		printf("%d %c %d -> ", exp->top->prev->data, car, exp->top->data);
		outcome = do_operation(exp->top->prev->data, exp->top->data, car);
		printf("%d You have %d operations left!\n", outcome, exp->size-1);
		
		exp->size--;
	} else{
		exp->size++;
	}
	Character *newtop = (Character *)calloc(1, sizeof(Character));
	newtop->data = outcome;			//assigns the number
	newtop->prev = exp->top;	//newtop.prev gets existing top
	if(exp->top != NULL){
		exp->top->next = newtop;	//existing top.next gets new top
	}
	exp->top = newtop;			//assigns the new top	
	return true;	
}




int do_operation(int num1, int num2, char op){
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
	int stop = exp->size, ctr = 0;
	Character *ptr = exp->top;
	while(ctr != stop-1){
		ptr = ptr->prev;
		ctr++;
	}
	printf("[");
	for(int i = 0; i < exp->size; i++){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("] ");
	return true;
}

bool check_character(char op){
	switch(op){
		case '+':
		case '-':
		case '*':
		case '/':
			return false;
			break;		
		default:
			return true;
	}
}




int main(void){
Expression *myExpression = make_new_expression();
	while(true){
		int input;
		printf("Enter a value: ");
		scanf("%s", &input);
		add_char(myExpression, input);
		print_expression(myExpression);
		printf("\n");
	}

	

	return 0;
}
