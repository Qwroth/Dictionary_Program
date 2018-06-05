#include <iostream>
#include <string>
#include "ProperNoun.h"

using namespace std;

ProperNoun::ProperNoun() {}

//a Preposition object will always have the word type set to Preposition
ProperNoun::ProperNoun(string wordIn, string defIn) 
	: Noun (wordIn, defIn) {
		type = "pn";
		properNoun = wordIn;
}

string ProperNoun::getWord()
{
	//return first letter of the word capitalized
	string s = properNoun;
	s[0] = toupper(s[0]);
    return s;
}

bool ProperNoun::isProperNoun()
{
	return true;
}

//not allowed in scrabble
int ProperNoun::calculateScrabbleScore()
{
	return 0;
}