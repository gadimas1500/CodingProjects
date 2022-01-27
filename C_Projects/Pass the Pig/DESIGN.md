**Design For Pass the Pig**

**Parameters**


@param s: the seed
@return: a random number with the given seed

**Main:**
	Here I include the included data type needed to show the position of the pig.
	I also will include these variables:
		input:  player input that grabs the number of players (DEFAULT = 2)
		
		points: an array to keep track of the players' score (initialized with 10 values)
		
		play:   a boolean var that tracks the game state
		
		orient: the orientation of the pig when rolled to be outputted to the screen
		
		seed:   an input by the user for a random seed (DEFAULT = 2022)
		
	-Here I will check if input and seed are valid values, else they will get their default
	
	**GAMEPLAY**
	Here is where the actual gameplay will occur
	while(play is true):
		check if player var is valid
			will reset to zero if player >= input;
		while(true):
			get a random number;
			switch(random number):
				check which orientation the pig landed on:
					player's score will increase by that number
				break out of inner loop if pig lands on side or score is >= 100
new function -> get_random
@param int s: the seed
return a random number from a range of 0 -> 6 (inclusive)
