#include <iostream>
using namespace std;
const int ROW_SIZE = 3;
const int COL_SIZE = 3;

// Prints the 2D Array
void printArray(int arr[ROW_SIZE][COL_SIZE]) {
    for(int i = 0; i < ROW_SIZE; i++) {
        for(int j = 0; j < COL_SIZE; j++) {
            cout << arr[i][j] << " ";
        } 
        cout << endl;
    }
}

// Sums all elements
int sumArray(int arr[ROW_SIZE][COL_SIZE]) {
    int sum = 0;
    for(int i = 0; i < ROW_SIZE; i++)
        for(int j = 0; j < COL_SIZE; j++)
            sum += arr[i][j];
    return sum; 
}

// Sums each column alone
void sumColumns(int arr[ROW_SIZE][COL_SIZE]) {
    for(int i = 0; i < ROW_SIZE; i++) {
        int col = 0;
        for(int j = 0; j < COL_SIZE; j++) {
            col += arr[j][i];
        }
        cout << col << endl;
    }
}

void sumRows(int arr[ROW_SIZE][COL_SIZE]) {
    for(int i = 0; i < ROW_SIZE; i++) {
        int row = 0;
        for(int j = 0; j < COL_SIZE; j++) {
            row += arr[i][j];
        }
        cout << row << endl;
    }
}

int main() {
    // 83 86 77
    // 15 93 35
    // 86 92 49
    int arr[ROW_SIZE][COL_SIZE] = {{83, 86, 77}, {15, 93, 35}, {86, 92, 49}};
    // for(int i = 0; i < ROW_SIZE; i++)
    //     for(int j = 0; j < COL_SIZE; j++)
    //         arr[i][j] = rand() % 100;
    // printArray(arr);
    // cout << sumArray(arr);
    // sumColumns(arr);
    // sumRows(arr);
}
