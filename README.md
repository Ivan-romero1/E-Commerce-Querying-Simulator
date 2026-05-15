# E-Commerce Inventory Query System
This is a C++ command-line inventory query system that simulates a simplified e-commerce product lookup engine using custom-built data structures and sorting algorithms. This project loads and parses product inventory data from a CSV dataset, and stores the data inside self-implemented hash maps and linked lists. 

## Purpose:
This project originated as part of an Advanced Data Structures course project and was later refined and expanded for portfolio purposes. This program contains practical implementation of core CS concepts such as custom hash maps, linked lists, sorting algorithms, file parsing, and algorithmic performance analysis. 

## Empirical Data Analysis and Algorithmic Efficiency Analysis: 
OBSERVATIONS AND INFERENCES BASED ON MERGE SORT AND INSERTION SORT ALGORITHMIC PERFORMANCE:

Okay, so I ran several tests on both merge sort and insertion sort algorithms

Here are my results from them: 
 - All along 10 trials each

## Benchmark Results

| Test # | Number of Elements | Insertion Sort Average Time | Merge Sort Average Time |
|---|---|---|---|
| 1 | 1,000 | 0.977893 ms | 0.345661 ms |
| 2 | 10,000 | 73.2557 ms | 4.37239 ms |
| 3 | 100 | 0.131144 ms | 0.0891453 ms |
| 4 | 5 | 0.0003196 ms | 0.0029033 ms |

Analysis:
--------------------------------------------------------------------------------------
Insertion Sort:
-----------------
From what I could observe, Insertion Sort was generally slower than merge sort, which
was to be expected given that insertion sort has a worst-case complexity of: O(n^2), 
while merge sort has a worst-case complexity of O(n log n). 

Insertion sort is generally slower than merge sort for medium and large unsorted datasets. This is probably due to the fact 
that if a collection is not at least partially sorted, insertion sort's time will really start 
piling up due to the sheer amount of shifting that has to happen. This is especially true in the
instance where the list or collection is fully reversed.

Although in general insertion sort is slower than merge sort, in some cases,
such as when the vector to sort was particularly small (5 elements), the
insertion sort outperformed merge sort. Hence, we can infer that the
insertion sort algorithm performs better when working with smaller
collections. 

Merge Sort:
-----------------
As mentioned before, according to the data acquired through the tests above, we can infer that
merge sort is generally much faster than insertion sort when it comes to large collections of data.
Merge sort's worst-case complexity is O(n log n). This is due to Merge Sort's divide and conquer
approach where the collection gets partitioned, and then gets recursively divided and merged back
together in sorted order. This makes the Merge Sort algorithm especially efficient in sorting 
large collections of data. 
