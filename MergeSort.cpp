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

/**
 * Merges two sorted subarrays of the given array.
 *
 * @param array The array to merge the subarrays of.
 * @param left The left index of the subarray to merge.
 * @param middle The middle index of the subarray to merge.
 * @param right The right index of the subarray to merge.
 */
void merge(std::vector<int>& array, int left, int middle, int right) {
    // Calculate teh sizes of the two subarrays to be merged.
    int n1 = middle - left + 1;  // Size of the first subarray.
    int n2 = right - middle;     // Size of the second subarray.

    // Create temporary subarrays to store the elements of the two subarrays.
    std::vector<int> left_subarray(n1);
    std::vector<int> right_subarray(n2);

    // Copy the elements of the two subarrays into the temporary subarrays.
    for (int i = 0; i < n1; i++) {
        left_subarray[i] = array[left + i];
    }

    for (int i = 0; i < n2; i++) {
        right_subarray[i] = array[middle + 1 + i];
    }

    // Initial indexes for left subarray, right subarray, and mergd subarray.
    int i = 0;     // Initial index of the first subarray.
    int j = 0;     // Initial index of the second subarray.
    int k = left;  // Initial index of the merged subarray.

    // Merge the two subarrays back into the original array.
    while (i < n1 && j < n2) {
        // Pick the smaller among the smallest element of left and right
        // subarray.
        if (left_subarray[i] <= right_subarray[j]) {
            array[k] = left_subarray[i];
            i++;
        } else {
            array[k] = right_subarray[j];
            j++;
        }

        k++;
    }

    // Copy the remaining elements of left_subarray, if there are any.
    while (i < n1) {
        array[k] = left_subarray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right_subarray, if there are any.
    while (j < n2) {
        array[k] = right_subarray[j];
        j++;
        k++;
    }
}

/**
 * Sorts the given array using the merge sort algorithm.
 *
 * @param array The array to sort.
 * @param left The left index of the array to sort.
 * @param right The right index of the array to sort.
 */
void merge_sort(std::vector<int>& array, int left, int right) {
    if (left < right) {
        // Find the middle point to divide the array into two halves.
        int middle = left + (right - left) / 2;

        // Call merge_sort for the first half.
        merge_sort(array, left, middle);

        // Call merge_sort for the second half.
        merge_sort(array, middle + 1, right);

        // Merge the two halves sorted in the previous steps.
        merge(array, left, middle, right);
    }
}

/**
 * Example usage of the merge_sort() method.
 */
int main() {
    std::vector<int> array = {12, 11, 13, 5, 6, 7};

    // Sort the array using merge_sort.
    merge_sort(array, 0, array.size() - 1);

    // Print the sorted array.
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }

    return 0;
}