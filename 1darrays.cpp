#include <iostream>
using namespace std;
const int ARRAY_SIZE = 5;

// Print the 1D array
void printArr(int arr[]) {
    for(int i = 0; i < ARRAY_SIZE; i++) cout << arr[i] << " ";
    cout << endl;
}

// Return the index of the largest item with the largest index
// eg: {55, 77, 93, 32, 93} -> returns 4
int largestItemLargestIndex(int arr[]) {
    int idx = 0;
    for(int i = 1; i < ARRAY_SIZE; i++) {
        if(arr[i] >= arr[idx]) { idx = i; }
    }
    return idx;
}

// Return the index of the largest item but with the smallest index
// eg: {55, 77, 93, 32, 93} -> returns 2
int largestItemSmallestIndex(int arr[]) {
    int idx = 0;
    for(int i = 1; i < ARRAY_SIZE; i++) {
        if(arr[i] > arr[idx]) { idx = i; }
    }
    return idx;
}

int main() {
    int arr[ARRAY_SIZE] = {55, 77, 93, 32, 93};
    // for(int i = 0; i < ARRAY_SIZE; i++) {
    //     arr[i] = rand() % 100; 
    // }
    printArr(arr);
    int idx  = largestItemLargestIndex(arr);
    int idx2 = largestItemSmallestIndex(arr);
    cout << arr[idx] << " " << idx << endl;
    cout << arr[idx2] << " " << idx2 << endl;
}
