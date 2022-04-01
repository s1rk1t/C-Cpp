#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>

#include"board.h"
#include"space.h"
#include"minesweeper.h"
#include"art.h"




int main(int argc, char ** args){

using std::cout;

if(argc == 2){

cout << "in main 0" << endl;
//read in data from file
string arg = args[1];
ifstream ifs;
ifs.open(arg);
stringstream ss;
string line;
getline(ifs, line);
ss << line;

int rows;

ss >> rows;
cout << rows << endl;
const int r = rows;

int cols;
ss >> cols;
cout << cols << endl;
const int c = cols;

getline(ifs, line);


cout << line << endl;
int nMines;
ss.clear();
ss << line;

ss >> nMines;
cout << nMines << endl;
vector<int> mineLoc;
ss.clear();
int mineX;
int mineY;
while(getline(ifs, line)){
ss << line;
ss >> mineX;
ss.clear();
ss >> mineY;
ss.clear();

mineLoc.push_back(mineX);
mineLoc.push_back(mineY);}
cout << mineLoc[0] << endl;
cout << mineLoc[1] << endl;


//declare minesweeper object
Board board(rows, cols);
board.checkBounds(rows, cols);
Minesweeper minesweeper(rows, cols, nMines, mineLoc);  


Space ** spaceArray = board.initSpaces(rows, cols);
//initialize spaces to proper row and column

spaceArray = board.initPositions(spaceArray);
//connect the dots

board.initPointers(spaceArray, rows, cols);
//place the mines

minesweeper.seedMines(spaceArray, mineLoc, minesweeper.nMines);
//game play manager initialization


minesweeper.printMain();

//start gameplay

	while(minesweeper.isWon == false){

	board.updateBoardState(minesweeper.rounds, spaceArray);	
	cout << " in main ten" << endl;
	minesweeper.menu(board, spaceArray);
	cout << " in main eleven" << endl;
	minesweeper.checkWin(board, spaceArray);
	cout << "in main 12" << endl;
	}//endwhile
	//TODO:	delete[] spaceArray;//deallocate dynamic memory

//TODO:test get input, test display of ASCII/doge, quit stuff
        }//end if
	Art art;
	string error = art.errorArt(); 
	if (argc != 2) {cout << error << "Incorrect number of command line arguments/nPlease re-enter command from terminal."<< endl;
	}//endif     
return EXIT_SUCCESS;}//end maini


