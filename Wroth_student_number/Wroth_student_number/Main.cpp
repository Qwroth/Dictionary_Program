#include<iostream>
#include<string>
#include"Word.h"
#include"Noun.h"
#include"Verb.h"
#include"dictionary.h"
#include "Menu.h"
#include<fstream>
#include"Tasks.h"


using namespace std;

int main ()
{
	//load the dictionary file into the program
	Dictionary myDictionary;
	myDictionary.loadDictionary();


	//display menu of tasks
	displayMenu();

	int cont = 1; // continue variable

	//keep using program until user quits
	while(cont !=0)
	{
	int taskNum; // hold task number
	
	//display menu again
	if(cont == 2)
		displayMenu();

	//get the task number
	cout << "Please enter a task number ";
	cin >> taskNum;

	//preform task
	tasks(taskNum);

	//ask user what to do next
	cout << "0 to quit 1 to continue or 2 for menu " << endl;
	cin >> cont;
	
	}
	
	system("pause");
	return 0;
}