#ifndef PROPERNOUN_H
#define PROPERNOUN_H

#include"Noun.h"
#include <string>
using namespace std;

//define the propernoun class, inherite from noun class
class ProperNoun : public Noun {

private:
	string type;
	string properNoun;
public:
	ProperNoun();
	ProperNoun(string wordIn, string defIn);
	string getWord();
	bool isProperNoun();
	int calculateScrabbleScore();
};

#endif PROPERNOUN_H