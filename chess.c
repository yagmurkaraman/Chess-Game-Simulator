/*----------------------------------------------------------------------------*/
/*                                                                            */
/* HW08_141044016_Yagmur_Karaman                                              */
/*                     												          */
/* main.c                                                                     */
/* ------										                              */
/* Created on 21/04/2016 by Yagmur Karaman                                    */
/*																	          */
/* Description                                                                */
/* ------------                                                               */
/*		The main.c contains the implementations of functions                  */
/*		for the homework VIII, which are use that performs 2-player 		  */
/*		chess game simulator which will take commands and arguments           */
/*		from the user, executes the commands and return the result.           */   
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*								İncludes									  */
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*								#defines                                      */
/*----------------------------------------------------------------------------*/
#define VALID 1
#define INVALID 0
#define BOARD_SIZE 8
#define SMALLEST_DIFF 16        /* smallest difference between game character */
/*----------------------------------------------------------------------------*/
/*							Function Prototypes                               */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* int initBoard(char *board)                                                 */
/* --------------------------                                				  */						  
/*		board - board of the chess                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		This function will return the start position to board.                */
/*																		      */
/*----------------------------------------------------------------------------*/
int initBoard(char *board);
/*----------------------------------------------------------------------------*/
/* void printBoard(char *board)                                               */
/* ----------------------------								             	  */
/*		board - board of the chess                                            */
/* 																			  */
/* Description                                                                */
/* -----------                                                                */
/*		This function will print the current state of the board as show       */
/*		above.																  */
/*                                                                            */
/*----------------------------------------------------------------------------*/
void printBoard(char *board);
/*----------------------------------------------------------------------------*/
/* int isPieceMovable(char *board,char sc, int sr, char tc, int tr)           */
/* -------------------------------                                            */
/*		board 	- board of the chess                                          */
/*		sc		- column of source index                                      */
/*		sr		- row of source index                                         */
/*		tc		- column of target index                                      */
/*		tr		- row of target index 				                          */
/*																	          */
/* Return                                                                     */
/* ------                                                                     */
/*		1 on success                                                          */
/*		0 on error                                                            */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		It asks the user the source and target positions and check            */
/*		whether the piece in the source cell can be movable to the            */
/*		target cell.                                                          */
/*																			  */
/*----------------------------------------------------------------------------*/
int isPieceMovable(char *board,char sc, int sr, char tc, int tr);
/*----------------------------------------------------------------------------*/
/* void getPosition(char *col, int *row)                                      */
/* -------------------------------------                                      */
/*		col - column of the board                                             */
/*		row - row of the board                                                */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		This function will take the row and column values of a                */
/*		specific cell on the board.                                           */
/*                                                                            */
/*----------------------------------------------------------------------------*/
void getPosition(char *col, int *row);
/*----------------------------------------------------------------------------*/
/* int isValidCell(char *col, int *row)                                       */
/* ------------------------------------                                       */
/*		col - column of the board                                             */
/*		row - row of the board                                                */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/*		1 on success                                                          */
/*		0 on error                                                            */
/*																		      */
/* Description                                                                */
/* -----------                                                                */
/*		This function will check whether the given cell is valid              */  
/*		according to the board sizes and returns 1 if it is valid,            */
/*		otherwise 0.													      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
int isValidCell(char col, int row);
/*----------------------------------------------------------------------------*/
/* int isKnightMovable(char *board, char sourceCol, int sourceRow,            */
/* char targetCol, int targetRow)                                             */
/* ------------------------------                                             */
/*		board     - board of the chess         		                          */
/*		sourceCol - column of source index                                    */
/*		sourceRow - row of source index                                       */
/*		targetCol - column of target index                                    */
/*		targetRow - row of target index                                       */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		This function will check whether a knight can move from source        */
/*		cell to the target cell according to the rules of the game.           */
/*																			  */
/*----------------------------------------------------------------------------*/
int isKnightMovable(char *board, char sourceCol, int sourceRow, 
						char targetCol, int targetRow);
/*----------------------------------------------------------------------------*/
/* int isRookMovable(char *board, char sourceCol, int sourceRow,              */
/* char targetCol, int targetRow)                                             */
/* ------------------------------                                             */
/*		board     - board of the chess         		                          */
/*		sourceCol - column of source index                                    */
/*		sourceRow - row of source index                                       */
/*		targetCol - column of target index                                    */
/*		targetRow - row of target index                                       */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		This function will check whether a rook can move from source          */
/*		cell to the target cell according to the rules of the game.           */
/*																			  */
/*----------------------------------------------------------------------------*/
int isRookMovable(char *board, char sourceCol, int sourceRow,
						char targetCol, int targetRow);
/*----------------------------------------------------------------------------*/
/* int isKingMovable(char *board, char sourceCol, int sourceRow,              */
/* char targetCol, int targetRow)                                             */
/* ------------------------------                                             */
/*		board     - board of the chess         		                          */
/*		sourceCol - column of source index                                    */
/*		sourceRow - row of source index                                       */
/*		targetCol - column of target index                                    */
/*		targetRow - row of target index                                       */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		This function will check whether a king can move from source          */
/*		cell to the target cell according to the rules of the game.           */
/*																			  */
/*----------------------------------------------------------------------------*/
int isKingMovable(char *board, char sourceCol, int sourceRow, 
						char targetCol, int targetRow);
