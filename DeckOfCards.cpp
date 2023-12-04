//Name: Assignment 2
//Author: Ahmed Al-khazraji
//Student numbers: c3277545
//Student email: c3277545@uon.edu.au
//date:21/10/2020
//Course: seng1120

#include <cstdlib>
#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include "Queue.h"
#include "Card.h"
#include "DeckOfCards.h"
using namespace std; 

	// consteractor will make crads info and stor them 
	DeckOfCards::DeckOfCards()
    {
		// string verabulss to store the informations of the cards
        string cardnumber [13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}; 
		string cardtype [4] = {"S", "H", "C", "D"};	
		// instantion the queues to be used in this class
		makeDeck = new Queue<Card>();
		queue1 = new Queue<Card>();
		queue2 = new Queue<Card>();
		queue3 = new Queue<Card>();
		queue4 = new Queue<Card>();
		Card* card = new Card();
		makeDeck = new Queue<Card>();
		// for loops will loop therogh to stor the informations of the card
        for (int i = 0; i < 4 ; i ++)
        {
            for (int j = 0; j < 13; j ++)
            {
				// setting the card values and the type of the card
				card->setFace(cardnumber[j] + "-" + cardtype[i]);
				card->setValue(j+1);
				if (cardnumber[j] == "J" || cardnumber[j] == "Q" || cardnumber[j] == "K")
				{card->setValue(10);}
				else if (cardnumber[j] == "A")
				{card->setValue(11);}
				card->setFaceUp(false);
				makeDeck->enqueue(*card);
            }
        }
        delete card;  
    }
	
	// Descructors
	DeckOfCards::~DeckOfCards()
	{
		queue1->~Queue();
		queue2->~Queue();
		queue3->~Queue();
		queue4->~Queue();
		makeDeck->~Queue();
	}
	
	void DeckOfCards::divide()
	{
		// after creating the cards in the consterctor and the card info
		// this for loop will keep looping till the end of the deck 
		// dividing the mani deck into 4 small decks by enqueuing the first item of the deck to the small deck and dequeue the item from the mai deck
		for (int k = 0; k < makeDeck->size(); k++)
		{
			if (k < 13)
			{
				queue1->enqueue(makeDeck->front());
				makeDeck->dequeue();
			}
			
			if (k < 26 && k > 13)
			{
				queue2->enqueue(makeDeck->front());
				makeDeck->dequeue();
			}
			
			if (k < 39 && k > 26)
			{
				queue3->enqueue(makeDeck->front());
				makeDeck->dequeue();
			}
			
			if (k < 52 && k > 39)
			{
				queue4->enqueue(makeDeck->front());
				makeDeck->dequeue();
			}
		}
		
	}
	
	void DeckOfCards::shuffle()
	{
		// 2 varbuls to stor the 2 randomlly chessen numbers and based on these numbers the sheflle fuction will choose the small queue to deque from and to 
		int x = 0;
		int Y = 0;
		
		Card temp;
		srand (time(NULL));
		
		// for loop will loops 1000 times to sheflle the 4 queues
		for (int e = 0; e < 1000; e++)
		{
			divide();
			x = rand() % 4 + 1;
			if(x == 1 && !(queue1->isEmpty()))
			{
				temp = queue1->front();
				queue1->dequeue();
			}
			if(x == 2 && !(queue2->isEmpty()))
			{
				temp = queue2->front();
				queue2->dequeue();
			}
			if(x == 3 && !(queue3->isEmpty()))
			{
				temp = queue3->front();
				queue3->dequeue();
			}
			if(x == 4 && !(queue4->isEmpty()))
			{
				temp = queue4->front();
				queue4->dequeue();
			}
			
			
			Y = rand() % 4 + 1;
			if(Y == 1)
			{
				queue1->enqueue(temp);
			}
			if(Y == 2)
			{
				queue2->enqueue(temp);
			}
			if(Y == 3)
			{
				queue3->enqueue(temp);
			}
			if(Y == 4)
			{
				queue4->enqueue(temp);
			}
			
			
			// while loop will loop to merage the 4 queues into 1 main queue by checking the if the small decks is empty then will enters the other if stsments 
			// to dequeeue and enqueue to the sheflled queue
			while(makeDeck->size() < 52)
			{
				if(!queue1->isEmpty())
				{
					makeDeck->enqueue(queue1->front());
					queue1->dequeue();
				}
				if (!queue2->isEmpty())
				{
					makeDeck->enqueue(queue2->front());
					queue2->dequeue();
				}
				if (!queue3->isEmpty())
				{
					makeDeck->enqueue(queue3->front());
					queue3->dequeue();
				}
				if (!queue4->isEmpty())
				{
					makeDeck->enqueue(queue4->front());
					queue4->dequeue();
				}
			}
		
		}
	}
	
	Card DeckOfCards::draw()
	{
		// the drow function will return the first item int the queue and then deque it
		Card temp = makeDeck->front();
		makeDeck->dequeue();
		return temp;
		
	}
	    
	std::ostream& operator<<(std::ostream& os, DeckOfCards& data) // << opertor overloding will return function info() which has the card info
    { 
        os << data.info() << endl; 
        return os;            
    }
	
	string DeckOfCards::info()   // info() will rturn a string containg the info of cards 
	{	
		string g =" ";
		for (int e=0; e<52; e++)
		{
			g += makeDeck->front().getFace() + " ";
			makeDeck->enqueue(makeDeck->front());
			makeDeck->dequeue();
		}
		return g;
	}
	
	
	
	

	
	


	
	
	
	
	
	
	
	
	
