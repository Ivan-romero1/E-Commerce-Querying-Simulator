# E-Commerce Inventory Query System
This is a C++ command-line inventory query system that simulates a simplified e-commerce product lookup engine using custom-built data structures and sorting algorithms. This project loads and parses product inventory data from a CSV dataset, and stores the data inside self-implemented hash maps and linked lists. 

## Purpose:
This project originated as part of an Advanced Data Structures course project and was later refined and expanded for portfolio purposes. This program contains practical implementation of core CS concepts such as custom hash maps, linked lists, sorting algorithms, file parsing, and algorithmic performance analysis. 

## Empirical Data Analysis and Algorithmic Efficiency Analysis: 
OBSERVATIONS AND INFERENCES BASED ON MERGE SORT AND INSERTION SORT ALGORITHMIC PERFORMANCE:

Okay, so I ran several tests on both merge sort and insertion sort algorithms

Here are my results from them: 
 - All along 10 trials each

Test Number: 1
# of Elements: 1000
Stats:
Insertion Sort Stats:
---------------------------------------
=======Time Performance=======
Average Time: 0.977893 ms
-------------------------------

Merge Sort Stats:
---------------------------------------
=======Time Performance=======
Average Time: 0.345661 ms
-------------------------------

=====================================================

Test Number: 2
# of Elements: 10,000
Stats:
Insertion Sort Stats:
---------------------------------------
=======Time Performance=======
Average Time: 73.2557 ms
-------------------------------

Merge Sort Stats:
---------------------------------------
=======Time Performance=======
Average Time: 4.37239 ms
-------------------------------

=====================================================

Test Number: 3
# of Elements: 100
Stats:
Insertion Sort Stats:
---------------------------------------
=======Time Performance=======
Average Time: 0.131144
-------------------------------

Merge Sort Stats:
---------------------------------------
=======Time Performance=======
Average Time: 0.0891453
-------------------------------

=====================================================
Test Number: 4
# of Elements: 5
Stats:
Insertion Sort Stats:
---------------------------------------
=======Time Performance=======
Average Time: 0.0003196
-------------------------------

Merge Sort Stats:
---------------------------------------
=======Time Performance=======
Average Time: 0.0029033

=======================================================================================

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

Although, in general insertion sort is slower than merge sort, in very some cases,
such as when the vector to sort was particularly small (5 elements), then insertion
sort outperformed merge sort. Hence, we can infer that insertion sort algorithm
performs better when working with smaller collections. 
---------------------------------------------------------------------------------------

---------------------------------------------------------------------------------------
Merge Sort:
-----------------
As mentioned before, according to my data acquired through some tests, we can infer that
merge sort is generally much faster than insertion sort, especially for large collections of data. 
Merge sort's worst-case complexity as mentioned before is O(n log n). This is due to merge sort's
divide and conquer approach, where the collection gets partitioned and then the collection is revursively divided and merged back together in sorted order, making the algorithm especially efficient for large collections. 
