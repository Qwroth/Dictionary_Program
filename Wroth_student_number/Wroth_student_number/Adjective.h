#ifndef ADJECTIVE_H
#define ADJECTIVE_H

#include"Word.h"
#include <string>
using namespace std;

//define the adjective class, inherite from word class
class Adjective : public Word {

private:
	string type;
public:
	Adjective();
	Adjective(string wordIn, string defIn);
	bool isAdjective();
	
};

#endif ADJECTIVE_H