#ifndef BOARD_H
#define BOARD_H

#include "space.h"

#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Board{
public:

int rows;
int cols;



Board(int, int);
void checkBounds(int,int);
void updateBoardState(int &, Space **);
void initPointers(Space **, int &, int &);
Space ** initSpaces(int, int);
Space ** initPositions(Space **);
};//end Board class
#endif
