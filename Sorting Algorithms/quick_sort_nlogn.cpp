#include <iostream>
#include <algorithm>

using namespace std;

// Given an array, puts pivot(last number) in it's correct position,
// in a way that all elements before are smaller than him,
// and all elements after are greatter.
// The return it's the pivot index.
/*
 * Example:
 * 1 6 2 3, 5(pivot) => i = 0
 * 1 2 6 3, 5(pivot) => i = 1
 * 1 2 3 6, 5(pivot) => i = 2
 * Final swap: 1 2 3 5 6 => i = 3
 */
int partition(int *A, int low, int high) {
    int pivot = A[high];
    // index of the greattest element smaller than the pivot
    int i = low-1;

    for(int j = low; j <= high-1; j++) {
        if(A[j] < pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i+1], A[high]);
    return (i + 1);
};

/// Recursive function to sort an array of integers.
// low: starting index, high: ending index
void quick_sort(int *A, int low, int high) {
    if(low < high) {
        // partition_idx it's gonna be the right place of the current pivot in A
        int partition_idx = partition(A, low, high);

        quick_sort(A, low, partition_idx-1);
        quick_sort(A, partition_idx+1, high);
    }
};

int main() {
    int array[12] = {28, 15, 49, 0, -3, 66, 100, 4, 2, 3, 1, 5};
    int array_size =  sizeof(array)/sizeof(array[0]);

    cout << "[ ";
    for(int i = 0; i < array_size; i++) {
        cout << array[i] << " ";
    }
    cout << "]\n";

    quick_sort(array, 0, array_size-1);

    cout << "[ ";
    for(int i = 0; i < array_size; i++) {
        cout << array[i] << " ";
    }
    cout << "]\n";

}