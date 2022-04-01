#include<string>
#include<vector>
#include<iostream>
#include"art.h"

using namespace std;

Art::Art(){
//default constructor

}


vector<string> Art::introArt(){


	vector<string> introArtVector;

	string string1 = "  /\\/\\ (_)_ __   ___  _____      _____  ___ _ __   ___ _ __ ";
	string string2 = " /    \\| | '_ \\ / _ \\/ _ \\ \\ /\\ / / _ \\/ _ \\ '_ \\ / _ \\ '__|";
	string string3 = "/ /\\/\\ \\ | | | |  __/\\__ \\\\ V  V /  __/  __/ |_) |  __/ |   ";
	string string4 = "\\/    \\/_|_| |_|\\___||___/ \\_/\\_/ \\___|\\___| .__/ \\___|_|   ";
	string string5 = "                                 RECURSIVE |_| EDITION      ";

	introArtVector.push_back(string1);
	introArtVector.push_back(string2);
	introArtVector.push_back(string3);
	introArtVector.push_back(string4);
	introArtVector.push_back(string5);	
	return introArtVector;
	}//end introArt

vector<string> Art::gameOverArt(){
vector<string> gameOverVector;
string string1 = "Oh no... You revealed a mine!                     "; 
string string2 = "  __ _  __ _ _ __ ___   ___    _____   _____ _ __ ";
string string3 = " / _` |/ _` | '_ ` _ \\ / _ \\  / _ \\ \\ / / _ \\ '__|";
string string4 = "| (_| | (_| | | | | | |  __/ | (_) \\ V /  __/ |   ";
string string5 = " \\__, |\\__,_|_| |_| |_|\\___|  \\___/ \\_/ \\___|_|   ";
string string6 = " |___/                                            ";  
gameOverVector.push_back(string1);
gameOverVector.push_back(string2);
gameOverVector.push_back(string3);
gameOverVector.push_back(string4);
gameOverVector.push_back(string5);
gameOverVector.push_back(string6);
return gameOverVector;
}

vector<string> Art::quitArt(){
vector<string> quitVector;
string string1 = " ლ(ಠ_ಠლ)";
string string2 = " Y U NO PLAY MORE?";
string string3 = " Bye!";
quitVector.push_back(string1);
quitVector.push_back(string2);
quitVector.push_back(string3);
return quitVector;
}

vector<string> Art::dogeArt(){

vector<string> dogeVector;
string string1 = " ░░░░░░░░░▄░░░░░░░░░░░░░░▄░░░░ \"So Doge\"";
string string2 = " ░░░░░░░░▌▒█░░░░░░░░░░░▄▀▒▌░░░";
string string3 = " ░░░░░░░░▌▒▒█░░░░░░░░▄▀▒▒▒▐░░░ \"Such Score\"";
string string4 = " ░░░░░░░▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐░░░";
string string5 = " ░░░░░▄▄▀▒░▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐░░░\"Much Minesweeping\"";
string string6 = " ░░░▄▀▒▒▒░░░▒▒▒░░░▒▒▒▀██▀▒▌░░░";
string string7 = " ░░▐▒▒▒▄▄▒▒▒▒░░░▒▒▒▒▒▒▒▀▄▒▒▌░░ \"Wow\"";
string string8 = " ░░▌░░▌█▀▒▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐░░";
string string9 = " ░▐░░░▒▒▒▒▒▒▒▒▌██▀▒▒░░░▒▒▒▀▄▌░";
string string10 = " ░▌░▒▄██▄▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▌░";
string string11 = " ▀▒▀▐▄█▄█▌▄░▀▒▒░░░░░░░░░░▒▒▒▐░";
string string12 = " ▐▒▒▐▀▐▀▒░▄▄▒▄▒▒▒▒▒▒░▒░▒░▒▒▒▒▌";
string string13 = " ▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒▒▒░▒░▒░▒▒▐░";
string string14 = " ░▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒░▒░▒░▒░▒▒▒▌░";
string string15 = " ░▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▄▒▒▐░░";
string string16 = " ░░▀▄▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▄▒▒▒▒▌░░";
string string17 = " ░░░░▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀░░░ CONGRATULATIONS!";
string string18 = " ░░░░░░▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀░░░░░ YOU HAVE WON!";
string string19 = " ░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▀▀░░░░░░░░ SCORE: ";
dogeVector.push_back(string1);
dogeVector.push_back(string2);
dogeVector.push_back(string3);
dogeVector.push_back(string4);
dogeVector.push_back(string5);
dogeVector.push_back(string6);
dogeVector.push_back(string7);
dogeVector.push_back(string8);
dogeVector.push_back(string9);
dogeVector.push_back(string10);
dogeVector.push_back(string11);
dogeVector.push_back(string12);
dogeVector.push_back(string13);
dogeVector.push_back(string14);
dogeVector.push_back(string15);
dogeVector.push_back(string16);
dogeVector.push_back(string17);
dogeVector.push_back(string18);
dogeVector.push_back(string19);
return dogeVector;
}

string Art::errorArt(){
string error = "ಠ_ಠ says,";
return error;

}
