#include <iostream>
#include "Word.h" 
#include"Noun.h"
#ifndef DICTIONARY_H
#define DICTIONARY_H

using namespace std;

class Dictionary : public Word {

private:
	Word word;
	Noun noun;

public:
	void loadDictionary();
	void getTotalNumberOfWords();
	void findWord(string wordIn);
	string getDefinition(string wordIn);
};

//tasks to perform
void findZ();
void findQ();
void findVerbAndNouns();
void findPalindrones();
void highestScrabbleScore();
void HighestRatioScore();
void ryhme();
void anagram();
void hangMan();

#endif