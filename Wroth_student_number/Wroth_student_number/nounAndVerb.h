#ifndef NOUNANDVERB_H
#define NOUNANDVERB_H

#include"Verb.h"
#include"Noun.h"
#include <string>
using namespace std;

//define the nounAndVerb class, inherite from noun and verb classes
class NounAndVerb : public Noun, public Verb {

private:
	string type;
public:
	NounAndVerb();
	NounAndVerb(string wordIn, string defIn);
	bool isNoun();
	bool isVerb();
};

#endif NOUNANDVERB_H