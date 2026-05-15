#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "utilities.h"
#include "sortUtilities.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

//Global Scope: 
Map<string, Product> productsMap;
LinkedList<Product> categoriesList;

Map<string, LinkedList<Product>> categoryMap;

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
}

bool validCommand(string line)
{   
    bool result;

    if(line == ":help" || line.rfind("find", 0) == 0 || line.rfind("listInventory") == 0){

        result = true;
    }
    else{

        result = false;
    }

    return result;
}

void evalCommand(string line)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        
        cout << "\nPlease enter the product ID of the product you want to find: " << endl;
        
        string userInput;
        
        getline(cin, userInput);

        cout << "\n" << endl;

        Product product;

        Product foundProduct;

        if(productsMap.find(userInput, foundProduct) == true){

            cout << "\nProduct Found!" << endl;
            
            cout << "------------------------------------------------------------------------------------------" << endl;
            foundProduct.printProductDetails();
            cout << "------------------------------------------------------------------------------------------" << endl;

            cout << "\nPlease enter next command or ':quit' to exit the app." << endl;
        }
        else{

            cout << "Product was not found :(" << endl;
        }
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        string category;
        string sortType;
        string sortOrder;

        //Skip whitespace:
        string skip;

        cout << "\nPlease enter the product category:" << endl;
        getline(cin, category);

        cout << "" << endl;

        cout << "Please enter the product's sort type:" << endl;
        cout << " - If insertion sort, type: 'insertion sort'" << endl;
        cout << " - If merge sort, type: 'merge sort'" << endl;

        getline(cin, sortType);

        cout << "" << endl;

        cout << "Please enter the product's sort order:" << endl;
        cout << " - If ascending order: just press 'Enter' key " << endl;
        cout << " - If descending order: just type 'desc' " << endl;

        getline(cin, sortOrder);

        cout << "" << endl;

        LinkedList<Product>* pList;
        vector<Product> productsVector;

        cout << "Products in Category: "<< category << endl;

        bool useMergeSort = false;
        bool useDescendingOrder = false;

        if(sortType == ""){

            cout << "\n Sort type field left empty. Defaulting to Insertion Sort..." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }

        if(sortType == "merge" || sortType == "mergeSort" || sortType == "merge sort" || sortType == "Merge Sort"){

            useMergeSort = true;
        }

        if(sortOrder == "desc" || sortOrder == "descending"){

            useDescendingOrder = true;
        }

        if(categoryMap.findForInventory(category, pList)){

            Node<Product>* current = pList->getHead();

            while(current != nullptr){

                productsVector.push_back(current->data);
                current = current->pNext;
            }

            if(useMergeSort){

                cout << "Using Merge Sort..." << endl;

                std::this_thread::sleep_for(std::chrono::seconds(2));

                //MergeSort to implement:
                if(useDescendingOrder){

                    cout << "Printing in Descending order..." << endl;

                    std::this_thread::sleep_for(std::chrono::seconds(2));

                    mergeSort<Product>(productsVector, [](const Product& product1, const Product& product2){

                        return product1.sellingPrice > product2.sellingPrice;
                    });
                }
                else{

                    cout << "Printing in Ascending order..." << endl;

                    std::this_thread::sleep_for(std::chrono::seconds(2));

                    mergeSort<Product>(productsVector, [](const Product& product1, const Product& product2){

                        return product1.sellingPrice < product2.sellingPrice;
                    });                    
                }
            }
            else{

                if(useDescendingOrder){

                    insertionSort<Product>(productsVector, [](const Product& product1, const Product& product2){
                        
                        return product1.sellingPrice > product2.sellingPrice;
                    });
                }
                else{

                    insertionSort<Product>(productsVector, [](const Product& product1, const Product& product2){
                        
                        return product1.sellingPrice < product2.sellingPrice;
                    });
                }
            }

            cout << "--------------------------------------------------------------" << endl;
            for(int index = 0; index < productsVector.size(); index++){
                
                productsVector[index].printProductDetails();
                cout << "--------------------------------------------------------------" << endl;
                
                std::this_thread::sleep_for(std::chrono::milliseconds(24));
            }

            cout << "Now please enter next command or 'quit' to exit the app. " << endl;
        }
        else{

            cout << "Invalid category :( No instances of the given category were found" << endl;
        }
    }
}

void loadAndParseFileContents(Map<string, Product>& mapDestinations, const string& fileName);

void bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices

    loadAndParseFileContents(productsMap, "products.csv");
    loadAndParseFileContentsForCategories(categoryMap, "products.csv");
}

//Function prototype for scope testing:
void runFullAlgorithmicTimeEfficiencyTest(const int numberOfElements, const int numberOfTrials);

int main(int argc, char const *argv[])
{
    string line;
    bootStrap();
    while (getline(cin, line) && line != ":quit")
    {
     
        if(validCommand(line)){

            evalCommand(line);
        }
        else{

            cout << "\nEnter a valid command or enter ':quit' to exit the app\n";
        }
        cout << ">";
    }

    cout << "Running Full Test on 5 Elements \n" << endl;
    runFullAlgorithmicTimeEfficiencyTest(5, 10);

    return 0;
}

void displayStats(const vector<double> &durations){

    double averageTime = 0.0;

    for(int index = 0; index < durations.size(); index++){

        averageTime = averageTime + durations[index];
    }

    averageTime = averageTime / durations.size();

    cout << "=======Time Performance=======" << endl;
    cout << "Average Time: " << averageTime << endl;
    cout << "-------------------------------" << endl;
}

//I will test both algorithms on an integers vector to make it easier to implement:
//This testing format is heavily based off MA3's statistics test, with a couple of tweaks:
void runFullAlgorithmicTimeEfficiencyTest(const int numberOfElements, const int numberOfTrials){
    
    const int MAX_VALS = 10000;

    srand(static_cast<unsigned>(time(nullptr)));

    vector<double> insertionDurations;
    vector<double> mergeDurations;

    cout << "Insertion Sort Stats: " << endl;
    cout << "---------------------------------------" << endl;

    for(int trial = 0; trial < numberOfTrials; trial++){

        vector<int> data(numberOfElements);

        //Generate an x amount of random numbers and populate the vector:
        for(int i = 0; i < numberOfElements; i++){

            data[i] = rand() % (MAX_VALS + 1);
        }

        auto start = chrono::high_resolution_clock::now();

        insertionSort<int>(data, [](const int& int1, const int& int2){
            return int1 < int2;
        });

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> duration = end - start;

        insertionDurations.push_back(duration.count());
    }
    
    displayStats(insertionDurations);

    cout << "\nMerge Sort Stats: " << endl;
    cout << "---------------------------------------" << endl;

    for(int trial = 0; trial < numberOfTrials; trial++){

        vector<int> data(numberOfElements);

        //Generate an x amount of random numbers and populate the vector:
        for(int i = 0; i < numberOfElements; i++){

            data[i] = rand() % (MAX_VALS + 1);
        }

        auto start = chrono::high_resolution_clock::now();

        mergeSort<int>(data, [](const int& int1, const int& int2){
            
            return int1 < int2;
        });

        auto end = chrono::high_resolution_clock::now();
        
        chrono::duration<double, std::milli> duration = end - start;

        mergeDurations.push_back(duration.count());
    }

    displayStats(mergeDurations);
}
