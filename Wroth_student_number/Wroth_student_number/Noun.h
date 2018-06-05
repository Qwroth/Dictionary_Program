#ifndef NOUN_H
#define NOUN_H

#include"Word.h"
#include <string>
using namespace std;

//define the noun class, inherite from word class
class Noun : public Word {

private:
	string type;
public:
	Noun();
	Noun(string wordIn, string defIn);
	bool isNoun(); //overide word is noun which returns false
	
};

#endif NOUN_H