#include <iostream>
#include <algorithm>

using namespace std;

/// Function to Merge Arrays L and R into A. 
// nL = number of elements in L
// rL = number of elements in R.
void merge(int *L, int nL, int *R, int nR, int *A) {

    /// Merge the temp arrays back into arr[l..r], assuming that they are sorted
    // Initial index of first subarray
    int i = 0;
    // Initial index of second subarray
    int j = 0;
    // Initial index of merged subarray
    int k = 0;

    // While one of the subarrays doesnt end
    while(i < nL and j < nR) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    /// Now one of the following while loops will execute:
    // Copy the remaining elements of L[], if there are any
    while(i < nL) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while(j < nR) {
        A[k] = R[j];
        j++;
        k++;
    }
};

/// Recursive function to sort an array of integers. 
void merge_sort(int *A, int n) {

    if(n < 2) return;
    
    int mid = n/2;

    int *L, *R;
    L = (int *)malloc(mid * sizeof(int));
    R = (int *)malloc((n-mid) * sizeof(int));

    // Left sublist
    for(int i = 0; i < mid; i++) {
        L[i] = A[i];
    }
    // Right sublist
    for(int j = 0; j < n-mid; j++) {
        R[j] = A[mid+j];
    }

    // Sort left sublist
    merge_sort(L, mid);
    // Sort right sublist
    merge_sort(R, n-mid);

    // Merge sorted L and R sublists into array
    merge(L, mid, R, n-mid, A);

    free(L);
    free(R);
};

int main() {
    int array[12] = {28, 15, 49, 0, -3, 66, 100, 4, 2, 3, 1, 5};
    int array_size =  sizeof(array)/sizeof(array[0]);

    cout << "[ ";
    for(int i = 0; i < array_size; i++) {
        cout << array[i] << " ";
    }
    cout << "]\n";

    merge_sort(array, array_size);

    cout << "[ ";
    for(int i = 0; i < array_size; i++) {
        cout << array[i] << " ";
    }
    cout << "]\n";

}