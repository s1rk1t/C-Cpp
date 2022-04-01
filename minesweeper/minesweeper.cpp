#include<iostream>

#include<vector>

#include<sstream>

#include<string>

#include<cstdlib>

#include<iterator>

#include<algorithm>


#include"space.h"
#include"board.h"
#include"minesweeper.h"
#include"art.h"



using namespace std;

Minesweeper::Minesweeper(int r,int c, int nM, vector<int> mineL){

rows = r;
cols= c;
nMines = nM;
vector<int> mineLoc = mineL;
rounds = 0;

//initialize variables


}



void Minesweeper::menu(Board & board, Space ** array){

	if(isWon == false){
	cout << "minesweeper$ " << endl;
	//create string to hold input
	string input;
	int row = 0;
	int col = 0;
	stringstream ss;
	cin >> input;
	
	
	string command;
  	command = input;
	






	if(command.at(0) == 'q' ||  command.at(0) == 'Q'){

	if((command.size() > 1 && (command == "quit" || command == "QUIT")) || command.size() == 1){
	quit();}
	else{
	Art art;
	cout << " " << endl;
        cout << art.errorArt() << " Command not recognized, please rerenter command" << endl;
        this->rounds++;
	//system("clear");
	board.updateBoardState(this->rounds, array);
        menu(board, array);}

	
	}//end quit
	
	
	else if (command.at(0) == 'h' || command.at(0) == 'H')
	{
	if((command.size() > 1 && command == "help" || "HELP") || command.size() == 1){
	rounds++;

	help();
	//system("clear");
	board.updateBoardState(this->rounds, array);//end help	
	menu(board, array);}
	else {
	
	Art art;

	string error = art.errorArt();
	
	rounds++;
	cout << " " <<endl;
	cout << error << " Input is unrecognized! Please re-enter your selection." << endl;

	board.updateBoardState(this->rounds, array);
	menu(board, array);}
	
	
}


	cin >> row;
	cin >> col;	
	//check boundary conditions for entered rows and columns
	if(row > board.rows || col > board.cols || row < 0 || col < 0){
	Art art;
	cout << art.errorArt() << "Your entry does not fall within the scope of the board layout."<< endl;
	cout<< " Please re-enter your command using a number between 0 and " << board.rows-1 << " for rows, and between 0 and " << board.cols-1 << " for columns." << endl;
	this->rounds++;
	}
	//if mark is input
	if(command.at(0) == 'm' || command.at(0) == 'M'){
	
	
	//error checking
	if(((command.size() > 1 && (command == "mark" || "MARK")) || command.size() == 1) && (row < board.rows && rows >= 0 && col < board.cols && col >= 0)){
	
	this->rounds++;

	flag(array, row, col);
	system("clear");
	board.updateBoardState(this->rounds, array);
	checkWin(board, array);
	menu(board,array);	
	}
	else{
	Art art;
	cout << art.errorArt() << " Command not recognized!" << endl;
	this->rounds++;
	
	system("clear");
	board.updateBoardState(this->rounds, array);
	
	menu(board, array);

	}
	
	}

	else if(command.at(0) == 'g' || command.at(0) == 'G'){
	
	if(((command.size() > 1 && (command == "guess" || "GUESS")) || command.size() == 1) && (row < board.rows && rows >= 0 && col < board.cols && col >= 0)){
	guess(array, row, col);
	this->rounds++;
	
	system("clear");
	board.updateBoardState(this->rounds, array);
	checkWin(board,array);
	
	menu(board, array);
	}
	else{
	Art art;
	cout << " " << endl;
        cout << art.errorArt() << " Command not recognized!" << endl;        this->rounds++;
	system("clear");
	board.updateBoardState(this->rounds, array);
        menu(board, array);}

	
	}//end g
	
	else if(command.at(0) == 'r' || command.at(0) == 'R'){

	if(((command.size() > 1 && (command == "reveal" || "REVEAL"))|| command.size() == 1) && (row < board.rows && rows >= 0 && col < board.cols && col >= 0)){
	
	this->rounds++;

	if(array[row][col].hasMine == true){

	Art art;
        vector<string> gameOver;
	gameOver = art.gameOverArt();
	ostream_iterator<string> os (cout, "\n");
	copy(gameOver.begin(), gameOver.end(), os);
	exit(0);}
	else{
        this->rounds++;
	revealMines(array[row][col]);
	string test;
	test = array[row][col].getState();
	
	//system("clear");
	board.updateBoardState(this->rounds, array);
        checkWin(board, array);
	menu(board, array);}	
	}
	}
	else if(command.at(0) != ('h' || 'r'|| 'q' || 'm'|| 'g')){

	Art art;
	cout << " " << endl;
	cout << art.errorArt() << "Command not recognized!" << endl;
	this->rounds++;
	board.updateBoardState(this->rounds, array);
	menu(board, array);
	}		
	else if(command.at(0) != ('h' || 'r'|| 'q' || 'm'|| 'g')){

	Art art;
	cout << " " << endl;
	cout << art.errorArt() << "Command not recognized!" << endl;
	this->rounds++;
	board.updateBoardState(this->rounds, array);
	menu(board, array);
	}		
	
	//end if(isWon == false)
}

	else{
	printDoge(board);
	exit(0);}
	
	}//end menu

///////BEGIN MENU OPTION///////////////////

 
void Minesweeper::flag(Space ** thisArray, int r, int c){


	if(thisArray[r][c].hasGuess == true){
	thisArray[r][c].hasGuess = false;}
	thisArray[r][c].hasFlag = true;
	}//end flag

void Minesweeper::guess(Space ** thisArray, int r, int c){
	
	//change state if nec
	if(thisArray[r][c].hasFlag == true) {
	thisArray[r][c].hasFlag = false;}
	thisArray[r][c].hasGuess = true;
	}//end guess

