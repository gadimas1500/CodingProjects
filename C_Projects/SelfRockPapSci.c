 #include <stdio.h>
 #include <stdlib.h>

 int random_number(void);

 int main(void)
 {
	int computer, cScore=0, pScore=0, games=1, cax=0, play, input;
	printf("How many game plays? ");
	scanf("%d", &play); play++;
	while(1){
		computer = random_number();	//COMPUTER CHOOSES A NUMBER
		for(int i = 0; i < 1000000000; i++);	//AN ARTIFICIAL TIMER DELAY
		//printf("Enter your move: %c\n", input);
		input = random_number();//getchar();
		
		switch(computer){	//assigns a move to computer based on its random number
			case 1:
				computer = 'r';
				break;
			case 2:
				computer = 'p';
				break;
			case 3:
				computer = 's';
				break;		
			default:
				printf("Computer messed up.\n");
			}	
		switch(input){	//assigns a move to computer based on its random number
			case 1:
				input = 'r';
				break;
			case 2:
				input = 'p';
				break;
			case 3:
				input = 's';
				break;		

							}
			printf("Input1:    %c\n", input);
			printf("Computer2: %c\n", computer); 
			if(computer == input)
			{
				printf("It's a cax game! Replaying...\n");
				cax++;
				continue;
			}
			else if((computer == 'r' && input == 'p') || (computer == 'p' && input == 's')||(computer == 's' && input == 'r')){
			
				printf("C1 Won\n");
				pScore++;
				
			} 
			
			else if((computer == 'r' && input == 's') || (computer == 'p' && input == 'r')||(computer == 's' && input == 'p'))
			{
				printf("C2 Won!\n");
				cScore++;
				
			} 
			else{
				printf("Some other error occured...-> %x, %d, %c\n", input, input, input);
				break;
			}	
			printf("C1 score: %d (%.2f%%), C2 Score: %d (%.2f%%). %d of %d Total games (Cax: %d).\n", pScore, ((float)pScore)*100/(games), cScore, ((float)cScore)*100/(games), games, play-1, cax);
		/*	while((input=getchar()) != '\n');	//CLEARS THE INPUT TO TAKE IN ANOTHER
			printf("Play again? [y/n]: "); 
			char temp = getchar();
			if(temp == 'n') {break;}
			while((input=getchar()) != '\n');*/
			games++;
			if(games == play){break;}
			
			printf("\n");
		}
	return 0;
 }





















 int random_number(void)	//gets a random number
 {
     int result = 0, low_num = 0, hi_num = 0, min_num = 1, max_num = 3;

     if (min_num < max_num)
     {
         low_num = min_num;
         hi_num = max_num + 1; // include max_num in output
     } else {
         low_num = max_num + 1; // include max_num in output
         hi_num = min_num;
     }
     srand(time(NULL));
     result = (rand() % (hi_num - low_num)) + low_num;
     return result;
 }