/*----------------------------------------------------------------------------*/
/* int isQueenMovable(char *board, char sourceCol, int sourceRow,             */
/* char targetCol, int targetRow)                                             */
/* ------------------------------                                             */
/*		board     - board of the chess         		                          */
/*		sourceCol - column of source index                                    */
/*		sourceRow - row of source index                                       */
/*		targetCol - column of target index                                    */
/*		targetRow - row of target index                                       */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		This function will check whether a queen can move from source         */
/*		cell to the target cell according to the rules of the game.           */
/*																			  */
/*----------------------------------------------------------------------------*/
int isQueenMovable(char *board, char sourceCol, int sourceRow, 
						char targetCol, int targetRow);
/*----------------------------------------------------------------------------*/
/* int isBishopMovable(char *board, char sourceCol, int sourceRow,            */
/* char targetCol, int targetRow)                                             */
/* ------------------------------                                             */
/*		board     - board of the chess         		                          */
/*		sourceCol - column of source index                                    */
/*		sourceRow - row of source index                                       */
/*		targetCol - column of target index                                    */
/*		targetRow - row of target index                                       */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		This function will check whether a bishop can move from source        */
/*		cell to the target cell according to the rules of the game.           */
/*																			  */
/*----------------------------------------------------------------------------*/
int isBishopMovable(char *board, char sourceCol, int sourceRow, 
						char targetCol, int targetRow);
/*----------------------------------------------------------------------------*/
/* int isPawnMovable(char *board, char sourceCol, int sourceRow,              */
/* char targetCol, int targetRow)                                             */
/* ------------------------------                                             */
/*		board     - board of the chess         		                          */
/*		sourceCol - column of source index                                    */
/*		sourceRow - row of source index                                       */
/*		targetCol - column of target index                                    */
/*		targetRow - row of target index                                       */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		This function will check whether a pawn can move from source          */
/*		cell to the target cell according to the rules of the game.           */
/*																			  */
/*----------------------------------------------------------------------------*/
int isPawnMovable(char *board, char sourceCol, int sourceRow, 
						char targetCol, int targetRow);
/*----------------------------------------------------------------------------*/
/* int whichIndex(char col, int row)                                          */
/* ------------------------------                                             */
/*		col - column of the board                		                      */
/*		row - row of the board                                                */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		This function will find the index of source cell and target cell.     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
int whichIndex(char col, int row);
/*----------------------------------------------------------------------------*/
/* int isBlack(char currPlayer)                                               */
/* ----------------------------                                               */
/*		currPlayer - character of player                                      */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/*		1 if black                                                            */
/*		0 not black                                                           */
/*																		      */
/* Description                                                                */
/* -----------                                                                */
/*		This function find the color of player.                               */
/*												                              */
/*----------------------------------------------------------------------------*/
int isBlack(char currPlayer);
/*----------------------------------------------------------------------------*/
/* int isWhite(char currPlayer)                                               */
/* ----------------------------                                               */
/*		currPlayer - character of player                                      */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/*		1 if white                                                            */
/*		0 not white                                                           */
/*																		      */
/* Description                                                                */
/* -----------                                                                */
/*		This function find the color of player.                               */
/*												                              */
/*----------------------------------------------------------------------------*/
int isWhite(char currPlayer);
/*----------------------------------------------------------------------------*/
/* int isInCheck(char* board)                                                 */
/* --------------------------                                                 */
/*		board -	board of the chess                                            */
/*																	          */
/* Return                                                                     */
/* ------                                                                     */
/*		1 - if white king is in check                                         */
/*		2 - if black king is in check                                         */
/*		0 - if there is no check                                              */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		This function checks whether a king is in check or not.               */
/*----------------------------------------------------------------------------*/
int isInCheck(char* board);
/*----------------------------------------------------------------------------*/
/* int makeMove(char *board, char sc, int sr, char tc, int tr)                */
/* ---------------------------------                                          */
/*		board - board of the chess                                            */
/*		sc		- column of source index                                      */
/*		sr		- row of source index                                         */
/*		tc		- column of target index                                      */
/*		tr		- row of target index 	                                      */
/*                                                                            */
/* Return                                                                     */
/* ------                                                                     */
/*		0 - if move is invalid                                                */
/*		1 - if move is invalid because same player's king is in check         */
/*		2 - if move is valid                                                  */
/*		3 - if move is valid and opponent player's king is in check           */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		This function moves a piece from source to destination if current     */
/*		player's king is not in check and piece can move from source to       */
/*		destination. If player's king is in check, move should not be         */
/*		made and board should remain same.                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
int makeMove(char *board, char sc, int sr, char tc, int tr);
/*----------------------------------------------------------------------------*/
/* char getPlayer(char *board, char col, int row)                             */
/* ------------------                                                         */
/*		board - board of the chess                                            */
/*		col - column of the board                		                      */
/*		row - row of the board                                                */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		This function find player who play the game.                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/
char getPlayer(char *board,char col,int row);
/*----------------------------------------------------------------------------*/
/* char whichColumn(int index)                                                */
/* ---------------------------                                                */
/*		index - cell of the board                                             */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		This function find column of index.                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/
char whichColumn(int index);
/*----------------------------------------------------------------------------*/
/* char whichRow(int index)                                                   */
/* ---------------------------                                                */
/*		index - cell of the board                                             */
/*                                                                            */
/* Description                                                                */
/* -----------                                                                */
/*		This function find row of index.                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
int whichRow(int index);

/*----------------------------------------------------------------------------*/
/*					     Function Implementations                             */
/*----------------------------------------------------------------------------*/
/* Function initBoard                                                         */
/* ------------------                                				          */						  
/*		This function will return the start position to board.                */

