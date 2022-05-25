#include <iostream>
using namespace std;

bool binarySearch(int *arr, int k) {
    int left = 0;
    int right = sizeof(arr)/sizeof(arr[0])-1;
    while(left <= right) {
        int middle = left + ((right-left)/2);
        if(arr[middle] == k) return true;
        else if(arr[middle] < k) left = middle+1;
        else right = middle-1;
    }
    return false;
}

int main() {
    int arr[] = {1,3,4,5};
    cout << binarySearch(arr, 2) << endl;
    cout << binarySearch(arr, 1) << endl;

    return 0;
}

