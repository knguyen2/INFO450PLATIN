/*
	github link to project repository: https://github.com/knguyen2/INFO450PLATIN.git

	Author: Kim Nguyen
	Assignment: 04
	Date: Tuesday, November 13, 2018
	Class: INFO 450 - FALL 2018
	Instructor: Michele Kelo

	REQUIREMENT:
		Write a program that will translate English words into Pig Latin
		Rules  for translating English to Pig Latin**:
			If the word starts with a consonant, the first character is removed and added to the end of the word. An “ay” is appended to the end of the word. 
				(E.g.: pig = igpay, latin = atinlay, job = objay, school = choolsay)
			If the word begins with a vowel then the word is simply appended with and “ay”.
				(E.g.: every = everyay, out = outay, apple = appleay)
			If the word has two or less characters, the work remains the same.
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
			Returns 0 if successful  and  -1 if not successful
			(Example – empty string! – nothing to translate OR a word that begins w/ a number – cannot be translated)
		The main program should include a loop that will continue to ask for input and translate words until the user chooses to quit.


	EC: Allow the user to enter a sentence and translate the entire sentence to pig Latin using the above rules.
		The size of the sentence can be up to 500 characters and is guaranteed to be <= 500 characters in total.
		The each word in the translated sentence should be translated following the basic rules defined. Punctuation should be ignored.
		If a “bad” word is entered the function should exit w/ an error and return -1 
		A sentence consists of words separated by spaces


*/

