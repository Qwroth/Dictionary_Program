#ifndef PREPOSTITION_H
#define PREPOSTITION_H

#include"MiscWord.h"
#include <string>
using namespace std;

//define the preposition class, inherite from miscWord class
class Preposition : public MiscWord {

private:
	string type;
public:
	Preposition();
	Preposition(string wordIn, string defIn);
	bool isPreposition();
	
};

#endif PREPOSTITION_H