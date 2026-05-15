/*
    I used my LinkedList.cpp file from PA1-ROMERO as a basis to implement this LinkedList, 
    with obvious modifications to accomodate for this specific assignment.

    So this LinkedList is heavily based upon my linkedList design from PA1, with a couple modifications:
*/
#pragma once

#include <iostream>

using namespace std;

//Template for any data type the list is about:
template <typename T>

struct Node{
	
	T data;
	Node<T>* pNext;
};

template <typename T>

class LinkedList{

private:
	Node<T>* pHead;
	
public:
	//Default Constructor:
	
	LinkedList(){
		pHead = nullptr;
	}

	//Insert Node Method:
	
	void insertNode(T nodeToInsert){
		
		Node<T>* newNode = new Node<T>;
		
		newNode->data = nodeToInsert;

		newNode->pNext = pHead;

		pHead = newNode;
	}

    //Remove Node Method:

    void removeNode(T nodeToRemove)
    {

        Node<T>* prevNode = nullptr;
        Node<T>* currNode = pHead;

        while(currNode != nullptr)
        {

         if(currNode->data == nodeToRemove)
         {

            if(prevNode == nullptr){
                //Remove head node: 
                pHead = currNode->pNext; 
            
            }
            else{

                prevNode->pNext = currNode->pNext;
            }

            delete currNode;
            return;
         }

         prevNode = currNode;
         currNode = currNode->pNext;
        }   
    }

    void printListContents(){

        Node<T>* currentNode = pHead;

        while(currentNode != nullptr){

            currentNode->data.printProductDetails();
            cout << "--------------------------------" << endl;
            currentNode = currentNode->pNext;
        }
    }

    Node<T>* getHead(){

        return this->pHead;
    }

};