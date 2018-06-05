#include <iostream>
#include <string>
#include "MiscWord.h"
using namespace std;

MiscWord::MiscWord() {}

//a MiscWord object will always have the word type set to MiscWord
MiscWord::MiscWord(string wordIn, string defIn) 
	: Word (wordIn, defIn) {
	type = "misc";
}

bool MiscWord::isMisc()
{
	return true;
}

//not allowed in scrabble
int MiscWord::calculateScrabbleScore()
{
	return 0;
}