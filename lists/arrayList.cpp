#include <iostream>
using namespace std;

// The amount of items the array list can take
const int CAPACITY = 8;

/*
    Problems with the static array lists
    - They require continuous memory allocation
    - The size is fixed after initialization
    Solution → Dynamic Arrays
*/

class ArrayList {
private:
    int size;
    int data[CAPACITY];
public:
    // Constructor
    // O(1)
    ArrayList() { size = 0; }

    // Check if the list is empty
    // O(1)
    bool isEmpty() const {
        return size == 0;
    }

    // Check if the list is full
    // O(1)
    bool isFull() const {
        return size == CAPACITY;
    }

    // Insert an item at a given position
    // Best case O(1) - Inserting at the end therefore no shifting is needed
    // Worst case O(n) - Inserting at the beginning therefore the whole array needs to be shifted
    void insert(int value, int pos) {
        if(pos < 0 || pos > size) {
            cerr << "\nInvalid position\n";
            return;
        }
        if(isFull()) {
            cerr << "\nList is full\n";
            return;
        }

        // 0, 1, 2, 3, 4, 5
        // Assume we want to insert 7 at position 2
        // We wanna shift everything to the right then insert at position 2
        for(int i = size; i > pos; i--)
            data[i] = data[i-1];
        
        size++;
        data[pos] = value;
    }

    // Remove a value from the list
    // Best case O(1) - Erasing the last element therefore no shifting is needed
    // Worst case O(n) - Erasing the first element therefore the whole array needs to be shifted
    void erase(int pos) {
        if(pos < 0 || pos >= size) {
            cerr << "\nInavlid position\n";
            return;
        }
        // 0, 1, 2, 3, 4, 5
        // Assume we want to erase at position 2
        // We wanna shift everything to the left starting from position 2 ending at size-1 to not go out of bounds (i+1)
        for(int i = pos; i < size-1; i++) {
            data[i] = data[i+1];
        }
        size--;
    }

    // Display the list using a stream
    // O(n) - It needs to loop over all items
    void display(ostream &out) const {
        out << "[ ";
        for(int i = 0; i < size; i++) {
            out << data[i] << " ";
        }
        out << "]" << endl;
    }
};

// Override the << operator when being given an ArrayList
// eg: cout << myList; → [ 1 2 3 4 ]
// O(n) - Uses the display method which loops over all items
ostream &operator<< (ostream &out, const ArrayList &list) {
    list.display(out);
    return out;
}