int main() {
    char board [BOARD_SIZE*BOARD_SIZE], empty;
    int player = 1; /* 1 white, 0 black */
    char sc,tc; /* source/target cols */
    int sr,tr; /* source/target rows */
    int moveStatus = 0;
    int checkStatus = 0;
    char currPlayer;

    initBoard(board);

    do {
        printBoard(board);
        printf("%s player move > ", player ? "White" : "Black");
        getPosition(&sc,&sr);
        scanf("%c", &empty);
        getPosition(&tc,&tr);
        scanf("%c", &empty);
        currPlayer = getPlayer(board, sc,sr);

        if(!isValidCell(sc,sr)) {
            printf("Source position is invalid\n");
            continue;
        }
        if(!isValidCell(tc,tr)) {
            printf("Target position is invalid\n");
            continue;
        }
        if((isBlack(currPlayer) && player) ||
           (isWhite(currPlayer) && !player)) {
            printf("Illegal piece. \n");
            continue;
        }

        moveStatus = makeMove(board,sc,sr,tc,tr);
        switch(moveStatus) {
            case 0:
                printf("Invalid move!\n");
                break;
            case 1:
                printf("Your king is in check!\n");
                ++checkStatus;
                break;
            case 3:
                printf("Check!\n ");
            case 2:             
                player = !player;
                checkStatus = 0;
                break;
        }
    } while(checkStatus < 2);
    printf("%s player WINS!\n", player ? "White" : "Black");
    return 0;
}
int initBoard(char *board)
{
	int i;

	board[0]='r';
	board[1]='n';
	board[2]='b';
	board[3]='q';
	board[4]='k';
	board[5]='b';
	board[6]='n';
	board[7]='r';
	
	for(i=8; i<16; i++){
		
		board[i]='p';
	} /* End of for */
	for(i=16; i<48; i++){
	
		board[i]=' ';
	}/* End of for */
	board[56]='R';
	board[57]='N';
	board[58]='B';
	board[59]='Q';
	board[60]='K';
	board[61]='B';
	board[62]='N';
	board[63]='R';
	
	for(i=48; i<56; i++){
	
		board[i]='P';
	} /* End of for */
	return 0;
}
/*----------------------------------------------------------------------------*/
/* Function printBoard                                                        */
/* -------------------      								             	  */
/*		This function will print the current state of the board as show       */
/*		above.																  */

void printBoard(char *board){
	
	int i,j,k;
	
	i=0;
	j=8;
	printf("  a b c d e f g h\n");
	printf("  - - - - - - - -\n");
	printf("%d|",j--);
	
	for(k=1; i<(BOARD_SIZE*BOARD_SIZE); k++){
	
		if(i==0 || i==8 || i==16 || i==24 || i==32 || i==40 || i==48 || i==56){
		
		
			printf("%c",board[i]);
		
		} /* End of if(i==0 || ...) */
		else{
		
			printf(" %c",board[i]);
		} /* Enf of else if */
		if(k%(8)==0){
		
			if(j!=0){
			
			printf("|\n");
			printf("%d|",j--);
			} /* End of if(j!=0) */
		
		} /* End of if(k%(8)==0) */
		i++;
	} /* En of for(k=1; i<SIZE; k++) */	
	printf("|\n");
	printf("  - - - - - - - -\n");		

	return;
}
/*----------------------------------------------------------------------------*/
/* Function getPosition                                                       */
/* -------------------------------------                                      */
/*		This function will take the row and column values of a                */
/*		specific cell on the board.                                           */

void getPosition(char *col, int *row){

	scanf(" %c",col);
	scanf("%d",row);
	
	return;
}
/*----------------------------------------------------------------------------*/
/* Function isValidCell                                                       */
/* ------------------------------------                                       */
/*		This function will check whether the given cell is valid              */  
/*		according to the board sizes and returns 1 if it is valid,            */
/*		otherwise 0.													      */

int isValidCell(char col, int row){

	if(col=='a' || col=='b' || col=='c' || col=='d' || col=='e' || col=='f' ||
		 col=='g' || col=='h'){
	
		if(row==8 || row==7 || row==6 || row==5 || row==4 || row==3 || 
			row==2 || row==1){
	
			return VALID;
		}
		return INVALID;
	}
	else return 0;
	
	return 0;	
}
/*----------------------------------------------------------------------------*/
/* Function isBlack                                                           */
/* ----------------------------                                               */
/*		This function find the color of player.                               */

