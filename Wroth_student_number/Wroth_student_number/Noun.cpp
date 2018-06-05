#include <iostream>
#include <string>
#include "Noun.h"
using namespace std;

Noun::Noun() {}

//a noun object will always have the word type set to noun
Noun::Noun(string wordIn, string defIn) 
	: Word (wordIn, defIn) {
	type = "n";
}

//overide the isNoun() return true
bool Noun::isNoun()
{
	return true;
}
