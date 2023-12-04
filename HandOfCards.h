//Name: Assignment 2
//Author: Ahmed Al-khazraji
//Student numbers: c3277545
//Student email: c3277545@uon.edu.au
//date:21/10/2020
//Course: seng1120

#ifndef Ahmed_HandOfCards
#define Ahmed_HandOfCards
#include <cstdlib>
#include <iostream>
#include "Queue.h"
#include "DeckOfCards.h"
#include "Card.h"
using namespace std; 




	class HandOfCards
	{
		public:
		//Constructors takes 0 args 
		HandOfCards();
		
		// Descructors
		~HandOfCards();
		
		//member function: this fuction will counts the value of the card that facing up only
		//preconditons: there have to be a card
		//postcondition: returns the value of cards that only facing up
		int count();
		
		//member function: this fuction will counts the value of the card that facing up and down
		//preconditons: there have to be a card
		//postcondition: returns the value of cards that only facing up and down
		int countAll();
		
		//member function: will fuction will returns the card information as string
		//preconditons: there have to be a card
		//postcondition: card info returned as string 
		string value();
		
		//member function: this function turn the card facing down to facing up
		//preconditons: there have to be a card
		//postcondition: all of the cards that facing down will be facing up                not working preperly ):
		void faceUp();
		
		//member function: this function will give add cards to the player hands
		//preconditons: the function need to be called with a mantion of if the card is facing up or down 
		//postcondition: cards will be added to the players hands 
		void add(Card card, bool faceID);
		

		private:
		Queue<Card>* deck;
	};
		std::ostream& operator<<(std::ostream& os, HandOfCards& data);     // << opeator overloding 
#endif