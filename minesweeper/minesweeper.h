#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "board.h"
#include "space.h"
#include"art.h"
#include<sstream>
#include<vector>
#include<string>
#include<iostream>
#include<cstdlib>

class Minesweeper{


public:

//default constructor

Minesweeper(int,int, int, vector<int>);
int rows;
int cols;
int nMines;
vector<int> mineLoc;
int score;
int rounds;
bool isWon;

//main menu
void menu(Board &, Space **);
//menu options
void flag(Space **, int, int);
void guess(Space **, int, int);
void quit();
void help();
//print functions
void printMain();
void printQuit();
void printGameOver();
void printDoge(Board & board);
//more utils
int getScore(Board & board);
void revealMines(Space & space);
void checkWin(Board &, Space **);
int  getMineCount(Space & space);
void seedMines(Space **, vector<int> &, int &);
};//end minesweeper class def

#endif
