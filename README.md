# Sorting Algorithms Assignment

## Overview

This document provides a summary of the sorting algorithms implemented for the CS240 assignment. It includes references to pseudocode and actual code implementations, along with a discussion on the time complexities of each algorithm.

## Contents

1. **Merge Sort Algorithm Pseudocode**
   - Commented explanation of the algorithm.
   - See `MergeSortPseudo.txt`

2. **Merge Sort Algorithm Implementation**
   - Implementation in the programming language of your choice, with comments explaining the algorithm.
   - See `MergeSort.cpp`

3. **Quick Sort Algorithm Pseudocode**
   - Commented explanation of the algorithm.
   - See `QuickSortPseudo.txt`

4. **Quick Sort Algorithm Implementation**
   - Implementation in the programming language of your choice, with comments explaining the algorithm.
   - See `QuickSort.cpp`

5. **Comparison of Time Complexities**

   ### MergeSort Time Complexity
   - Best Case: O(n log n)
   - Average Case: O(n log n)
   - Worst Case: O(n log n)

   MergeSort consistently performs at O(n log n) time complexity in the best, average, and worst cases. This predictable performance is due to its divide-and-conquer approach, where the array is divided into halves, sorted, and merged. The process of splitting and merging ensures that every level requires a linear time, causing the O(n log n) performance.

   ### QuickSort Time Complexity
   - Best Case: O(n log n)
   - Average Case: O(n log n)
   - Worst Case: O(n^2)

   QuickSort also employs the divide-and-conquer strategy but chooses a "pivot" element and partitions the array around the pivot. The efficiency depends on the pivot's accuracy. If the pivot is the smallest or the largest element, it leads to unbalanced partitions, and the time complexity degrades to O(n^2), especially in nearly sorted arrays.

6. **Verification of Sorting Algorithms**
   - Use the uploaded file to verify your sort algorithms are working. 
   - The position of 90262 is 3608.
   - The position of 11559 is non-existent as it doesn't exist in the file.
