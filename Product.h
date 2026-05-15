#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>



//Just for debugging purposes, I will use vector to verify various functionalities:
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Product{

    
    public:
    string uniqueId;
    string productName;
    string productCategory;

    //Added for PA5 Enhancement Purposes:
    double sellingPrice;

    //Public Default Constructor:
    Product(){

        this->uniqueId = "DefaultId";
        this->productName = "DefaultProductName";
        this->productCategory = "DefaultProductCategory";

        //Added for PA5 Enhancement Purposes
        this->sellingPrice = 0.0;
    }

    //Public Parametrized Constructor:
    Product(string uniqueIdToSet, string productNameToSet, string productCategoryToSet, double sellingPriceToSet){

        this->uniqueId = uniqueIdToSet;
        this->productName = productNameToSet;
        this->productCategory = productCategoryToSet;

        //PA5 Enhancement:
        this->sellingPrice = sellingPriceToSet;
    }

    //Print Details Method:
    void printProductDetails(){

        cout << "Product ID: " << this->uniqueId << endl;
        cout << "Product Name: " << this->productName << endl;
        cout << "Product Category: " << this->productCategory << endl;

        //PA5 Enhancement:
        cout << "Product Selling Price: $" << this->sellingPrice << endl;
    }

    //Setters and Getters:
    void setUniqueId(string uniqueIdToSet){

        this->uniqueId = uniqueIdToSet;
    }

    void setProductName(string productNameToSet){

        this->productName = productNameToSet;
    }

    void setProductCategory(string productCategoryToSet){

        this->productCategory = productCategoryToSet;
    }

    //In case we need to set the price externally...
    void setProductSellingPrice(double sellingPriceToSet){

        this->sellingPrice = sellingPriceToSet;
    }

    bool operator==(const Product& other) const{

        return uniqueId == other.uniqueId;
    }
};


#endif