#include <iostream>
#include <string>
#include "Preposition.h"
using namespace std;

Preposition::Preposition() {}

//a Preposition object will always have the word type set to Preposition
Preposition::Preposition(string wordIn, string defIn) 
	: MiscWord (wordIn, defIn) {
	type = "prep";
}

bool Preposition::isPreposition()
{
	return true;
}