//
// Copyright Caiden Sanders - All Rights Reserved
//
// Unauthorized copying of this file, via any medium is strictly prohibited.
// Proprietary and confidential.
//
// Written by Caiden Sanders <work.caidensanders@gmail.com>, February 12, 2024.
//

#include <iostream>
#include <vector>

/** Quick sort algorithm */

/**
 * Partitions the array into two subarrays such that all elements in the left
 * subarray are less than or equal to the pivot and all elements in the right
 * subarray are greater than the pivot.
 *
 * @param array The array to partition.
 * @param low The lowest index of the subarray to partition.
 * @param high The highest index of the subarray to partition.
 * @return The index of the pivot element after partitioning.
 */
int partition(std::vector<int>& array, int low, int high) {
    int pivot = array[high];  // Choose the last element as the pivot.
    int i = low - 1;          // Index of the smaller element.

    // Iterate through the array, rearranging elements based on the pivot's
    // value.
    for (int j = low; j < high; j++) {
        // If the current element is less than or equal to the pivot,
        // move it to the right of the pivot.
        if (array[j] <= pivot) {
            i++;  // Increment index of smaller element.
            std::swap(array[i], array[j]);  // Swap the elements at i and j.
        }
    }

    // Place the pivot element in the correct position by swapping it
    // with the element at i + 1, ensuring all elements left of the pivot
    // are less than it, and all elements to the right are greater.
    std::swap(array[i + 1], array[high]);

    return i + 1;  // Return the partitioning index.
}

/**
 * Sorts the array using the quick sort algorithm.
 *
 * @param array The array to sort.
 * @param low The lowest index of the subarray to sort.
 * @param high The highest index of the subarray to sort.
 */
void quick_sort(std::vector<int>& array, int low, int high) {
    if (low < high) {
        // Partition the array and get the index of the pivot element.
        int pivot = partition(array, low, high);

        // Recursively sort the elements before and after partition.
        quick_sort(array, low, pivot - 1);   // Sort the left subarray.
        quick_sort(array, pivot + 1, high);  // Sort the right subarray.
    }
}

/**
 * Example usage of the quick_sort() method.
 */
int main() {
    std::vector<int> array = {12, 11, 13, 5, 6, 7};

    // Sort the array using quick_sort.
    quick_sort(array, 0, array.size() - 1);

    // Print the sorted array.
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }

    return 0;
}