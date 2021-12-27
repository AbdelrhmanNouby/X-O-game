/*************************************
 * Task	  : X - O game
 * Created: 12/20/2021 7:43:54 PM
 * Author : Abdelrhman Elsawy
 *************************************/

#include <stdio.h>
#include <conio.h>
#include "typedef.h"

uint8_t gu8arr_square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };      // x-o template ( Empty position numbers )
uint8_t gu8_checker = 'c' ;    // indicator to the end of the game

void board();           // x-o template ( the boarders )
uint8_t checkwin();	   	    // function to check if any player win ( 1 if player win 0 if draw )
void reset();			// function to reset template and start new game 

main()
{
	static uint8_t u8_playerNumber = 1 ;   // variable to hold the player number 
	uint8_t u8_mark ;						 // variable to hold x or o mark 
	uint8_t u8_position ;                  // variable to select position in template 
	
	while(1)
	{	
		u8_playerNumber = 0 ;    					 // to make player 1 start the game every time 
		board(); 								 // initialize the template 
	    while ( gu8_checker != 1 && gu8_checker != 0 )   // the game is not over 
	    {
	    	u8_playerNumber++ ;       // go to the second player 
	    	u8_playerNumber = (( u8_playerNumber % 2 ) ? 1 : 2 );						// go to the next player
	        printf("\nPlayer %d, enter a position number:  ",u8_playerNumber);		// select position 
	        u8_position = getch();
	        u8_mark = (( u8_playerNumber == 1 ) ? 'X' : 'O');							// assign mark depend on player
	        
		    if( gu8arr_square[u8_position-48]== u8_position )    // checking valid position ( -48 >> convert char getted to int )
	        {
 				gu8arr_square[u8_position-48] = u8_mark ;       		
        	}
	        else 
	        {
        		printf("\n***** not valid posiotion *****");
        		u8_playerNumber-- ;
	        }
					
	        board();      // print updated template
	        gu8_checker = checkwin();	// check game status 			 
	    }
	    if ( gu8_checker == 1 && u8_playerNumber == 1 ) 		// print game status if it finished 		
	    	printf("\n***** player 1 is winner *****");
	    else if ( gu8_checker == 1 && u8_playerNumber != 1 )
	    	printf("\n***** player 2 is winner *****");
	    else 
	    	printf("\n***** game is draw *****");
	   	reset();			// start new game 
	}	  
}


// function to draw board of game

void board()
{
	printf("\n\n\t X - O Game \n\n");

	printf("\nPlayer 1 (X)  -  Player 2 (O)\n\n\n");

	printf("\t   |     |     \n");
	printf("\t%c  |  %c  |  %c \n", gu8arr_square[1], gu8arr_square[2], gu8arr_square[3]);

	printf("      _____|_____|_____\n");
	printf("\t   |     |     \n");

	printf("\t%c  |  %c  |  %c \n", gu8arr_square[4], gu8arr_square[5], gu8arr_square[6]);

	printf("      _____|_____|_____\n");
	printf("\t   |     |     \n");


	printf("\t%c  |  %c  |  %c \n", gu8arr_square[7], gu8arr_square[8], gu8arr_square[9]);
	printf("\t   |     |     \n");
}

/*********************************************
Function to return game status

1 --> one of tow players is win
0 --> draw
'c' --> game in progress 

 **********************************************/

uint8_t checkwin()
{
	if (gu8arr_square[1] == gu8arr_square[2] && gu8arr_square[2] == gu8arr_square[3])
	return 1;

	else if (gu8arr_square[4] == gu8arr_square[5] && gu8arr_square[5] == gu8arr_square[6])
	return 1;

	else if (gu8arr_square[7] == gu8arr_square[8] && gu8arr_square[8] == gu8arr_square[9])
	return 1;

	else if (gu8arr_square[1] == gu8arr_square[4] && gu8arr_square[4] == gu8arr_square[7])
	return 1;

	else if (gu8arr_square[2] == gu8arr_square[5] && gu8arr_square[5] == gu8arr_square[8])
	return 1;

	else if (gu8arr_square[3] == gu8arr_square[6] && gu8arr_square[6] == gu8arr_square[9])
	return 1;

	else if (gu8arr_square[1] == gu8arr_square[5] && gu8arr_square[5] == gu8arr_square[9])
	return 1;

	else if (gu8arr_square[3] == gu8arr_square[5] && gu8arr_square[5] == gu8arr_square[7])
	return 1;

	else if (gu8arr_square[1] != '1' && gu8arr_square[2] != '2' && gu8arr_square[3] != '3' &&
	gu8arr_square[4] != '4' && gu8arr_square[5] != '5' && gu8arr_square[6] != '6' && gu8arr_square[7]
	!= '7' && gu8arr_square[8] != '8' && gu8arr_square[9] != '9')
	return 0;
	
	else 
	return 'c';
}

/*******************************
 function to return back template to initial statu 
 and start new game 
********************************/

void reset()   
{
	uint8_t u8_index = 0 ;
	for( u8_index = 0 ; u8_index < 11 ; u8_index++ )
	{
		gu8arr_square[u8_index] = u8_index+48 ; 
	}	
	gu8_checker = 'c';	
	printf("\n*****lets start new game*****");
}