int isBlack(char currPlayer){
	
	if(currPlayer=='p' || currPlayer=='r' || currPlayer=='n' || 
		currPlayer=='b' || currPlayer=='q' || currPlayer=='k')	
		
		return 1;
		
	return 0;
}
/*----------------------------------------------------------------------------*/
/* Function isWhite                                                           */
/* ----------------------------                                               */
/*		This function find the color of player.                               */

int isWhite(char currPlayer){

	if(currPlayer=='P' || currPlayer=='R' || currPlayer=='N' || 
		currPlayer=='B' || currPlayer=='Q' || currPlayer=='K')	
		
		return 1;
		
	return 0;
}
/*----------------------------------------------------------------------------*/
/* Function getPlayer                                                         */
/* ------------------                                                         */
/*		This function find player who play the game.                          */

char getPlayer(char *board,char col,int row){

	char player;
	int index;
	
	index=whichIndex(col,row);
	player=board[index];

	return player;
}
/*----------------------------------------------------------------------------*/
/* Function whichIndex                                                        */
/* ------------------------------                                             */
/*		This function will find the index of source cell and target cell.     */

int whichIndex(char col,int row){

	int index;
	
	if(col=='a'){
		
		switch(row){
		
			case 8: index=0; break;
			case 7: index=8; break;
			case 6: index=16; break;
			case 5: index=24; break;
			case 4: index=32; break;
			case 3: index=40; break; 
			case 2: index=48; break;
			case 1: index=56; break;
		}
	}
	else if(col=='b'){
	
	   switch(row){
		
			case 8: index=1; break;
			case 7: index=9; break;
			case 6: index=17; break;
			case 5: index=25; break;
			case 4: index=33; break;
			case 3: index=41; break; 
			case 2: index=49; break;
			case 1: index=57; break;
		}
	}
	else if(col=='c'){
	
		switch(row){
		
			case 8: index=2; break;
			case 7: index=10; break;
			case 6: index=18; break;
			case 5: index=26; break;
			case 4: index=34; break;
			case 3: index=42; break; 
			case 2: index=50; break;
			case 1: index=58; break;
		}
	}
	else if(col=='d'){
	
		switch(row){
		
			case 8: index=3; break;
			case 7: index=11; break;
			case 6: index=19; break;
			case 5: index=27; break;
			case 4: index=35; break;
			case 3: index=43; break; 
			case 2: index=51; break;
			case 1: index=59; break;
		}
	}
	else if(col=='e'){
	
		switch(row){
		
			case 8: index=4; break;
			case 7: index=12; break;
			case 6: index=20; break;
			case 5: index=28; break;
			case 4: index=36; break;
			case 3: index=44; break; 
			case 2: index=52; break;
			case 1: index=60; break;
		}
	}
	else if(col=='f'){
	
		switch(row){
		
			case 8: index=5; break;
			case 7: index=13; break;
			case 6: index=21; break;
			case 5: index=29; break;
			case 4: index=37; break;
			case 3: index=45; break; 
			case 2: index=53; break;
			case 1: index=61; break;
		}
	}
	else if(col=='g'){
	
		switch(row){
		
			case 8: index=6; break;
			case 7: index=14; break;
			case 6: index=22; break;
			case 5: index=30; break;
			case 4: index=38; break;
			case 3: index=46; break; 
			case 2: index=54; break;
			case 1: index=62; break;
		}
	}
	else if(col=='h'){
	
	    switch(row){
		
			case 8: index=7; break;
			case 7: index=15; break;
			case 6: index=23; break;
			case 5: index=31; break;
			case 4: index=39; break;
			case 3: index=47; break; 
			case 2: index=55; break;
			case 1: index=63; break;
		}
	}
    return index;
}
/*----------------------------------------------------------------------------*/
/* Function whichColumn                                                       */
/* ---------------------------                                                */
/*		This function find column of index.                                   */

char whichColumn(int index){

	char col;

	if((index%8)==0) col='a';
	if((index%8)==1) col='b';
	if((index%8)==2) col='c';
	if((index%8)==3) col='d';
	if((index%8)==4) col='e';
	if((index%8)==5) col='f';
	if((index%8)==6) col='g';
	if((index%8)==7) col='h';
	
	return col;
}
/*----------------------------------------------------------------------------*/
/* Function whichRow                                                          */
/* ---------------------------                                                */
/*		This function find row of index.                                      */

int whichRow(int index){

	int row;

	if(index>=0 && index<=7)   row=8;
	if(index>=8 && index<=15)  row=7;
	if(index>=16 && index<=23) row=6;
	if(index>=24 && index<=31) row=5;
	if(index>=32 && index<=39) row=4;
	if(index>=40 && index<=47) row=3;
	if(index>=48 && index<=55) row=2;
	if(index>=56 && index<=63) row=1;

	return row;
}
/*----------------------------------------------------------------------------*/
/* Function isPieceMovable                                                    */
/* -------------------------------                                            */
/*		It asks the user the source and target positions and check            */
/*		whether the piece in the source cell can be movable to the            */
/*		target cell.                                                          */

