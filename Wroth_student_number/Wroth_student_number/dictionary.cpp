#include "Word.h"
#include "dictionary.h"
#include <iostream>
#include<string>
#include<fstream>
#include <algorithm>
#include<time.h>
#include <stdlib.h>  
#include <stdio.h>  
using namespace std;

//create a global dictionary array
static const int MAX_WORDS = 110000;
Word myDictionary[MAX_WORDS];

//create a constant for the number of words in the dictionary file
static const int TOTAL_WORDS = 106184; 
//initialize a word counter
int totalWords = 0;

void Dictionary::loadDictionary()
{
	//load the dictionary file
	cout << "loading dictionary please wait" << endl;
	ifstream dictionaryFile;
	dictionaryFile.open("dictionary.txt");
	string line;
	int i = 0;
	
	//sort the file into the word array
	if (dictionaryFile.is_open()) 
	{
		for (i; i < TOTAL_WORDS; i++)
		{
			getline(dictionaryFile, line); //get the word 
			word.setWord(line);

			getline(dictionaryFile, line); //get the definition
			word.setDefinition(line);

			getline(dictionaryFile, line); //get the word type
			word.setType(line);

			// get the next line (space) and do nothing with it
			getline(dictionaryFile, line);
			
			//store word object into the array
			myDictionary[i] = word;

			// count the total number of words while the dictionary is being sorted in the array
			totalWords++;			
		}
		dictionaryFile.close();
		cout << "dictionary loaded succesfully" << endl;		
	}
}

//display total number of words
void Dictionary::getTotalNumberOfWords()
{
	//print out the number of words defined in the load dictionary method
 cout << "Total number of words: " << totalWords << endl;
}

