#include <iostream>
#include <string>
#include "nounAndVerb.h"

using namespace std;

NounAndVerb::NounAndVerb() {}

//a NounAndVerb object will always have the word type set to NounAndVerb

NounAndVerb::NounAndVerb(string wordIn, string defIn)
	: Noun ( wordIn,  defIn), Verb (wordIn, defIn)  {
		type = "n_and_v";
}

 bool NounAndVerb::isNoun()
{
	return true;
}

 bool NounAndVerb::isVerb()
 {
	 return true;
 }