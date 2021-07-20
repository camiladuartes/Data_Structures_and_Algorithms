#include <iostream>
#include <algorithm>

using namespace std;

void bubble_sort(int array[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if(array[j] < array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
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

    bubble_sort(array, array_size);

    cout << "[ ";
    for(int i = 0; i < array_size; i++) {
        cout << array[i] << " ";
    }
    cout << "]\n";

}