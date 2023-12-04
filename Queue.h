//Name: Assignment 2
//Author: Ahmed Al-khazraji
//Student numbers: c3277545
//Student email: c3277545@uon.edu.au
//date:21/10/2020
//Course: seng1120

#ifndef Ahmed_Queue
#define Ahmed_Queue
#include <cstdlib>
#include <iostream>
using namespace std;
#include "LinkedList.h"
template <typename T>  




	class Queue
	{
		public:
			
			//Constructors
			Queue();
			
			// Descructors 
			~Queue();
			
			//member function: adding to the queue
			//preconditons: there has to be linkedlist
			//postcondition: item added to the queue
			void enqueue(const T& start);
			
			//member function: removing from the queue
			//preconditons: there has to be linkedlist
			//postcondition: item removed from the queue
			void dequeue();
			
			//member function: checks if the queue is empty
			//preconditons: there has to be queue
			//postcondition: returns true if the queue is empty
			bool isEmpty();
			
			//member function: checks the size of the queue
			//preconditons: there has to be queue
			//postcondition: returns an intger of the size of the queue
			int size();
			
			//member function: return the first item in the queue
			//preconditons: there has to be queue
			//postcondition: 
			T front();
			
			//member function: return the last item in the queue
			//preconditons: there has to be queue
			//postcondition:
			T back();

		private:
			LinkedList<T>* list;       // doublly linkedlist to bulid the queue with
			int uesd;					// intger to store the size of the queue
	};
	
	// temblates
	template <typename T>
	Queue<T>::Queue()
	{
		list = new LinkedList<T>();		
		uesd = 0;
	}
	
	// temblates
	template <typename T>
	Queue<T>::~Queue()
	{
			list->~LinkedList();  
			delete list;
			uesd = 0;
	}
	
	// temblates
	template <typename T>
	void Queue<T>::enqueue(const T& start)
	{
		list->addHead(start);               // using the addhead function to add to the queue
		uesd++;
	}
	
	// temblates
	template <typename T>
	void Queue<T>::dequeue()
	{
		list->removeTail();                   // using the removetail function to remove from the queue
		uesd--;
	}
	
	// temblates
	template <typename T>
	bool Queue<T>::isEmpty() 
	{
		if (uesd == 0)
		{
			return true;
		}
		else 
		{return false;}
	}
	
	// temblates
	template <typename T>
	int Queue<T>::size() 
	{
		return uesd;
	}
	
	// temblates
	template <typename T>
	T Queue<T>::front()
	{
		return list->getTailData();  			// using the gettaildata function that i created in linkedlist to return the data in side the nodes
	}
	
	// temblates
	template <typename T>
	T Queue<T>::back()
	{
		return list->getHeadData();
	}
	
	
	
	
	
// 
//
//
//
//
//
//
//
//
//
#endif