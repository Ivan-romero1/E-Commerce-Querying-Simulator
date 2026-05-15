#pragma once
#include "Map.h"
#include "Product.h"
#include "LinkedList.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

//Function Protytype to load necessary file.csv fields into the structure: 
void loadAndParseFileContents(Map<string, Product>& mapDestinations, const string& fileName);

//Modifies loadAndParseFileContents specifically for my categories list:
void loadAndParseFileContentsForCategories(Map<string, LinkedList<Product>>& categoryMap, const string& fileName);
