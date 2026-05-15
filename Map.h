//According to PA4's instructions, I can use std::hash, so:
#pragma once
#include <functional>
#include "Product.h"

using namespace std;

//General template for any data type:
template <typename Key, typename Value>
class Map{
private:
    struct mapNode{

        Key key;
        Value value;
        mapNode* pNext;

        //Constructor:
        mapNode(const Key& keyToSet, const Value& valueToSet){

            this->key = keyToSet;
            this->value = valueToSet;
            this->pNext = nullptr;
        }
    };

    //As a table size I'll choose 103 because it is a prime number:
    static const size_t SIZE_OF_TABLE = 103;

    mapNode* table[SIZE_OF_TABLE];

    size_t returnHashIndex(const Key& key) const{

        return std::hash<Key>{}(key) % SIZE_OF_TABLE;
    }

public:
    //Constructor and Destructor of Map:
    Map(){
        
        //Initializing all buckets to nullptr's:
        for(size_t index = 0; index < this->SIZE_OF_TABLE; index++){

            table[index] = nullptr;
        }

        //Constructor:
        //cout << "Constructor called" << endl; 
    }

    ~Map(){

        for(size_t index = 0; index < this->SIZE_OF_TABLE; index++){

            mapNode* currentNode = table[index];

            while(currentNode != nullptr){

                mapNode* nodeToDelete = currentNode;
                
                mapNode* nextNode = currentNode->pNext;

                currentNode = nextNode;

                delete nodeToDelete;
            }
        }

        cout << "Destructor Called!" << endl;        
    }

    //Functions: insert, find and listInventory:
    void insert(const Key& key, const Value& value){

        size_t index = returnHashIndex(key);

        mapNode* currentNode = table[index];

        //If key exists, then:
        while(currentNode != nullptr){

            if(currentNode->key == key){

                currentNode->value = value;
                return;
            }

            currentNode = currentNode->pNext;
        }

        //If the key doesn't exist, make a new node:
        mapNode* newNode = new mapNode(key, value);
        mapNode* nextNode = table[index];

        newNode->pNext = nextNode;
        table[index] = newNode;
    }

    //According to instructions, if uniqueId found, then returns the product details:
    bool find(const Key& key, Value& value){

        size_t index = returnHashIndex(key);

        mapNode* currentIndex = table[index];
        
        //Traverse the list 
        while(currentIndex != nullptr){

            if(currentIndex->key == key){

                value = currentIndex->value;
                //print product details:

                return true;
            }

            currentIndex = currentIndex->pNext;
        }

        return false;
    }

    bool findForInventory(const Key& key, Value*& value){

        size_t index = returnHashIndex(key);

        mapNode* currentIndex = table[index];

        while(currentIndex != nullptr){

            if(currentIndex->key == key){

                value = &(currentIndex->value);
                return true;
            }

            currentIndex = currentIndex->pNext;
        }
        
        return false;
    }

};