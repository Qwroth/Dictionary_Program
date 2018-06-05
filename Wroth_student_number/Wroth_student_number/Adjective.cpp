#include <iostream>
#include <string>
#include "Adjective.h"
using namespace std;

Adjective::Adjective() {}

//an abjective object will always have the word type set to abjective
Adjective::Adjective(string wordIn, string defIn) 
	: Word (wordIn, defIn) {
	type = "adj";
}

bool Adjective::isAdjective()
{
	return true;
}