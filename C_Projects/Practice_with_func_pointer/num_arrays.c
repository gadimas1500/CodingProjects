
/*
 * All of your code goes in here. You need to finish these functions.
 */
#include <stdio.h>
#include <limits.h>
#include "num_arrays.h"
int get_max(int n1, int n2);
int sum_them(int n1, int n2);
int is_negative(int score, int value);

int maximum(int *nums, int len) {
	int largest = *nums;
	for(int i = 0; i < len; i++)
	{
		if(*(nums+i) > largest){	//holds the largest value
			largest = *(nums + i);
		}
	}
  return largest;
}

int sum_positive(int *nums, int len) {
	int sum = 0;
	for(int i = 0; i < len; i++){
		if(*(nums+i) > 0)	
		{
			sum += *(nums+i);
		}
	}
  return sum;
}

int reduce(int *nums, int len, int (*f)(int,int), int initial){
	int value = initial;
	if(len > 1){
		for(int i = 0; i < len-1; i++){
			value = f(value, nums[i+1]);
		}
	} else{
		value = f(value, nums[0]);//points to a function that must take in two parameters
	}
	return value;
}

int maximum_with_reduce(int *nums, int size) {
	int max = INT_MIN;	//the smallest integer value
  for(int i = 0; i < size; i++){
  		max = reduce(nums, size, get_max, max);
  }
  return max;
}

int get_max(int n1, int n2){	//helper function for maximum_with_reduce
	if(n1 > n2){return n1;}else{return n2;}
	}


int sum_positive_with_reduce(int *nums, int size) {
	int sum = 0;	//the smallest integer value
  for(int i = 0; i < size; i++){
  		int list[] = {sum, nums[i]};	//this array updates after every iteration to ensure we carry the sum of only the positive numbers
  		if(nums[i] > 0){
  			sum = reduce(list, 2, sum_them, sum);
  		}
  }
  return sum;
}
int sum_them(int n1, int n2){	//helper function for sum_positive_with_reduce
	return n1 + n2;
}

int count_negative_with_reduce(int *nums, int size) {	
  int count = 0;
  for(int i = 0; i < size; i++){
  			int list[] = {nums[i], 0};		//0 is a dummy constant that we need to pass because reduce takes in an array of at least 2 elements
			count = reduce(list, 1, is_negative, count);
		
	}
	return count;
}

int is_negative(int score, int value){	//helper function for count_negative_with_reduce
	if(value < 0){
		score++;
		}
	return score;
}








