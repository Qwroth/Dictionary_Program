// Word.H
#include <iostream>

#ifndef WORD_H
#define WORD_H

using namespace std;

//construct the word class

class Word 
{
private:					
	string word;							// The word in the dictionary file
	string definition;						// The definition of the word
	string type;
public:
	Word();
	Word(string wordIn, string defIn);
	void setWord(string wordIn);				// setter for the word
	void setDefinition(string wordIn);		// setter for the word's definition
	void setType(string in);
	string getWord();							// getter of the word
	string getDefinition();						// getter of the word's definition
	string getType();
	int calculateScrabbleScore();			// calculate and return the scrable score of a word
	virtual bool isNoun();							// returns false unless the word is a noun
	bool isHyphenated();					 // returns true if a word is hyphenated
	bool isPalindrome();					// returns true if a word is a palindrome
	bool isVerb();							// returns false unless a word is false
	bool isMisc();
	bool isProperNoun();
};

#endif