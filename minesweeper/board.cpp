#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include"board.h"
#include"space.h"
#include"art.h"
#include<iomanip>//setw()
#include<cstdlib>
using namespace std;

//the board class serves to print the board in its current state
//it uses the Space class to draw information about the state of each space

Board::Board(int r, int c){
rows = r;
cols = c;
 
}
void Board::updateBoardState(int & rounds, Space ** spaceArray){


//first line 
cout <<"Number of Rounds Completed: " << rounds << endl;
cout << endl;
//head the board with the number of rounds

	//for loops print board based on const ints 'rows' and 'cols' 
	for(int i = 0; i < rows; i++){
	cout << " " << i;
	
	for(int j = 0; j < cols; j++){
	if(j == 9){
	cout << "|" << spaceArray[i][j].getState() << "|";}
	//if it's the first column, print the row number
	else {cout<< "|" << spaceArray[i][j].getState();}
	
	}//emdj;
	cout << endl;
	}//end i
	cout << "  ";
	//if it's the last row, print out the column nuimber
 	for (int i = 0; i < cols; i++){
	cout << setw(2) << i;
	}
	cout << endl; 
	
//check to see if it's dropping a line below the prompt for user input
}//end boardState

 //initialize all spaces and return them in a 2D array
  


Space ** Board::initSpaces(int rows, int cols){


Space ** array = new Space * [rows];

	for (int i = 0; i < rows; i++) {

    	array[i] = new Space [cols];}

	return array;

}

void Board::initPointers(Space ** allSpaces, int & rows, int & cols){
	
	for(int i=0; i < rows; i++){
	for(int j=0; j < cols; j++){

	if(allSpaces[i][j].row == 0 && allSpaces[i][j].col == 0){
	allSpaces[i][j].pE = &allSpaces[i][j+1];
	allSpaces[i][j].pSE = &allSpaces[i+1][j+1];
	allSpaces[i][j].pS = &allSpaces[i+1][j];
	}
	else if(allSpaces[i][j].row == 0 && allSpaces[i][j].col == cols-1){
	allSpaces[i][j].pW = &allSpaces[i][j-1];
	allSpaces[i][j].pSW = &allSpaces[i+1][j-1];
	allSpaces[i][j].pS = &allSpaces[i+1][j];	
	}
	else if(allSpaces[i][j].row == 0 && (allSpaces[i][j].col != cols-1 && allSpaces[i][j].col != 0 )){
	allSpaces[i][j].pW = &allSpaces[i][j-1];
	allSpaces[i][j].pSW = &allSpaces[i+1][j-1];
	allSpaces[i][j].pS = &allSpaces[i+1][j];
	allSpaces[i][j].pSE = &allSpaces[i+1][j+1];
	allSpaces[i][j].pE = &allSpaces[i][j+1];}
	else if(allSpaces[i][j].col == 0 && allSpaces[i][j].row == rows-1){
	allSpaces[i][j].pN = &allSpaces[i-1][j];
	allSpaces[i][j].pNE = &allSpaces[i-1][j+1];
	allSpaces[i][j].pE = &allSpaces[i][j+1];}
	else if(allSpaces[i][j].col = cols -1 && allSpaces[i][j].row == rows -1){
	allSpaces[i][j].pN = &allSpaces[i-1][j];
	allSpaces[i][j].pW = &allSpaces[i][j-1];
	allSpaces[i][j].pNW = &allSpaces[i-1][j-1];}
	else if(allSpaces[i][j].row == rows -1 && (allSpaces[i][j].col != 0 && allSpaces[i][j].col != cols-1)){
	allSpaces[i][j].pW = &allSpaces[i][j-1];
	allSpaces[i][j].pNW = &allSpaces[i-1][j-1];
	allSpaces[i][j].pN = &allSpaces[i-1][j];
	allSpaces[i][j].pNE = &allSpaces[i-1][j+1];
	allSpaces[i][j].pE = &allSpaces[i][j+1];}
	else if(allSpaces[i][j].col == 0 && allSpaces[i][j].row != 0 && allSpaces[i][j].row != rows-1){
	allSpaces[i][j].pN = &allSpaces[i-1][j];
	allSpaces[i][j].pSE = &allSpaces[i+1][j+1];
	allSpaces[i][j].pS = &allSpaces[i+1][j];
	allSpaces[i][j].pNE = &allSpaces[i-1][j+1];
	allSpaces[i][j].pE = &allSpaces[i][j+1];}
	else if(allSpaces[i][j].col == cols -1 && (allSpaces[i][j].row  != 0 && allSpaces[i][j].row != rows -1)){
	allSpaces[i][j].pW = &allSpaces[i][j-1];
	allSpaces[i][j].pN = &allSpaces[i-1][j];
	allSpaces[i][j].pS = &allSpaces[i+1][j];
	allSpaces[i][j].pNW = &allSpaces[i-1][j-1];
	allSpaces[i][j].pSW = &allSpaces[i+1][j-1];}
	else{
	allSpaces[i][j].pN = &allSpaces[i-1][j];
	allSpaces[i][j].pS = &allSpaces[i+1][j];
	allSpaces[i][j].pNW = &allSpaces[i-1][j-1];
	allSpaces[i][j].pSW = &allSpaces[i+1][j-1];	
	allSpaces[i][j].pE = &allSpaces[i][j+1];
	allSpaces[i][j].pW = &allSpaces[i][j-1];
	allSpaces[i][j].pNE = &allSpaces[i-1][j+1];
	allSpaces[i][j].pSE = &allSpaces[i+1][j+1];}
}//end i
}//end j
}//end initializePointers



Space ** Board::initPositions(Space ** array){
	for(int i = 0; i < this->rows; i++){
	for(int j = 0; j < this->cols; j++){
	
	array[i][j].row = i;
	array[i][j].col = j;
	}
	 }return array;

}//end initiSpaces
	

void Board::checkBounds(int rows, int cols){

if(rows > 10 || cols > 10 || rows <= 0 || cols <=0){
	Art art;
	cout<< art.errorArt() << "Cannot create a minefield with that many rows/columns." << endl;
	exit(0);
	}
}





//end Board function definitions


