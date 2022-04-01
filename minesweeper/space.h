#ifndef SPACE_H
#define SPACE_H
#include<string>
#include<sstream>
class Space{


public:
Space();

int row;
int col;
bool hasMine;
bool hasFlag;
bool hasGuess;
bool isRevealed;
int mineCount;

Space * pN;
Space * pNE;
Space * pE;
Space * pSE;
Space * pS;
Space * pSW;
Space * pW;
Space * pNW;

std::string getState();
std::string getMineCount();
};

#endif
