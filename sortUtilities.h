#pragma once
#include <vector>
#include <functional>

using namespace std;

template <typename T, typename Compare>
void insertionSort(vector<T>& vectorInput, Compare comp){

    for(size_t index = 1; index < vectorInput.size(); index++){

        //Store the element we want to insert at generic insertionElement variable:
        T insertionElement = vectorInput[index];

        //Have j point at the element before the current index instance:
        int j = index - 1;

        while(j >= 0 && comp(insertionElement, vectorInput[j])){

            vectorInput[j + 1] = vectorInput[j];

            j--;
        }

        vectorInput[j + 1] = insertionElement;
    }
}

template <typename T, typename Compare>
void mergeSort(std::vector<T>& vector, int start, int end, Compare comp){

    if(start >= end){

        return;
    }

    int middle = (start + end) / 2;

    mergeSort(vector, start, middle, comp);
    mergeSort(vector, middle + 1, end, comp);
    mergeSortHelper(vector, start, middle, end, comp);
}

template<typename T, typename Compare>
void mergeSortHelper(std::vector<T>& vector, int start, int middle, int end, Compare comp){

    int l = start;
    int r = middle + 1;

    std::vector<T> sorted;

    while(l <= middle && r <= end){
        
        if(comp(vector[l], vector[r])){

            sorted.push_back(vector[l++]);
        }
        else{

            sorted.push_back(vector[r++]);
        }
    }

    while(l <= middle){

        sorted.push_back(vector[l++]);
    }

    while(r <= end){

        sorted.push_back(vector[r++]);
    }

    for(int index = 0; index < sorted.size(); index++){

        vector[start + index] = sorted[index];
    }
}

//Wrapper function, in order to reduce the argument when an outside call of mergeSort is received:
template<typename T, typename Compare>
void mergeSort(std::vector<T>& vector, Compare comp){

    if(vector.size() <= 1){

        //Trivial case. Vector is sorted!
        return;
    }

    mergeSort(vector, 0, vector.size() - 1, comp);
}