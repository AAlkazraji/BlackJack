//Name: Assignment 2
//Author: Ahmed Al-khazraji
//Student numbers: c3277545
//Student email: c3277545@uon.edu.au
//date:21/10/2020
//Course: seng1120


#ifndef Ahmed_LINKEDLIST
#define Ahmed_LINKEDLIST
#include <cstdlib>
#include <iostream>
using namespace std;
#include "Node.h"
template <typename T>  




	class LinkedList
	{
		public:
			// Constructors
			LinkedList();
			
			// Constructors
			LinkedList(T& data); 
			
			// Descructors 
			~LinkedList();	
			
			//member function: adding data to the tail
			//preconditons: valid data
			//postcondition: data stored in tail
			void addTail(const T& data);
			
			//member function: adding data to the head
			//preconditons: valid data
			//postcondition: data stored in head			
			void addHead(const T& data);
			
			//member function: removing the head
			//preconditons: there has to be head 
			//postcondition: head removed  
			void removeHead();
			
			//member function: removing the tail
			//preconditons: there has to be tail
			//postcondition: tail removed
			void removeTail();
			
			//member function: return head
			//preconditons: there has to be head 
			//postcondition: return head
			Node<T>* getHead() const;
			
			//member function: return head data
			//preconditons: there has to be head 
			//postcondition: return head data
			T getHeadData() const;
			T getTailData() const;
			
			//member function: return tail
			//preconditons: there has to be tail
			//postcondition: return tail
			Node<T>* getTail() const;
			
			//member function: return current 
			//preconditons: there has to be carrunt data 
			//postcondition: return current
            Node<T>* getCurrent() const;
			
			//member function: sets current data 
			//preconditons: there has to be carrunt data  
			//postcondition: sets the current 
			void setCurrent(Node<T>* newCurrent);
			
			T getLength(); 

		private:
			Node<T>* head;     
			Node<T>* tail;     
			Node<T>* current;  
			int length;	
	};

	// Constructors takes 0 arguments and sets varbles to null and lenght to 0
	// temblates 
    template <typename T> 
	LinkedList<T>::LinkedList()    
    {
		//sets head to null
        head = NULL; 
		// sets tail to null
        tail = NULL; 
		// sets current to null
        current = NULL;
		//sets length to 0
        length = 0;
    }
	
    // Constructors
	// temblates 
	template <typename T>
    LinkedList<T>::LinkedList(T& data)
    {
		// make node
        head = new Node<T>(data);
		//sets tail = to head
        tail = head;
		// sets current = tail
        current = tail; 
		// sets length = 0
        length = 1;             
        return;
    }
    // Descructors 
	// temblates 
	template <typename T>
    LinkedList<T>::~LinkedList()
	{
		// while loop breakes when head = null
        while(head != NULL)   
        {
			//temprary varble type node
			Node<T>* temp;
			//sets temprary = head
            temp = head;
			//storing next node to head
            head = head->getNext();
			// if statment works when head is has data
            if (head != NULL)
			{
			// when head is not null sets prevuse node to head
			head->setPrev(NULL);
			}	
            else
			{
			tail = NULL;
			} 
			// deleting temprary to avoid momary leaks
            delete temp; 					
            current = head; 								
        }
		length = 0;												
    }
    
	// temblates 
	template <typename T>
    void LinkedList<T>::addTail(const T& data)
    {
		//if statment works only when length = 0
        if (length == 0)
        {
			
            tail = new Node<T>(data); 		
            head = tail;                   
            length = 1;            					
        }
        else
        {
			//making new tail type node
            Node<T>* newTail = new Node<T>(data);
			//sets tail to new node
            tail->setNext(newTail);  
			//sets new tail to prevuse node 
            newTail->setPrev (tail);   			
            tail = newTail; 
			//length increses every time else stament works
            length++;                         	 
            newTail = NULL;                   		
        }
  
    }
	
	// temblates 
	template <typename T>
	void LinkedList<T>::removeHead()
	{
		Node<T>* tempHead = head;
		head = head->getNext();
		if(head != NULL)
		{
			head->setPrev(NULL);
		}
		else
		{
			tail = NULL;
		}
		// length decreses every time head removed 
		length --;
		//delete temp head to avoid momary leaks
		delete tempHead;
		
	}
	
	// temblates 
	template <typename T>
	void LinkedList<T>::removeTail()
	{
		
		Node<T>* tempTail = tail;
		tail = tail->getPrev();
		if(tail != NULL)
		{
			tail->setNext(NULL);
		}
		else
		{
			head = NULL;
		}
		// length decreses every time tail removed 
		length --;
		//delete temp tail to avoid momary leaks
		delete tempTail;
		
	}
	
	// temblates 
	template <typename T>
	void LinkedList<T>::addHead(const T& data)
	{
		if (length == 0)
        {
			//assigning tail to node
            tail = new Node<T>(data);
			//assigning head to tail
            head = tail;           
            current = head;        
            length = 1;            									
        }
		else
		{
		    Node<T>* newHead = new Node<T>(data);   						
            head->setPrev(newHead);         						
            newHead->setNext (head);   						
            head = newHead;
            length++;                         						
            newHead = NULL;
		}
	}
   
   // temblates 
    template <typename T>
    Node<T>* LinkedList<T>::getCurrent() const
        {
            return current;  
        }

	// temblates 
    template <typename T>
    Node<T>* LinkedList<T>::getHead() const
        {
            return head;
        }
	
	// temblates 
	template <typename T>	
	T LinkedList<T>::getHeadData() const
	{
		T data= head->getData();
		return data;
	}
	
	template <typename T>	
	T LinkedList<T>::getTailData() const
	{
		T data= tail->getData();
		return data;
	}
		
	// temblates 
	template <typename T>
    Node<T>* LinkedList<T>::getTail() const
        {
            return tail;
        }
	// temblates 
    template <typename T>
    void LinkedList<T>::setCurrent(Node<T>* NewCurrent)
        {
            current = NewCurrent;
        }
		
	template <typename T>	
	T LinkedList<T>::getLength() 
	{
		return length;
	}
	

#endif