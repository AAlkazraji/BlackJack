//Name: Assignment 2
//Author: Ahmed Al-khazraji
//Student numbers: c3277545
//Student email: c3277545@uon.edu.au
//date:21/10/2020
//Course: seng1120

#ifndef Ahmed_Card
#define Ahmed_Card
#include <cstdlib>
#include <iostream>
#include "Node.h"
using namespace std; 




	class Card
	{
		public:
		
		//constractor
		Card(string nF, int nV, bool f);
		
		// constracor takes 0 arg
		Card();
		
		//desrector
		~Card();
		
		//member function: sets info of the cards 
		//preconditons: there has to be a card
		//postcondition:  card info are set
		void setFace(string f);
		
		//member function: sets value of the cards 
		//preconditons: there has to be a card
		//postcondition:  card value are set 
		void setValue(int v);
		
		//member function: sets how the card will face up or down
		//preconditons: there has to be a card
		//postcondition:  card info are set  
		void setFaceUp(bool x);
		
		//member function: returns card info
		//preconditons: there has to be card
		//postcondition:  info returned 
		string getFace();
		
		//member function: returns card info
		//preconditons: there has to be card
		//postcondition:  info returned  
		int getValue();
		
		//member function: returns card info
		//preconditons: there has to be card
		//postcondition:  info returned  
		bool getFaceUp();


		private:
		string face;
		int value;
		bool faceUp;

	};
	ostream& operator<<(ostream& os, Card& value); 
#endif