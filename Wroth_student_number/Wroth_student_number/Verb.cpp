#include <iostream>
#include <string>
#include "Verb.h"
using namespace std;

Verb::Verb() {}

//a verb object will always have the word type set to verb
Verb::Verb(string wordIn, string defIn) 
	: Word (wordIn, defIn) {
	type = "v";
}

bool Verb::isVerb()
{
	return true;
}