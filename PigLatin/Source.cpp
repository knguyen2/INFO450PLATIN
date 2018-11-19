/*
	github link to project repository: https://github.com/knguyen2/INFO450PLATIN.git

	Author: Kim Nguyen
	Assignment: 04
	Date: Tuesday, November 13, 2018
	Class: INFO 450 - FALL 2018
	Instructor: Michele Kelo

	REQUIREMENT:
		Write a program that will translate English words into Pig Latin
		Rules  for translating English to Pig Latin:
			***If the word starts with a consonant, the first character is removed and added to the end of the word. An “ay” is appended to the end of the word. 
				(E.g.: pig = igpay, latin = atinlay, job = objay, school = choolsay)
			***If the word begins with a vowel then the word is simply appended with and “ay”.
				(E.g.: every = everyay, out = outay, apple = appleay)
			***If the word has two or less characters, the word remains the same.
				(E.g.: of = of, to = to)
			If the word is an article (e.g. the, a, an) OR a conjunction: 
				(I.g.: and, but, for, nor, so, yet, or), the word remains the same.
				(E.g.: and = and, but = but)
			Any word that starts with a number should not be translated and user provided with an error message.
		The user should be allowed to continue to enter words for translation until they opt to quit the program.
		For each word provided, the translated Pig Latin is displayed to the console.

		The translator program will only translate words that are 50 characters or less, and the user’s input is guaranteed to be 50 characters or less.
		The program should use C-string to store and process the word.
		The program should include a function: translateToPigLatin that performs the following:
			Translates the word that is passed as a parameter to the function into Pig Latin.
			Displays the translated word to the console
			//Returns 0 if successful  and  -1 if not successful
			(Example – empty string! – nothing to translate OR a word that begins w/ a number – cannot be translated)
		The main program should include a loop that will continue to ask for input and translate words until the user chooses to quit.


	EC: Allow the user to enter a sentence and translate the entire sentence to pig Latin using the above rules.
		The size of the sentence can be up to 500 characters and is guaranteed to be <= 500 characters in total.
		The each word in the translated sentence should be translated following the basic rules defined. Punctuation should be ignored.
		If a “bad” word is entered the function should exit w/ an error and return -1 
		A sentence consists of words separated by spaces


*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


//Declare a constant variable for maximum number of (50) characters in a C-String 
const int MAXCHAR = 50;


//Function Declaration
int translateToPigLatin(char fromEng[MAXCHAR], char toPLatin[MAXCHAR]);
bool isVowel(char vowel);
bool isConjunction(char fromEng[MAXCHAR]);

// translateToPigLatin function for translating from English word to PigLatin and return a value
int translateToPigLatin(char fromEng[MAXCHAR], char toPLatin[MAXCHAR])
{
	//Condition to return -1 (unsucessful) for empty string and a word that begins with a number 
	if (fromEng[0] == '\0' || 
		fromEng[0] == '0' || fromEng[0] == '1' || 
		fromEng[0] == '2' || fromEng[0] == '3' || 
		fromEng[0] == '4' || fromEng[0] == '5' || 
		fromEng[0] == '6' || fromEng[0] == '7' || 
		fromEng[0] == '8' || fromEng[0] == '9')
	{
		return -1;
	}

	//Condition to check if the word begins with a vowel, then appended an “ay” at the end.
	else if (isVowel(fromEng[0]))
	{
		strcat(toPLatin, fromEng);
		strcat(toPLatin, "ay");
	}

	//Condition to check if a word is <= 2 characters and keep it as it was
	else if (fromEng[2] == '\0')
	{
		strcpy(toPLatin, fromEng);
	}

	//Condition to check if the word is an article (e.g. the, a, an) OR a conjunction then keep it as it was
	else if (isConjunction(fromEng) == true)
	{
		strcpy(toPLatin, fromEng);
	}

	//If the word starts with a consonant, the first character is removed and added to the end of the word. An “ay” is appended to the end of the word. 
	else
	{
		int first;
		int last = strlen(fromEng) - 1;
		for (first = 1; first <= last; first++)
		{
			toPLatin[first - 1] = fromEng[first];
		}
		toPLatin[strlen(fromEng) - 1] = fromEng[0];
		strcat(toPLatin, "ay");
	}
	return 0;

}

//Function to check through several cases that represent vowels and returns true if the first character is a vowel, otherwise returns false if consonant
bool isVowel(char vowel)
{
	return (vowel == 'A' || vowel == 'a' ||
			vowel == 'E' || vowel == 'e' ||
			vowel == 'I' || vowel == 'i' ||
			vowel == 'O' || vowel == 'o' ||
			vowel == 'U' || vowel == 'u');
}

// Function to check article (e.g. the, a, an) OR conjunction (i.g.: and, but, for, nor, so, yet, or ) and return true or false 
bool isConjunction(char fromEng[MAXCHAR])
{
	bool conjunction;

	fromEng[MAXCHAR] = tolower(fromEng[MAXCHAR]);

	if (fromEng == "The" || fromEng == "the" || 
		fromEng == "A"	 || fromEng == "a"   || 
		fromEng == "An"  ||	fromEng == "an"  || 
		fromEng == "And" || fromEng == "and" || 
		fromEng == "But" || fromEng == "but" || 
		fromEng == "For" || fromEng == "for" || 
		fromEng == "Nor" || fromEng == "nor" || 
		fromEng == "So"  || fromEng == "so"  || 
		fromEng == "Yet" || fromEng == "yet" || 
		fromEng == "Or"  || fromEng == "or")
	{
		conjunction = true;
	}
	else
	{
		conjunction = false;
	}
	return conjunction;
}

int main() 
{

	//do-while loop that will continue to ask for input and translate words until the user chooses to quit.
	char answer = 'N';

	do
	{
		char fromEng[MAXCHAR] = "";
		char toPLatin[MAXCHAR] = "";

		cout << "\n Enter a word/phrase (in English) -->  ";
		cin.getline(fromEng, MAXCHAR);

		//translating user input from English to Pig Latin and allow user to enter another word/phrase
		if (translateToPigLatin(fromEng, toPLatin) == 0)
		{
			cout << "\n\t\t\t " << fromEng << " \n\n\t\t\t --> translates to..." << toPLatin << endl;
			cout << "\n Do you want to enter another word? Enter Y to continue, or N to quit -->  ";
			cin >> answer;
			cout << endl;
		}
		else
		{
			cout << "\n Empty string! Nothing to translate. \n\n OR a word that begins with a number can't be translated. \n\n Enter Y to continue, or N to quit...";
			cin >> answer;
		}
		
		//Clear the input buffer before asking for another word
		cin.ignore(MAXCHAR, '\n');
		cin.clear();

	} while (answer == 'Y' || answer == 'y');

	cout << endl;
	system("pause");
	return 0;
}