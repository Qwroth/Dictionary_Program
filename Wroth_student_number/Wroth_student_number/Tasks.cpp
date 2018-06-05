#include<iostream>
#include"dictionary.h"
#include"Word.h"
#include<string>

using namespace std;
Dictionary myDictionary;

//Tasks of the program
void tasks(int taskIn)
{
	int task = taskIn;
	string word;

	switch (task)
	{
		case 1:
			cout << "Please enter a word to search ";
			cin >> word;
			myDictionary.findWord(word);
		break;

		case 2:
			findZ();
			break;

		case 3:
			findQ(); 
			break;

		case 4:
			 findVerbAndNouns();
			break;

		case 5:
			findPalindrones();
			break;

		case 6:
			highestScrabbleScore();
			break;

		case 7:
			HighestRatioScore();
			break;

		case 8:
			ryhme();
			break;

		case 9:
			anagram();
			break;

		case 10:
			hangMan();
			break;

		default:
			cout << "sorry please enter a number between 1 - 10 " << endl;
}


}