//find word method
void Dictionary::findWord(string wordIn)
{
	//get the word to search
	string search;
	search = wordIn;
	
	//binary search left and right values of the array
	int left = 0, right = 108164;
	int mid = (left + right) / 2;

	//start binary search
	while(myDictionary[mid].getWord() != search)
	{
		mid = ( left + right) /2;
		
		if (myDictionary[mid].getWord() == search)
		{
			cout << myDictionary[mid].getWord() << endl;
	        cout << myDictionary[mid].getDefinition() << endl;
	        cout << "scrabble score : " << myDictionary[mid].calculateScrabbleScore() << endl;
			break;
		}
		else if (search > myDictionary[mid].getWord())
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
}
//Task section

// Task: find the words with more than 3 z's in it
void findZ()
{
	bool wordsFound = false;			// variable to check wether word(s) were found (there is only one word in the dictionary file that has more that 3 z's, razzamatazz)
	cout << "Word(s) with more than 3 z's in it " << endl;
	for (int i = 0; i < TOTAL_WORDS; i++)			// search through the dictionary array
	{
		int zCount = 0;							// reset the z count to 0 when inspecting a new word

		for (char& c: myDictionary[i].getWord())	// inspect the words for any z characters
		{
			if (c == 'z')
			{
				zCount++;					// z counter + 1 if true
			}
		}
		if (zCount > 3)					// print out the words that had more than 3 z's
			{
				cout << myDictionary[i].getWord() << endl;
				wordsFound = true;
			}
	 }
	if (wordsFound == false)				// outside of loop, if no words were found display message
	{
		cout << "sorry, there are now words with more than 3 z's in the dictionary " << endl;
	}
}

// Task: find word(s) with q without a u
void findQ()
{
	int wordsFound = 0; // count the number of words that have a q without a u

	for (int i = 0; i < TOTAL_WORDS; i++) // go through the word array
	{
		bool hasQ = false; // check if the word has a q
		char letter[50];  // store the characters in an array
		int position = 0; // will hold the position of the letter q
		int upos;  // will check to see if the letter after the q is a u

			for (char& c: myDictionary[i].getWord())  // go through each letter in a word
			{
				letter[position] = c; // store the letter along with its postion in the word
				
				if (c == 'q') // if the word has a q in it
				{
				hasQ = true;		// mark the word as a q holder
				upos = position + 1;  // gets the position of the u (
				}
				
				position++;  // move onto the next letter of the word
			}

		if (hasQ == true && letter[upos] != 'u')     // if the word has a q in it and does not have a u in the position after the q, print the word
		{
		cout << myDictionary[i].getWord() << endl;
		wordsFound++;
		}
	}
	if (wordsFound < 0)  // there are about 8 words that will be found, incase a different dictionary file is loaded, display error message
		cout << "Sorry, there are no words without a u after a q in the dictionary " << endl;
	else
		cout << "Number of words found " << wordsFound << endl;

}

// find verbs and nouns
void findVerbAndNouns()
{

	for (int i = 0; i < TOTAL_WORDS; i++)
	{
		if(myDictionary[i].isNoun() == true && myDictionary[i].isVerb() == true )
		cout << myDictionary[i].getWord() << endl;
	}
}

//find the highest scrabble score
void highestScrabbleScore()
{
	int highScore = 0; //start the highest score
	int position;  // hold the position of the word

	//search through dictionary
	for (int i =0; i< TOTAL_WORDS; i++)
	{
		//if the next score is higher than a previous score set it to the new highscore and record the position in the array
		if (myDictionary[i].calculateScrabbleScore() > highScore)
		{
			highScore = myDictionary[i].calculateScrabbleScore();
		position = i;
		}
	}
	//print out the highest score
	cout << "The high score is " << highScore << endl <<  myDictionary[position].getWord() << endl;
}

//find palindrones
void findPalindrones()
{
	//search through dictionary array
	for (int i =0; i < TOTAL_WORDS; i++)
	{
		//if the isPalindrone method outputs true print out word
		if(myDictionary[i].isPalindrome() == true && myDictionary[i].getWord().length() > 2)
			cout << myDictionary[i].getWord() << endl;
	}

}

//find highest scrabble score ratio
void HighestRatioScore()
{
	double highScore = 0; // hold the first score to be beaten
	int position; // position of the word in the array
	int size; // size of the word
	string currentWord;  //the current word being scored
	int currentScore; // the current highscore
	double ratio; //the ratio score of the word
	
	//go through the dictionary array
	for (int i =0; i< TOTAL_WORDS; i++)
	{
		currentWord = myDictionary[i].getWord(); //get the word
		size = currentWord.size(); // get the size of the word
		currentScore = myDictionary[i].calculateScrabbleScore(); //get the scrabble score

		//cannot divide by 0 if the score is 0
		if(size != 0)
		{
			ratio = currentScore / size; // divide score by the size of the word
		}

		//if the score is beaten record as new highscore
		if (ratio > highScore)
		{
			highScore = ratio;
		    position = i;
		}
	}
		//print out highscore
		cout << "The high score is " << highScore << endl <<  myDictionary[position].getWord() << endl;

}

//find words that rhyme with chosen word
void ryhme()
{
	string searchWord;   //variable to hold the search word
	string lastThreeLetters;  //variable to hold the last 3 letters of the search word
	string dictionaryWord;    //variable to hold the current word in the dictionary
	string lastLetters;   //variable to hold the last 3 letters of the dictionary word

	//ask the user for a word to search and store it in the search word variable
	cout << "Please enter a word to search ";
	cin >> searchWord;

	//get the value of the last 3 letters of the search word
	lastThreeLetters = searchWord.substr(searchWord.size() - 3);
	
	//go through the dictionary
	for (int i =0; i< TOTAL_WORDS; i++)
	{
		if(myDictionary[i].getWord().length() > 3)
		{
			dictionaryWord = myDictionary[i].getWord();
			lastLetters = dictionaryWord.substr(dictionaryWord.size() -3);

			//if the word ryhmes with the search word print it out
			if(lastLetters == lastThreeLetters)
			cout << myDictionary[i].getWord() << endl;
		}
	}
}

//anagram method
void anagram()
{
	string searchWord;  //variable to hold the search word
	string dictionaryWord;  //variable to hold the dictionary word

	//ask user for a word and store it
	cout << "Please enter a word to search ";
	cin >> searchWord;

	//sort the characters of the word in ascending order
	sort(searchWord.begin(), searchWord.end());
	
	//go through the dictionary
	for (int i =0; i< TOTAL_WORDS; i++)
	{
		//sort the current word in the dictionary
		dictionaryWord = myDictionary[i].getWord();
		sort(dictionaryWord.begin(), dictionaryWord.end());
		
		//if it matches, print out the word
		if(dictionaryWord == searchWord)
				cout << myDictionary[i].getWord() << endl;
	}
}

void hangMan()
{
	//generate seed
	srand(time(NULL));

	//generates a random number
	int randomIndex = rand() % 106185; //0 - 106184
	
	//select a random word from the dictionary
	string randomWord;
	randomWord = myDictionary[randomIndex].getWord();

	//get the length of the word
	int numOfLetters;
	numOfLetters = randomWord.length();

	//hold the number of guesses the user is allowed to make
	int guessesLeft = 6;

	//hold the correct guesses
	int correctGuesses = 0;

	//sort the word into an array
	char array[30]; //size of 30
	int index = 0;

	//store word into the array
	for(char& c: randomWord)
	{
		array[index] = c;
		index++;
	}

	char letter; //variable to hold a character a user has entered
	char word[30]; // an undiscovered array of the word
	int indexx = 0; //index for this particular array

	//go through the array to discover hyphens and print out undiscovered letters 
	for(int x =0; x < numOfLetters; x++)
		if(array[x] == '-')
		{
			word[x] = '-';
			correctGuesses++; // the hyphen counts as a letter in the word
		}
		else
		word[x] = '*';

	//print out the word (undiscovered form)
	for(int i = 0; i < numOfLetters; i++)
		cout << word[i];
	cout << endl;

	//start the game
	while(guessesLeft != 0)
	{
		//ask the user for a letter
		cout << "Please enter a letter ";
		cin >> letter;
		int lettersFound =0;

		indexx = 0;

		//check to see if the word has the letter
		for(char& c: randomWord)
		{
			if(c == letter)
			{
				word[indexx] = letter;
				correctGuesses++;
				lettersFound++;
			}
			indexx++;
		}

		//print out the discovered and undiscovered letters of the word
		for(int a = 0; a < numOfLetters; a++) // print only to the number of letters to avoid printing out null values
			cout << word[a];
		cout << endl;

		//if found undiscovered letters in the guess
		if(lettersFound > 0)
			cout << "Correct " << endl;
		else
		{
			cout << "Sorry, incorrect ";
			guessesLeft--;
			cout << guessesLeft << " reamaining " << endl;
		}

		//if the user has guessed all the letters, tell them they won
		if(correctGuesses == numOfLetters)
		{
			cout << "You win, word was " << randomWord << endl << myDictionary[randomIndex].getDefinition() << endl;
			break; // exit the loop
		}
	}
	
	//tell the user they have lost
	if(guessesLeft == 0)
		cout << "you lose, word was "<< myDictionary[randomIndex].getWord() << endl;
}