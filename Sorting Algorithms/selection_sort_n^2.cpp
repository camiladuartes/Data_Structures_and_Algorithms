#include <iostream>
#include <algorithm>

using namespace std;

void selection_sort(int array[], int n) {
    for(int i = 0; i < n; i++) {
        int min_idx = i;
        for(int j = i+1; j < n; j++) {
            if(array[j] < array[min_idx])
                min_idx = j;
        }
        swap(array[i], array[min_idx]);
    }
};

int main() {
    int array[4] = {2, 3, 1, 5};
    int array_size =  sizeof(array)/sizeof(array[0]);

    cout << "[ ";
    for(int i = 0; i < array_size; i++) {
        cout << array[i] << " ";
    }
    cout << "]\n";

    selection_sort(array, array_size);

    cout << "[ ";
    for(int i = 0; i < array_size; i++) {
        cout << array[i] << " ";
    }
    cout << "]\n";

}