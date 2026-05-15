#include "Product.h"
#include "Map.h"
#include "utilities.h"

//load and parse file contents onto specified structure.
void loadAndParseFileContents(Map<string, Product>& mapDestinations, const string& fileName){

    //Open the streamfile:
    ifstream streamFile(fileName);

    //line placeholder
    string line = "";

    //getstringfile line
    getline(streamFile, line);

      while(getline(streamFile, line)){

        stringstream lineStringStream(line);

        string uniqueId;
        string productName;
        string productCategory;

        //PA5 Enhancements:
        string priceString;
        double sellingPrice = 0.0;

        string field;
        int columnCounter = 0;

        while(getline(lineStringStream, field, ',')){

            //Get rid of quotes:
            if(!field.empty() && field.front() == '"'){

                field.erase(0,1);
            }

            if(!field.empty() && field.back() == '"'){

                field.erase(field.size() - 1);
            }
            
            //Here I'm counting each column in order to extract only the necessary fields:
            if(columnCounter == 0){

                uniqueId = field;
            }
            else if(columnCounter == 1){

                productName = field;
            }
            else if(columnCounter == 4){

                productCategory = field;
            }
            else if(columnCounter == 7){

                priceString = field;
                
                if(!priceString.empty() && priceString.front() == '$'){

                    priceString.erase(0,1);
                }

                if(!priceString.empty()){

                    stringstream stream(priceString);

                    stream >> sellingPrice;

                    if(stream.fail() || !stream.eof()){

                        //default to 0.0 for empty double field:
                        sellingPrice = 0.0;
                    }
                }
                else{

                    sellingPrice = 0.0;
                }
            }

            columnCounter++;
        }

        //If category field is empty, then I'll replace it with string "N/A"
        if(productCategory.empty()){

            productCategory = "N/A";
        }

        //UPDATE TO INCLUDE PRODUCT PRICE:
        Product product(uniqueId, productName, productCategory, sellingPrice);

        mapDestinations.insert(uniqueId, product);     
    }

    //cout << "File contents parsed and loaded properly" << endl;
}

void loadAndParseFileContentsForCategories(Map<string, LinkedList<Product>>& categoryMap, const string& fileName){

//Open the streamfile:
    ifstream streamFile(fileName);

    //line placeholder
    string line = "";

    //getstringfile line
    getline(streamFile, line);

      while(getline(streamFile, line)){

        stringstream lineStringStream(line);

        string uniqueId;
        string productName;
        string productCategory;

        //PA5 Enhancements:
        string priceString;
        double sellingPrice = 0.0;

        string field;
        int columnCounter = 0;

        while(getline(lineStringStream, field, ',')){

            //Get rid of quotes:
            if(!field.empty() && field.front() == '"'){

                field.erase(0,1);
            }

            if(!field.empty() && field.back() == '"'){

                field.erase(field.size() - 1);
            }
            
            //Here I'm counting each column in order to extract only the necessary fields:
            if(columnCounter == 0){

                uniqueId = field;
            }
            else if(columnCounter == 1){

                productName = field;
            }
            else if(columnCounter == 4){

                productCategory = field;
            }
            else if(columnCounter == 7){

                priceString = field;
                
                if(!priceString.empty() && priceString.front() == '$'){

                    priceString.erase(0,1);
                }
                
                if(!priceString.empty()){

                    stringstream stream(priceString);

                    stream >> sellingPrice;

                    if(stream.fail() || !stream.eof()){

                        //default to 0.0 for empty double field:
                        sellingPrice = 0.0;
                    }
                }
                else{

                    sellingPrice = 0.0;
                }
            }

            columnCounter++;
        }

        //If category field is empty, then I'll replace it with string "N/A"
        if(productCategory.empty()){

            productCategory = "N/A";
        }

        Product product(uniqueId, productName, productCategory, sellingPrice);

        stringstream stringStream(productCategory);

        string category;

        while(getline(stringStream, category, '|')){

            category.erase(0, category.find_first_not_of(" \t"));
            category.erase(category.find_last_not_of(" \t") + 1);

            LinkedList<Product>* pList = nullptr;

            if(categoryMap.findForInventory(category, pList)){

                pList->insertNode(product);
            }
            else{

                LinkedList<Product> list;

                list.insertNode(product);
                categoryMap.insert(category, list);
            }
        }
    }
}
