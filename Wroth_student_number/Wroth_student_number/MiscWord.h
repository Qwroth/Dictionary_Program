#ifndef MISCWORD_H
#define MISCWORD_H

#include"Word.h"
#include <string>
using namespace std;

//define the MiscWord class, inherite from word class
class MiscWord : public Word {

private:
	string type;
public:
	MiscWord();
	MiscWord(string wordIn, string defIn);
	bool isMisc();
	int calculateScrabbleScore();
	
};

#endif MISCWORD_H