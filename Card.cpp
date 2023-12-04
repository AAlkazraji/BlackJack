//Name: Assignment 2
//Author: Ahmed Al-khazraji
//Student numbers: c3277545
//Student email: c3277545@uon.edu.au
//date:21/10/2020
//Course: seng1120

#include <cstdlib>
#include <iostream>
using namespace std;
#include "Card.h"

	

		Card::Card(string nF, int nV, bool f)
		{
			face = nF;
			value = nV;
			faceUp = f;
		}
		
		Card::Card()
		{
			face = "";
			value = 0;
		}
		
		Card::~Card()
		{
			face = "";
			value = 0;
			faceUp = false;
		}
		
		void Card::setFace(string f) 
		{
			face = f;
		}
		
		void Card::setValue(int v) 
		{
			value = v;
		}
		
		void Card::setFaceUp(bool x) 
		{
			faceUp = x;
		}
		
		string Card::getFace()
		{
			return face;
		}
		
		int Card::getValue()
		{
			return value;
		}
		
		bool Card::getFaceUp()
		{
			return faceUp;
		}
		ostream& operator<<(ostream& os, Card& value)
		{
			os << value.getValue();
			return os;
		}

	
		
		
		
		