int isPieceMovable(char *board,char sc, int sr, char tc, int tr){

	int sIndex,result; 

	sIndex=whichIndex(sc,sr);  

		switch(board[sIndex]){
	
			case 'p':
			case 'P':
					result=isPawnMovable(board, sc, sr, tc, tr);
					break; 
			case 'r':
			case 'R':
					result=isRookMovable(board, sc, sr, tc, tr);
					break;
			case 'n':
			case 'N':
					result=isKnightMovable(board, sc, sr, tc, tr);
					break;
			case 'b':
			case 'B':
		            result=isBishopMovable(board, sc, sr, tc, tr);
					break;
			case 'q':
			case 'Q':
					result=isQueenMovable(board, sc, sr, tc, tr);
					break;
			case 'k':
			case 'K':
					result=isKingMovable(board, sc, sr, tc, tr);
					break;
		} /* Enf of switch(board[i]) */
				
	return result;
}

/*----------------------------------------------------------------------------*/
/* Function makeMove                                                          */
/* -------------------                                                        */
/*		This function moves a piece from source to destination if current     */
/*		player's king is not in check and piece can move from source to       */
/*		destination. If player's king is in check, move should not be         */
/*		made and board should remain same.                                    */

int makeMove(char *board, char sc, int sr, char tc, int tr){

	int moveValid,source,target,checkStatus1,checkStatus2;
	char tempS,tempT;
	
	moveValid=isPieceMovable(board,sc,sr,tc,tr);
	/*printf("moveValid: %d\n",moveValid);*/
	checkStatus1=isInCheck(board);
	/*printf("checkstatus 1: %d\n",checkStatus1);*/
	
	if(moveValid==1){
	
		source=whichIndex(sc,sr);
		target=whichIndex(tc,tr);
		
		/* move to destination */
		tempS=board[source];
		tempT=board[target];
		board[target]=board[source];
		board[source]=' ';

		checkStatus2=isInCheck(board);
		/* printf("checkstatus 2: %d\n",checkStatus2); */
		
		if(checkStatus1==0 && checkStatus2==1) return 3;
		if(checkStatus1==0 && checkStatus2==2) return 3;
	
		if(checkStatus1==1 && checkStatus2==1){
	
		 /* board should remain same */
			board[source]=tempS;
			board[target]=tempT;
	
			return 1;
		}
		if(checkStatus1==2 && checkStatus2==2){
	
		 /* board should remain same */
			board[source]=tempS;
			board[target]=tempT;
	
			return 1;
		}
 		return 2;
	}
	return 0;
}
/*----------------------------------------------------------------------------*/
/* Function isInCheck                                                         */
/* --------------------------                                                 */
/*		This function checks whether a king is in check or not.               */

int isInCheck(char* board){

	int search,kingW,kingB,kingRowW,kingRowB,sr,result;
	char kingColW,kingColB,sc;

	for(kingW=0; board[kingW]!='K'; kingW++){
		 /* white king index */  
	}
	for(kingB=0; board[kingB]!='k'; kingB++){
		 /* black king index */ 
	}
	kingColW=whichColumn(kingW); /* white king column */
	kingRowW=whichRow(kingW);    /* white king row    */
	
	kingColB=whichColumn(kingB); /* black king column */
	kingRowB=whichRow(kingB);    /* black king row    */

	for(search=0; search<(BOARD_SIZE*BOARD_SIZE); search++){
		
		/* make search on board */
		sc=whichColumn(search);
		sr=whichRow(search); 
	
		/* check for white king */	
		if(board[search]>='a' && board[search]<='z'){ 
			
			switch(board[search]){
				
				case 'q': 
						result=isQueenMovable(board,sc,sr,kingColW,kingRowW); 
						break;
				case 'b': 
						result=isBishopMovable(board,sc,sr,kingColW,kingRowW); 
						break;
				case 'n': 
						result=isKnightMovable(board,sc,sr,kingColW,kingRowW); 
						break;
				case 'p': 
						result=isPawnMovable(board,sc,sr,kingColW,kingRowW); 
						break;
				case 'r': 
						result=isRookMovable(board,sc,sr,kingColW,kingRowW); 
						break;
			}
			if(result==1) return 1;
		}
		/* check for black king */
		if(board[search]>='A' && board[search]<='Z'){
		
			switch(board[search]){
						
				case 'Q': 
						result=isQueenMovable(board,sc,sr,kingColB,kingRowB); 
						break;
				case 'B': 
						result=isBishopMovable(board,sc,sr,kingColB,kingRowB); 
						break;
				case 'N': 
						result=isKnightMovable(board,sc,sr,kingColB,kingRowB); 
						break;
				case 'R': 
						result=isRookMovable(board,sc,sr,kingColB,kingRowB); 
						break;
				case 'P': 
						result=isPawnMovable(board,sc,sr,kingColB,kingRowB); 
						break;	
			}
			if(result==1) return 2;		
		}
	}  
	return 0;
}
/*----------------------------------------------------------------------------*/
/* Function isKnightMovable                                                   */
/* ------------------------                                                   */
/*		This function will check whether a knight can move from source        */
/*		cell to the target cell according to the rules of the game.           */

