#include <iostream>
#include <string>
#include "Adverb.h"
using namespace std;

Adverb::Adverb() {}

//an abverb object will always have the word type set to adverb
Adverb::Adverb(string wordIn, string defIn) 
	: Word (wordIn, defIn) {
	type = "adv";
}

bool Adverb::isAdverb()
{
	return true;
}