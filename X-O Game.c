/*************************************
 * Task	  : X - O game
 * Created: 12/20/2021 7:43:54 PM
 * Author : Abdelrhman Elsawy
 *************************************/

#include <stdio.h>
#include <conio.h>

char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };      // x-o template ( Empty position numbers )
void board();           // x-o template ( the boarders )
int checkwin();	   	    // function to check if any player win ( 1 if player win 0 if draw )
char checker = 'c' ;    // indicator to the end of the game
void reset();			// function to reset template and start new game 

int main(void)
{
	static char playerNumber = 1 ;   // variable to hold the player number 
	char mark ;						 // variable to hold x or o mark 
	char position ;                  // variable to select position in template 
	
	while(1)
	{	
		playerNumber = 1 ;    					 // to make player 1 start the game every time 
		board(); 								 // initialize the template 
	    while ( checker != 1 && checker != 0 )   // the game is not over 
	    {
	    	playerNumber = (( playerNumber % 2 ) ? 1 : 2 );	
	        printf("\nPlayer %d, enter a position number:  ",playerNumber);
	        position = getch();
	        mark = (( playerNumber == 1 ) ? 'X' : 'O');
	        
		    if( square[position-48]== position )
	        {
 				square[position-48] = mark ;       		
        	}
	        else 
	        {
        		printf("\n***** not valid posiotion *****");
        		playerNumber-- ;
	        }
					
	        board();
	        checker = checkwin();
		    playerNumber++ ; 			 
	    }
	    if ( checker == 1 && playerNumber == 1 )
	    	printf("\n***** player 1 is winner *****");
	    else if ( checker == 1 && playerNumber != 1 )
	    	printf("\n***** player 2 is winner *****");
	    else 
	    	printf("\n***** game is draw *****");
	   	reset();
	}	  
}


// function to draw board of game
void board()
{
	printf("\n\n\t X - O Game \n\n");

	printf("\nPlayer 1 (X)  -  Player 2 (O)\n\n\n");

	printf("\t   |     |     \n");
	printf("\t%c  |  %c  |  %c \n", square[1], square[2], square[3]);

	printf("      _____|_____|_____\n");
	printf("\t   |     |     \n");

	printf("\t%c  |  %c  |  %c \n", square[4], square[5], square[6]);

	printf("      _____|_____|_____\n");
	printf("\t   |     |     \n");


	printf("\t%c  |  %c  |  %c \n", square[7], square[8], square[9]);
	printf("\t   |     |     \n");
}

/*********************************************
Function to return game status

1 --> one of tow players is win
0 --> draw

 **********************************************/

int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])
	return 1;

	else if (square[4] == square[5] && square[5] == square[6])
	return 1;

	else if (square[7] == square[8] && square[8] == square[9])
	return 1;

	else if (square[1] == square[4] && square[4] == square[7])
	return 1;

	else if (square[2] == square[5] && square[5] == square[8])
	return 1;

	else if (square[3] == square[6] && square[6] == square[9])
	return 1;

	else if (square[1] == square[5] && square[5] == square[9])
	return 1;

	else if (square[3] == square[5] && square[5] == square[7])
	return 1;

	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
	square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
	!= '7' && square[8] != '8' && square[9] != '9')
	return 0;
}
void reset()
{
	int index = 0 ;
	for( index = 0 ; index < 11 ; index++ )
	{
		square[index] = index+48 ; 
	}	
	checker = 'c';	
	printf("\n*****lets start new game*****");
}