int isKnightMovable(char *board, char sourceCol, int sourceRow, 
					char targetCol, int targetRow)
{					
	int sourceIndex,targetIndex;

	sourceIndex=whichIndex(sourceCol,sourceRow);
	targetIndex=whichIndex(targetCol,targetRow);
    
    if(board[targetIndex]==' ' || 
            abs(board[targetIndex]-board[sourceIndex])>=SMALLEST_DIFF){
	
		if(targetCol==sourceCol+1 && targetRow==sourceRow+2) return 1;
		if(targetCol==sourceCol+1 && targetRow==sourceRow-2) return 1;	
		if(targetCol==sourceCol-1 && targetRow==sourceRow+2) return 1;
		if(targetCol==sourceCol-1 && targetRow==sourceRow-2) return 1;
		if(targetCol==sourceCol+2 && targetRow==sourceRow+1) return 1;
		if(targetCol==sourceCol-2 && targetRow==sourceRow+1) return 1;
		if(targetCol==sourceCol+2 && targetRow==sourceRow-1) return 1;
		if(targetCol==sourceCol-2 && targetRow==sourceRow-1) return 1;
	
	}
	return 0;
}
/*----------------------------------------------------------------------------*/
/* Function isRookMovable                                                     */
/* ------------------------                                                   */
/*		This function will check whether a rook can move from source          */
/*		cell to the target cell according to the rules of the game.           */

int isRookMovable(char *board, char sourceCol, int sourceRow, 
				char targetCol, int targetRow)
{
	int sourceIndex,targetIndex,i,row;
	char col;

	sourceIndex=whichIndex(sourceCol,sourceRow);
	targetIndex=whichIndex(targetCol,targetRow);

	if(board[targetIndex]==' ' || 
		abs(board[targetIndex]-board[sourceIndex])>=SMALLEST_DIFF){

		if(targetCol==sourceCol){
		
			if(targetRow>sourceRow){
		
				col=sourceCol;		
				row=sourceRow+1;
				
				while(row!=targetRow){
				
					i=whichIndex(col,row);
				
					if(board[i]==' ') row++;
				
					else return 0;
				}
				return 1;						
			}
			if(targetRow<sourceRow){
				
				col=sourceCol;
				row=sourceRow-1;
				while(row!=targetRow){
				
					i=whichIndex(col,row);
				
					if(board[i]==' ') row--;
				
					else return 0;
				}
				return 1;						
			}
		}
		if(targetRow==sourceRow){
		
			if(targetCol>sourceCol){
				
				row=sourceRow;
				col=sourceCol+1;
				while(col!=targetCol){
				
					i=whichIndex(col,row);
				
					if(board[i]==' ') col++;
				
					else return 0;
				}
				return 1;						
			}
			if(targetCol<sourceCol){
				
				row=sourceRow;
				col=sourceCol-1;
				while(col!=targetCol){
				
					i=whichIndex(col,row);
				
					if(board[i]==' ') col--;
				
					else return 0;
				}
				return 1;						
			}
		}
	}
    return 0;
}
/*----------------------------------------------------------------------------*/
/* Function isKingMovable                                                     */
/* ------------------------                                                   */
/*		This function will check whether a king can move from source          */
/*		cell to the target cell according to the rules of the game.           */
 
int isKingMovable(char *board, char sourceCol, int sourceRow, 
				char targetCol, int targetRow)
{
	int sourceIndex,targetIndex;
	int status1,status2,status3,status4,status5,status6,status7,status8;
	
	sourceIndex=whichIndex(sourceCol,sourceRow);
	targetIndex=whichIndex(targetCol,targetRow);
	
	if(board[sourceIndex]=='k'){
	
		if(board[targetIndex]==' ' || 
			(abs(board[targetIndex]-board[sourceIndex])>=SMALLEST_DIFF)){
		
			/* block matches two king */
            status1=whichIndex(targetCol+1,targetRow+1); 
            status2=whichIndex(targetCol,targetRow+1);
            status3=whichIndex(targetCol-1,targetRow+1);
            status4=whichIndex(targetCol-1,targetRow);
            status5=whichIndex(targetCol+1,targetRow);
            status6=whichIndex(targetCol-1,targetRow-1);
            status7=whichIndex(targetCol,targetRow-1);
            status8=whichIndex(targetCol+1,targetRow-1);
            
            if(board[status1]=='K') return 0;
            if(board[status2]=='K') return 0;
            if(board[status3]=='K') return 0;
            if(board[status4]=='K') return 0;
            if(board[status5]=='K') return 0;
            if(board[status6]=='K') return 0;
            if(board[status7]=='K') return 0;
            if(board[status8]=='K') return 0;
            
			if((targetCol==sourceCol+1) && (targetRow==sourceRow+1)) return 1;
			if((targetCol==sourceCol-1) && (targetRow==sourceRow+1)) return 1;
			if((targetCol==sourceCol+1) && (targetRow==sourceRow-1)) return 1;
			if((targetCol==sourceCol-1) && (targetRow==sourceRow-1)) return 1;
			if(((targetCol==sourceCol+1) || (targetCol==sourceCol-1)) 
					&& (targetRow==sourceRow)) return 1;
			if((targetCol==sourceCol) && ((targetRow==sourceRow+1) || 
					(targetRow==sourceRow-1))) return 1;
		
		}
	}
	if(board[sourceIndex]=='K'){
	
		if(board[targetIndex]==' ' || 
			(abs(board[targetIndex]-board[sourceIndex])>=SMALLEST_DIFF)){
             
            /*  block matches two king  */ 
            status1=whichIndex(targetCol+1,targetRow+1); 
            status2=whichIndex(targetCol,targetRow+1);
            status3=whichIndex(targetCol-1,targetRow+1);
            status4=whichIndex(targetCol-1,targetRow);
            status5=whichIndex(targetCol+1,targetRow);
            status6=whichIndex(targetCol-1,targetRow-1);
            status7=whichIndex(targetCol,targetRow-1);
            status8=whichIndex(targetCol+1,targetRow-1);
            
            if(board[status1]=='k') return 0;
            if(board[status2]=='k') return 0;
            if(board[status3]=='k') return 0;
            if(board[status4]=='k') return 0;
            if(board[status5]=='k') return 0;
            if(board[status6]=='k') return 0;
            if(board[status7]=='k') return 0;
            if(board[status8]=='k') return 0;
            	
			if((targetCol==sourceCol+1) && (targetRow==sourceRow+1)) return 1;
			if((targetCol==sourceCol-1) && (targetRow==sourceRow+1)) return 1;
			if((targetCol==sourceCol+1) && (targetRow==sourceRow-1)) return 1;
			if((targetCol==sourceCol-1) && (targetRow==sourceRow-1)) return 1;
			if(((targetCol==sourceCol+1) || (targetCol==sourceCol-1)) && 
					(targetRow==sourceRow)) return 1;
			if((targetCol==sourceCol) && ((targetRow==sourceRow+1) || 
					(targetRow==sourceRow-1))) return 1;
		
		}
	}
	return 0;
}
/*----------------------------------------------------------------------------*/
/* Function isQueenMovable                                                    */
/* ------------------------                                                   */
/*		This function will check whether a queen can move from source         */
/*		cell to the target cell according to the rules of the game.           */

