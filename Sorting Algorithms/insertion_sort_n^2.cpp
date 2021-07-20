#include <iostream>
#include <algorithm>

using namespace std;

void insertion_sort(int array[], int n) {
    for(int i = 1; i < n; i++) {
        int value = array[i];
        int value_idx = i;
        while(value < array[value_idx-1] && value_idx > 0) {
            swap(array[value_idx], array[value_idx-1]);
            value_idx--;
        }
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

    insertion_sort(array, array_size);

    cout << "[ ";
    for(int i = 0; i < array_size; i++) {
        cout << array[i] << " ";
    }
    cout << "]\n";

}