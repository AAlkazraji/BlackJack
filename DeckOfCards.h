//Name: Assignment 2
//Author: Ahmed Al-khazraji
//Student numbers: c3277545
//Student email: c3277545@uon.edu.au
//date:21/10/2020
//Course: seng1120

#ifndef Ahmed_DeckOfCards
#define Ahmed_DeckOfCards
#include <cstdlib>
#include <iostream>
#include "Queue.h"
#include "Card.h"
using namespace std; 




	class DeckOfCards
	{
		public:
		 
		//Constructors takes 0 args 
		DeckOfCards();
		
		// Descructors
		~DeckOfCards();
		
		//member function: will call divide fuction and then shuflling the 4 decks
		//preconditons: divide fuction will divide main deck into 4 small decks 
		//postcondition: 4 decks sheflled and merge to 1 deck
		void shuffle();
		
		//member function: this fuction will divide the main deck to 4 smaill decks
		//preconditons: there has to be 1 main deck that will store all the cards 
		//postcondition: main deck divided into 4 decks
		void divide();
		
		//member function: adding cards to the players 
		//preconditons: there has to be 1 maind sheflled deck
		//postcondition: cards added to the players
		Card draw();
		
		//member function: this fuction will take infromation that stored inside decks 
		//preconditons: there has to be 1 maind sheflled deck
		//postcondition: these information will be sent to the << opreator
		string info();

		private:
		
		// 4 small deck to be used when dividing the deck and one main deck to store the cards before and after sheflling
		Queue<Card>* queue1;
		Queue<Card>* queue2;
		Queue<Card>* queue3;
		Queue<Card>* queue4;
		Queue<Card>* makeDeck;

	};
		std::ostream& operator<<(std::ostream& os, DeckOfCards& data); //<< opreator overloading
#endif