#ifndef ART_H
#define ART_H

#include<vector>
#include<string>
using std::vector;
using std::string;
class Art{

public:

Art();

vector<string> introArt();
vector<string> dogeArt();
vector<string> gameOverArt();
vector<string> quitArt();
string errorArt();

};






#endif
