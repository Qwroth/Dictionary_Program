#ifndef VERB_H
#define VERB_H

#include"Word.h"
#include <string>
using namespace std;

//define the verb class, inherite from word class
class Verb : public Word {

private:
	string type;
public:
	Verb();
	Verb(string wordIn, string defIn);
	bool isVerb(); //overide isVerb()
	
};

#endif VERB_H