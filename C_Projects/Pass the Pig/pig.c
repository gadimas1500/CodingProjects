#include <stdio.h>
#include <stdlib.h>
#include "names.h"
#include <stdbool.h>
int get_random (int s); //headers




//MAIN
int main(void){
	typedef enum { SIDE , RAZORBACK , TROTTER , SNOUTER , JOWLER } Position;	//new data type
	const Position pig [7] = {	//makes use of our new data type
		SIDE,
		SIDE,
		RAZORBACK,
		TROTTER,
		SNOUTER,
		JOWLER,
		JOWLER
	 };
	int points[10] = {0,0,0,0,0,0,0,0,0,0};	//keeps track of scores of all the peeps playing
	float input = 0, seed = 0;
	bool play = true;
	const char *orient[7] = {"side", "side", "razorback", "trouter", "snouter", "jowler", "jowler"};
	printf("How many players? ");
	scanf("%f", &input);	//gets player input
	
	if(!(input == (int)input && (input >= 2) && (input <= 10)))//checks for float values and range
	{
		fprintf(stderr, "Invalid number of players. Using 2 instead.\n");//error message
		input = 2;	 //sets input to 2
	}
	
	printf("Random seed: ");
	scanf("%f", &seed);	//gets the seed
	if(!(seed == (int)seed))
	{
		printf("Invalid random seed. Using 2022 instead.\n");
		seed = 2022;
	}
	else{
		seed = (int)seed;	//assigns the original input of seed if it was correct (casted)
		}

	//actual gameplay
	int player = 0;	//the player who is currently playing
	int roll;
	while(play)
	{
		if (player >= input) //resets to the first player if we reached the last player
		{
			player = 0; 
		}
		printf("%s rolls the pig...", names[player]);
		
		while(true){
			roll = get_random(seed+=50);	//calls and receives the random number		
			if(pig[roll] == 2 || pig[roll] == 3){
				points[player] += 10;	//RAZORBACK OR TROTTER
			}else if(pig[roll] == 4){
				points[player] += 15;	//SNOUTER
			}else if(pig[roll] == 5 || pig[roll] == 6){
				points[player] += 5;	//JOWLER OR JOWLER
			}
			printf(" pig lands on %s", orient[pig[roll]]);
			if((pig[roll] == 0 || pig[roll] == 1) || points[player] >= 100)
			{break;}	//onto next player if lands on side or player points >= 100
		}
		if(points[player] >= 100){	//checks if a player wins the game
			printf("\n%s wins with %d points!\n", names[player], points[player]);
			play = !play;
			break;
			}
		
		player +=1;	//next player
		printf("\n");
	}
return 0;
}



 
int get_random (int s) {	//takes in a seed and generates a psudorandom number
	int sd = s;
	int to_return;
	srand(sd);
	to_return = random();
	to_return = (rand() % (6 - 0 + 1) + 0);
	return to_return;
 }
 


 
 
 
 
 
 
 
 

