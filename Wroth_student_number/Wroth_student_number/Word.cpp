//word.ccp
#include "Word.h"
#include <iostream>
#include <string>
using namespace std;

Word::Word() {}

Word::Word(string wordIn, string defIn)
{
	word = wordIn;
	definition = defIn;
}

// create setword method
void Word::setWord(string wordIn)
{
	word = wordIn;					// set the string passed into the method as the word 
}

// create getword method
string Word:: getWord()
{
	return word;					// returns the word that was set by the setter setWord()
}

//set word type
void Word::setType(string wordIn)
{
	type = wordIn;
}

//get word type
string Word::getType()
{
	return type;
}

//is noun
 bool Word::isNoun()
{
	if (type == "n" ||  type =="n_and_v")
		return true;

	else
	
	return false;
}

 //is hyphenated
bool Word::isHyphenated()
{
	int hyphenCount = 0;
	for (char& c: word)
	{
		if (c == '-')
			hyphenCount++;
	}

	if (hyphenCount > 0)
		return true;
	else
		return false;
	
}

//is verb
bool Word::isVerb()
{
	if (type == "v" ||  type =="n_and_v")
		return true;

	else
	
	return false;
}

//is palindrome
bool Word::isPalindrome()
{
	
	if (word == string(word.rbegin(), word.rend())) 
	return true;
	else
	return false;
}

// is misc word
bool Word::isMisc()
{
	if (type == "misc")
		return true;
	else
	return false;
}

//is propernoun
bool Word::isProperNoun()
{
	if (type == "pn")
		return true;
	else
	return false;
}

//calculate the scrabble score
int Word::calculateScrabbleScore()
{
	int scrabbleScore = 0;

	//words not allowed in scrabble
	if (isHyphenated() == true || isMisc() == true || isProperNoun() == true)
	{
		scrabbleScore = 0;
	}

	else

	{
		// go through the word, letter by letter
	for (char& c: word)
	{
		if (c == 'a')
		{
			scrabbleScore = scrabbleScore + 1;
		}
		
		if (c == 'b')
		{
			scrabbleScore = scrabbleScore + 3;
		}
		
		if (c == 'c')
		{
			scrabbleScore = scrabbleScore + 3;
		}
		
		if (c == 'd')
		{
			scrabbleScore = scrabbleScore + 2;
		}

		if (c == 'e')
		{
			scrabbleScore = scrabbleScore + 1;
		}

		if (c == 'f')
		{
			scrabbleScore = scrabbleScore + 4;
		}

		if (c == 'g')
		{
			scrabbleScore = scrabbleScore + 2;
		}

		if (c == 'h')
		{
			scrabbleScore = scrabbleScore + 4;
		}
		
		if (c == 'i')
		{
			scrabbleScore = scrabbleScore + 1;
		}

		if (c == 'j')
		{
			scrabbleScore = scrabbleScore + 8;
		}
		
		if (c == 'k')
		{
			scrabbleScore = scrabbleScore + 5;
		}

		if (c == 'l')
		{
			scrabbleScore = scrabbleScore + 1;
		}

		if (c == 'm')
		{
			scrabbleScore = scrabbleScore + 3;
		}

		if (c == 'n')
		{
			scrabbleScore = scrabbleScore + 1;
		}

		if (c == '0')
		{
			scrabbleScore = scrabbleScore + 1;
		}
		if (c == 'p')
		{
			scrabbleScore = scrabbleScore + 3;
		}

		if (c == 'q')
		{
			scrabbleScore = scrabbleScore + 10;
		}
		if (c == 'r')
		{
			scrabbleScore = scrabbleScore + 1;
		}

		if (c == 's')
		{
			scrabbleScore = scrabbleScore + 1;
		}
		if (c == 't')
		{
			scrabbleScore = scrabbleScore + 1;
		}
		if (c == 'u')
		{
			scrabbleScore = scrabbleScore + 1;
		}
		if (c == 'v')
		{
			scrabbleScore = scrabbleScore + 4;
		}
		if (c == 'w')
		{
			scrabbleScore = scrabbleScore + 4;
		}

		if (c == 'x')
		{
			scrabbleScore = scrabbleScore + 8;
		}

		if (c == 'y')
		{
			scrabbleScore = scrabbleScore + 4;
		}
		if (c == 'z')
		{
			scrabbleScore = scrabbleScore + 10;
		}

	}

	}
	
	return scrabbleScore;
}

//set the definition of the word
void Word::setDefinition(string wordIn)
{
	definition = wordIn;
}

//get the definition of a word
string Word::getDefinition()
{
	return definition;
}