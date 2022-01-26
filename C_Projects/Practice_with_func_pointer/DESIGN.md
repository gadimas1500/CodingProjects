# Design Functions, Arrays, and Pointers

## Parameters

**maximum**

@params *nums: a pointer to an integer array
			len: an integer holding the length of the array
Variables: largest: this holds the largest value
We would initialize largest with the very first element in the nums array. This means that we can iterate through the array and check if there are any larger values in the array.

_Implementation_

for (all the elements in the array -> for length range):  
	if(there is a number bigger than larger):  
		update larger with that bigger value  
  return largest
  
**sum_positive**
 
 @params *nums: a pointer to an integer array  
			len: an integer holding the length of the array  
Variables: sum: this holds sum of all positive values  

_Implementation_

for all elements in the array -> the range of len:  
	if the current number is greater than zero:  
		add this number to the sum  
I will also implement a helper function that returns the sum two integers together

**reduce**

 @params *nums: a pointer to an integer array  
			len: an integer holding the length of the array  
			f: a pointer function that points to some type of funtion to perform an operation
Variables: value: sets the value at the initial value passed

_Implementation_

set value equal to inital  
for all the values in the array:  
	value is set to some operation of two numbers  
return value

**maximum_with_reduce**

 @params *nums: a pointer to an integer array  
			len: an integer holding the length of the array  
Variables: max: initially holds the minimum integer value, then holds the minimum   value for the array

_Implementation_

for all the elements in the list:  
the max variable will get the return integer of the reduce call. We are going to pass the original list and the original sixe of the list  
We return the max value
I will also implement a helper function _get_max_ that returns the sum of two integers together

**sum_positive_with_reduce**

 @params *nums: a pointer to an integer array  
			len: an integer holding the length of the array  
	Variables: a sum integer that will be returned. A _list_ array that takes two values and holds them to send to the _reduce_ function.  
	
_Implementation_

for all the elements in the list:  
	- we update our temparary list array with the sum at index 0 and the curruent value we are evaluating at index 1.  
	- check if that the number we are evaluating is a positive number
	- if so, then max gets the integer that the reduce function returns with the parameters as the list array, length 2, the helper function _sum_them_, and the sum  
- after the for loop, we return the sum

- _sum_them_ is a helper function that adds only two values

**count_negative_with_reduce**

@params *nums: a pointer to an integer array  
			len: an integer holding the length of the array  
Variables: count: this holds the count of the negative numbers. A _list_ array that takes two values and holds them to send to the _reduce_ function.  

_Implementation_

for all the values in the array:  
- we update the _list_ array that takes in two elements: the 0th index is the value we are evaluating, and the 1st index is a dummy constant only because the _reduce_ functions requires an incoming list to be at _least_ two elements long.  
- _count_ updates with the return integer of a _reduce_ call  
- after the for loop, we return the _count_ of negative numbers.  
- we also have a helper function that returns the score + 1 if the incoming number is negative, or returns the original score if the value is positive.  






































