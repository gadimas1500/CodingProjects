**Pass the Pig**

-----------
**DESCRIPTION**

The program fuctions mostly autonomously. On the initial run, the user is to input 
the number of players playing the game from a range of 2 (inclusive) to 10 (inclusive). The player chooses n players. The program then choses n players from the array of 10 players and makes a psudorandom number choice.

Whichever the random number lands on, then that sid of the 'pig' is considered to be rolled.

The program goes around in a circle with all the players. A players turn is finished when they roll the pig to land on its side. Else, that player keeps rolling. 

The first player to reach greather than or equal to 100 points wins the game. The program is terminated.


-----------
**FILES**

- pig.c

The is the source file for my program. It includes the the main function as well as a function to generate psudorandom numbers. This file also includes error messages for in case the user inputs non-integer values for the player number and the random seed (also checks for correct player range for player numbers).

- names.h

A header file that includes an array of all the ten names of players.

- DESIGN.md

A markdown file that holds the design of the program. Includes some psudocode.

- README.md

This README file.

- Makefile

Makefile used to make, link, and compile the main program and the header files together.

-----------
**INSTRUCTIONS**

On first run, the player is asked to input the amount of players they want to play with.
The player is then asked to plant a random seed.
The computer then goes in a circle and randomly rolls an imaginary pig.
The first to reach 100 points wins. 