int isQueenMovable(char *board, char sourceCol, int sourceRow, 
		char targetCol, int targetRow)
{
	int sourceIndex,targetIndex,i,j,row;
	char col;

	sourceIndex=whichIndex(sourceCol,sourceRow);
	targetIndex=whichIndex(targetCol,targetRow);
	
	if(board[targetIndex]==' ' || 
			abs(board[targetIndex]-board[sourceIndex])>=SMALLEST_DIFF){
	
		if((targetCol>sourceCol) && (targetRow>sourceRow)){
	
			row=sourceRow+1;
			col=sourceCol+1;
			
			while((row!=targetRow) && (col!=targetCol)){
			
				i=whichIndex(col,row);
				
				if(board[i]!=' ') return 0;
					
				col++;
				row++;
				
				j=whichIndex(col,row);
			}
		
				if(targetIndex!=j) return 0;
			
				else if(targetIndex==j) return 1;			
		}
		if((targetCol>sourceCol) && (targetRow<sourceRow)){
	
			row=sourceRow-1;
			col=sourceCol+1;
					
			while((row!=targetRow) && (col!=targetCol)){ 
			
				i=whichIndex(col,row);
	
				if(board[i]!=' ') return 0;
				
				col++;
				row--;
	
				j=whichIndex(col,row);
			}
			if(targetIndex!=j) return 0;
			
			else if(targetIndex==j) return 1;		
		}
		if((targetCol<sourceCol) && (targetRow>sourceRow)){
	
			row=sourceRow+1;
			col=sourceCol-1;
			
			while((row!=targetRow) && (col!=targetCol)){ 
			
				i=whichIndex(col,row);
			
				if(board[i]!=' ') return 0;
		
				col--;
				row++;
		
				j=whichIndex(col,row);
			
			}	
				if(targetIndex!=j) return 0;
				
				else if(targetIndex==j) return 1;				
		}
		if((targetCol<sourceCol) && (targetRow<sourceRow)){
	
			row=sourceRow-1;
			col=sourceCol-1;
			
			while((row!=targetRow) && (col!=targetCol)){
			
				i=whichIndex(col,row);
		
				if(board[i]!=' ') return 0;	
			
				col--;
				row--;
				
				j=whichIndex(col,row);
								
			}
			
			if(targetIndex!=j) return 0;
				
			else if(targetIndex==j) return 1;						
		}	
		if(targetCol==sourceCol){
		
			if(targetRow>sourceRow){
		
				col=sourceCol;		
				row=sourceRow+1;
				
				while(row!=targetRow){
				
					i=whichIndex(col,row);
				
					if(board[i]==' ') row++;
				
					else return 0;
				}
				return 1;						
			}
			if(targetRow<sourceRow){
				
				col=sourceCol;
				row=sourceRow-1;
				
				while(row!=targetRow){
				
					i=whichIndex(col,row);
				
					if(board[i]==' ') row--;
				
					else return 0;
				}
				return 1;						
			}
		}
		if(targetRow==sourceRow){
		
			if(targetCol>sourceCol){
				
				row=sourceRow;
				col=sourceCol+1;
				
				while(col!=targetCol){
				
					i=whichIndex(col,row);
				
					if(board[i]==' ') col++;
				
					else return 0;
				}
				return 1;						
			}
			if(targetCol<sourceCol){
				
				row=sourceRow;
				col=sourceCol-1;
				
				while(col!=targetCol){
				
					i=whichIndex(col,row);
					
					if(board[i]==' ') col--;
				
					else return 0;
				}
				return 1;						
			}
		}
	}
	return 0;
}
/*----------------------------------------------------------------------------*/
/* Function isBishopMovable                                                   */
/* ------------------------                                                   */
/*		This function will check whether a bishop can move from source        */
/*		cell to the target cell according to the rules of the game.           */