void Minesweeper::help(){
	cout << " Commands Available..." << endl;
	cout <<	" - Reveal: r/reveal row col" << endl;
	cout <<	" -   Mark: m/mark row col" << endl;
	cout <<	" -  Guess: g/guess row col" << endl;
	cout <<	" -   Help: h/help" << endl;
	cout <<	" -   Quit: q/quit" << endl;
	
	}//end help

void Minesweeper::quit(){
	printQuit();
	exit(0);
	}//end quit


///////////END MENU OPTIONS/////////////////

void Minesweeper::seedMines(Space ** array, vector<int> & mineLoc, int & nMines){
       int mineRow;
	int mineCol;
        stringstream ss;
        for(int i = 0; i < nMines; i++){
	//accessing data in vector algorithm == 2*i and 2*i+1	
	mineRow = mineLoc[2*i];
	mineCol = mineLoc[2*i+1];
        array[mineRow][mineCol].hasMine = true;
	
	     
	}//end for

	}//end seedMines








/////////////BEGIN PRINT FUNCTIONS//////////////////


void Minesweeper::printMain(){
  	Art art;
	vector<string> mainVector = art.introArt();  
	for(int i = 0; i < 5; i++){
          //first six lines are the minesweeper ASCII art
          cout << mainVector.at(i) << endl;
                  }
  
          }//end printMain
  
void Minesweeper::printQuit(){
	Art art;
	vector<string> quitArt = art.quitArt();
	ostream_iterator<string> os(cout, "\n");
	copy(quitArt.begin(), quitArt.end(), os);
	}//end printEnd

void Minesweeper::printGameOver(){

	Art art;
	vector<string> gameOverVector = art.gameOverArt();
	for(int i; i < 6; ++i){
	cout << gameOverVector.at(i) << endl;
		}
	}//end printGameOver

void Minesweeper::printDoge(Board & board){
	cout << " " << endl;
	Art art;
	vector<string> dogeVector = art.dogeArt();
	ostream_iterator<string> os (cout, "\n");
	copy(dogeVector.begin(), dogeVector.end()-1, os);
	string str = dogeVector.back();
	cout << str << getScore(board) << endl;
	cout << " " << endl;
	exit(0);
	
	}//end printDoge


////////////END PRINT FUNCTIONS//////////////////



int Minesweeper::getScore(Board & board){

	score = (board.rows * board.cols) - this->nMines - rounds;
	return score; 

}



void Minesweeper::revealMines(Space & space){
	//check loss condition
	

	int temp = getMineCount(space);	

		
	space.isRevealed = true;
	if(temp == -1){space.isRevealed=false;}
	//if there's no mine nearby
         if(temp == 0){


         //make sure there's something there first, then check neighbors
         if (space.pN != 0 && (*space.pN).isRevealed == false) {
	revealMines(*space.pN);

	}


         if (space.pNW != 0 && (*space.pNW).isRevealed == false){ 

	revealMines(*space.pNW);

	}
         if (space.pW != 0 && (*space.pW).isRevealed == false) {revealMines(*space.pW);
	}
         if (space.pSW != 0 && (*space.pSW).isRevealed == false){ revealMines(*space.pSW);
	}
         if (space.pS != 0 && (*space.pS).isRevealed == false) {revealMines(*space.pS);
	}
         if (space.pSE != 0 && (*space.pSE).isRevealed == false){ revealMines(*space.pSE);}
	
         if (space.pE != 0 && (*space.pE).isRevealed == false) {revealMines(*space.pE);}
         if (space.pNE != 0 && (*space.pNE).isRevealed == false) {revealMines(*space.pNE);}
	
         }//endif
 
      space.mineCount = temp;  
         //make sure they will display in getState (if no mine present) by setting isRevealed to true
         
	
       
         

}//end revealMine

void Minesweeper::checkWin(Board & board, Space ** thisArray){
	int count = board.rows*board.cols;
	int flags = 0;
	int reveals = 0;
	
	for(int i = 0; i < 10; i++){
	for(int j = 0; j < 10;j++){
	if(thisArray[i][j].isRevealed == true){
	reveals++;}
	

	if((thisArray[i][j].hasMine == true) && (thisArray[i][j].hasFlag == true)){


	flags++;}
	
	

}//end checkWin
}
if((board.rows*board.cols - flags) <= reveals){
	 printDoge(board);}
}
//calculate and return number of mines close to Space argument
int Minesweeper::getMineCount(Space & space){
	int temp = 0;
	if(space.hasMine == false){
          //make sure there's a space there and then check for presence of a mine
          if((space.pN != 0) && ((*space.pN).hasMine == true)){
	
          temp++;
	}
          if((space.pNW != 0) && ((*space.pNW).hasMine == true)){
     
	
	 temp++;}
          if((space.pNE != 0) &&((*space.pNE).hasMine == true)){
    
	 
	 space.mineCount++;}
          if((space.pE != 0) && ((*space.pE).hasMine == true)){
    
    
	 temp++;}
          if((space.pSE != 0)  && ((*space.pSE).hasMine == true)){
    
 
	  temp++;}
          if((space.pS != 0) && ((*space.pS).hasMine == true)){
    
	  
	  temp++;}
          if((space.pSW != 0) && ((*space.pSW).hasMine == true)){
    
  
	  temp++;}
          if((space.pW != 0) && ((*space.pW).hasMine == true)){
     
	  temp++;}
          return temp;}

         else  if(space.hasMine == true){return -1;}  //if -1 is returned, there must be a mine present
         
          }//end getMineCount


/////////////////end minesweeper functions////////////////////


