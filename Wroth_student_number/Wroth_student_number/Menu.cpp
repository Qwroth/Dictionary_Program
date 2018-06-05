#include <iostream>
#include "menu.h"

using namespace std;

//display menu method
void displayMenu ()
{
	cout << " *********MENU**********" << endl << "please select a task from below" << endl << endl;
	cout << "_________Basic Tasks___________" << endl << 
		"1: Word Search" << endl <<
		"2: Find Word(s) with more than 3 Z's" << endl <<
		"3: Find Words that dont have a u after q" << endl <<
		"4: List nouns and Verbs" << endl <<
		"5: List palindrones " << endl <<
		"6: List highest scrabble score" << endl <<
		"7: List highest scrabble score ratio to length" << endl << endl <<
		"_________Intermediate Tasks___________" << endl <<
		"8: Ryhme" << endl <<
		"9: Anagram" << endl << endl <<
		"_________Advanced Tasks___________" << endl <<
		"10: Hangman" << endl;
}