int isBishopMovable(char *board, char sourceCol, int sourceRow, 
			char targetCol, int targetRow)
{
	int sourceIndex,targetIndex,i,j,row;
	char col;

	sourceIndex=whichIndex(sourceCol,sourceRow);
	targetIndex=whichIndex(targetCol,targetRow);
	
	if(board[targetIndex]==' ' || 
			abs(board[targetIndex]-board[sourceIndex])>=SMALLEST_DIFF){

		if((targetCol>sourceCol) && (targetRow>sourceRow)){
	
			row=sourceRow+1;
			col=sourceCol+1;
			
			while((row!=targetRow) && (col!=targetCol)){ 
			
				i=whichIndex(col,row);
				
				if(board[i]!=' ') return 0;
					
				col++;
				row++;
				
				j=whichIndex(col,row);
			}
				if(targetIndex!=j) return 0;
			
				else return 1;			
		}
		if((targetCol>sourceCol) && (targetRow<sourceRow)){
	
			row=sourceRow-1;
			col=sourceCol+1;
					
			while((row!=targetRow) && (col!=targetCol)){ 
			
				i=whichIndex(col,row);
	
				if(board[i]!=' ') return 0;
				
				col++;
				row--;
		
				j=whichIndex(col,row);
			}
		
			if(targetIndex!=j) return 0;
			
			else return 1;		
		}
		if((targetCol<sourceCol) && (targetRow>sourceRow)){
	
			row=sourceRow+1;
			col=sourceCol-1;
				
			while((row!=targetRow) && (col!=targetCol)){ 
			
				i=whichIndex(col,row);
						
				if(board[i]!=' ') return 0;
		
				col--;
				row++;
			
				j=whichIndex(col,row);
			
			}	
				if(targetIndex!=j) return 0;
				
				else return 1;				
		}
		if((targetCol<sourceCol) && (targetRow<sourceRow)){
	
			row=sourceRow-1;
			col=sourceCol-1;
			
			while((row!=targetRow) && (col!=targetCol)){
			
				i=whichIndex(col,row);
		
				if(board[i]!=' ') return 0;	
			
				col--;
				row--;
			
				j=whichIndex(col,row);
								
			}
			if(targetIndex!=j) return 0;
				
			else return 1;						
		}	
	}
    return 0;
}
/*----------------------------------------------------------------------------*/
/* Function isPawnMovable                                                     */
/* ------------------------                                                   */
/*		This function will check whether a pawn can move from source          */
/*		cell to the target cell according to the rules of the game.           */

int isPawnMovable(char *board, char sourceCol, int sourceRow, 
			char targetCol, int targetRow)
{
	int sourceIndex,targetIndex;

	sourceIndex=whichIndex(sourceCol,sourceRow);
	targetIndex=whichIndex(targetCol,targetRow);

	if(board[sourceIndex]=='p'){
	
		/* can make two steps for start */
		if(sourceRow==7){
		
			if(((targetIndex-sourceIndex)==SMALLEST_DIFF) &&
			    board[targetIndex]==' '){
	
			 	return 1;	
			}
		}
		if(((targetIndex-sourceIndex)==8) && board[targetIndex]==' '){
	
		 	return 1;	
		}
		if((targetCol==sourceCol+1) && (targetRow==sourceRow-1)){

			if((board[targetIndex])!=' ' && 
				((board[targetIndex])>='A' && (board[targetIndex])<='Z')){
	
				return 1;
			}
			else return 0;
		}
		if((targetCol==sourceCol-1) && (targetRow==sourceRow-1)){

			if((board[targetIndex])!=' ' && 
				((board[targetIndex])>='A' && (board[targetIndex])<='Z')){
		
				return 1;
			}
			else return 0;
		}
	}/* end of if(board[sourceIndex]=='p') */
	
	if(board[sourceIndex]=='P'){
	
		/* can make two steps for start */
		if(sourceRow==2){
		
			if(((targetIndex-sourceIndex)==-16) && board[targetIndex]==' '){
	
			 	return 1;	
			}
		}
		if(((targetIndex-sourceIndex)==(-8)) && board[targetIndex]==' '){
		
			return 1;
		}
		if((targetCol==sourceCol+1) && (targetRow==sourceRow+1)){

			if((board[targetIndex])!=' ' && 
				((board[targetIndex])>='a' && (board[targetIndex])<='z')){
			
				return 1;
			}
			else return 0;
		}
		if((targetCol==sourceCol-1) && (targetRow==sourceRow+1)){

			if((board[targetIndex])!=' ' && 
				((board[targetIndex])>='a' && (board[targetIndex])<='z')){
		
				return 1;
			}
			else return 0;
		}
	}/* enf of if(board[sourceIndex]=='P') */
	return 0;
}
/*----------------------------------------------------------------------------*/
/*                          End of main.c                                     */
/*----------------------------------------------------------------------------*/
