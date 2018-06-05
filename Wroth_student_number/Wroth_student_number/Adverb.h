#ifndef ADVERB_H
#define ADVERB_H

#include"Word.h"
#include <string>
using namespace std;

//define the adverb class, inherite from word class
class Adverb : public Word {

private:
	string type;
public:
	Adverb();
	Adverb(string wordIn, string defIn);
	bool isAdverb();
	
};

#endif ADVERB_H