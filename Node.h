//Name: Assignment 2
//Author: Ahmed Al-khazraji
//Student numbers: c3277545
//Student email: c3277545@uon.edu.au
//date:21/10/2020
//Course: seng1120


#ifndef Ahmed_Node
#define Ahmed_Node
#include <cstdlib>
#include "Card.h"
#include <iostream>
using namespace std;
template <typename T>
  
  
	class Node

	{
		public:
		// Constructors
		Node (const T dataIn, Node *NextIn, Node *PrevIn);
		
		// Constructors
		Node (const T dataIn);
		
		//Descructors
		~Node();
		
		//member function: a pointer to the next node 
		//preconditons: valid data 
		//postcondition: data set to the next node
		void setNext(const Node* n);
		
		//member function: a pointer to the prevuse pointer
		//preconditons: valid data 
		//postcondition: data set to the prevuse node
		void setPrev(const Node* p);
		
		//member function: a fuction to set data
		//preconditons: valid data 
		//postcondition: data stored 
		void setData (const T& d);
		
		//member function: returning next pointer
		//preconditons: valid data 
		//postcondition: pointer sent to the next node
		Node* getNext();
		
		//member function: returning prevuse pointer
		//preconditons: valid data 
		//postcondition: pointer sent to the prevuse node
		Node* getPrev();
		
		//member function: returning next pointer
		//preconditons: valid data 
		//postcondition: pointer sent to the next node
		T getData();

		private:
		T data;
		Node* next;
		Node* prev;			
		
	
	};
	
		// Constructors
	template <typename T>
	Node<T>::Node (const T dataIn, Node *NextIn, Node *PrevIn)
	{
		data = dataIn;
		next = NextIn;
		prev = PrevIn;	
    }
	
		// Constructors
	template <typename T>
	Node<T>::Node (const T dataIn)
	{
		data = dataIn;
		next = NULL;
		prev = NULL;	
	}
	
	//Descructors
	template <typename T>
	Node<T>::~Node()
    {
		//sets next to null
		next = NULL;
		//sets next to null
		prev = NULL;
	}
	
	// templates 
	template <typename T>
	void Node<T>::setNext(const Node* nextNode)
    {
		//sets next node
		next = (Node*) nextNode;
	}
	
	// templates 
	template <typename T>
	void Node<T>::setPrev(const Node* prevNode)
    {
		//sets prevuse node
		prev = (Node*) prevNode;
	}
	
	
	// templates 
	template <typename T>
	void Node<T>:: setData (const T& d)
    {
		data = d;
	}
	
	// templates 
	template <typename T>
	T Node<T>::getData()
    {
		return data;
	}
	
	// templates 
	template <typename T>
	Node<T>* Node<T>::getNext()
    {
		return next;
	}
	
	// templates 
	template <typename T>
	Node<T>* Node<T>::getPrev()
    {
		return prev;
	}
	
	
   
#endif

	