#include <iostream>
#include "space.h"
#include<string>
#include<sstream>

using namespace std;



Space::Space(){

//all bools default to false
hasMine = false;
hasFlag = false;
hasGuess = false;
isRevealed = false;

int mineCount = 0;

}

///////////BEGIN FUNCTIONS//////////////////////


string Space::getState(){
	

	if (this->hasGuess == true)
	{return "?";}
	else if (this->hasFlag == true)
	{return "F";}	
	else if(this->isRevealed == false && this->hasMine == true){
	return " ";}
	if (this->isRevealed == true){
	stringstream ss;
	ss << this->mineCount;
	return ss.str();}

	else return " ";
	}//end GetState

string Space::getMineCount(){
	stringstream ss;
	ss << mineCount;
	return ss.str();
}
 

////////////////END FUNCTIONS//////////////////////


