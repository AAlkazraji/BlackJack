//Name: Assignment 2
//Author: Ahmed Al-khazraji
//Student numbers: c3277545
//Student email: c3277545@uon.edu.au
//date:21/10/2020
//Course: seng1120

#include <cstdlib>
#include <iostream>
#include<string>
#include "Queue.h"
#include "HandOfCards.h"
#include "Card.h"
using namespace std; 


		HandOfCards::HandOfCards()
		{
			deck = new Queue<Card>();
		}
		
		HandOfCards::~HandOfCards()
		{
			delete deck;
		}
		
		int HandOfCards::count()
		{
			int length = deck->size();
			int total = 0;
			for (int i = 0; i < length; i++)
			{
				if (deck->front().getFaceUp())
				{	
					total += deck->front().getValue();
					
				}
				deck->enqueue(deck->front());
				deck->dequeue();
			}

			return total;
		}
		
		int HandOfCards::countAll()
		{
			int newTotal = 0;
			int newLength = deck->size();
			
			for (int m = 0; m < newLength; m++)
				{
					newTotal += deck->front().getValue();
					deck->enqueue(deck->front());
					deck->dequeue();
				}
			
			return newTotal;
			
		}
		
		string HandOfCards::value()
		{
			string cardInfo = " ";
			for (int j = 0; j < deck->size(); j++)
			{
				if (deck->front().getFaceUp() == true)
				{
					cardInfo += deck->front().getFace() + " ";
				}
				else 
				{cardInfo += "?-? ";}
				deck->enqueue(deck->front());
				deck->dequeue();
			}
				return cardInfo;
		}
		
		void HandOfCards::faceUp()
		{ 
			bool x = true;
			for (int q = 0; q < deck->size(); q++)
			{
				deck->front().setFaceUp(x);
				deck->enqueue(deck->front());
				deck->dequeue();
			}			
		}
		
		void HandOfCards::add(Card card, bool faceID)
		{
			card.setFaceUp(faceID);
			deck->enqueue(card);	
		}
		
		std::ostream& operator<<(std::ostream& os, HandOfCards& data)
		{
			os << data.value(); 
			os << "(" ;
			os <<data.count();
			os << ")" << endl;
			return os;  
		}
		
		
