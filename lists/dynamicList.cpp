#include <iostream>
#include <cstdlib>
using namespace std;

/*
    Problems with the dynamic array lists
    - insert() and erase() are inefficient because they keep shifting the elements
    - if the array is full, a larger array needs to be allocated and the original list is copied to the new one
    - if list size flucuates, the array may end up having unused space or needs frequent resizing
    Solution → Linked Lists
*/

class DynamicList {
private:
    int size;
    int capacity;
    int *data;

    void checkMemoryAllocation() {
        // If the data is 0 ( nullptr ) an error message is written and the program exits
        if(data == 0) {
            cerr << "Memory allocation failed\n";
            exit(1);
        }
        // Alternative to the if statement:
        // assert(data != 0);
    }
public:
    // Constructor with optional paramater maxSize
    // if not specified defaults to 8
    // O(1)
    DynamicList(int maxSize = 8) {
        size = 0;
        capacity = maxSize;
        // nothrow means if allocation fails, return nullptr instead of crashing
        data = new(nothrow) int[capacity];
        checkMemoryAllocation();
    }

    // Copy constructor
    // O(n) - Loops over every element to copy it
    DynamicList(const DynamicList &original) {
        size = original.size;
        capacity = original.capacity;
        data = new(nothrow) int[capacity];
        checkMemoryAllocation();
        for(int i = 0; i < size; i++) {
            data[i] = original.data[i];
        }
    }

    // Destructor for when the list goes out of scope
    // O(1)
    ~DynamicList() {
        // Delete the array from memory
        delete []data;
        data = NULL;
    }

    // Assignment operator, used so the whole list is copied instead of the address
    // eg: myList = otherList
    // Best case O(1) - if they have the same address
    // Worst case O(n) - if they are different objects, therefore we loop over them to copy every element
    const DynamicList &operator=(const DynamicList &original) {
        // Check if they have the same address ( they are the same list )
        if(this == &original) return *this;
        // Check for capacity, if they have different capacities delete old data array and replace with a new one with the new capacity
        if(capacity != original.capacity) {
            delete []data;
            capacity = original.capacity;
            data = new(nothrow) int[capacity];
            checkMemoryAllocation();
        }
        size = original.size;
        // Copy the original list's data
        for(int i = 0; i < size; i++) {
            data[i] = original.data[i];
        }
        // Returns the current object
        return *this;
    }

    // Check if the list is empty
    // O(1)
    bool isEmpty() const {
        return size == 0;
    }

    // Check if the list is full
    // O(1)
    bool isFull() const {
        return size == capacity;
    }

    // Insert an item at a given position
    // Best case O(1) - Inserting at the end therefore no shifting is needed
    // Worst case O(n) - Inserting at the beginning therefore the whole array needs to be shifted
    void insert(int value, int pos) {
        if(isFull()) {
            cerr << "\nList is full\n";
            return;
        }
        if(pos < 0 || pos > size) {
            cerr << "\nInvalid position\n";
            return;
        }

        // 0, 1, 2, 3, 4, 5
        // Assume we want to insert 7 at position 2
        // We wanna shift everything to the right then insert at position 2
        // Same as ArrayList
        for(int i = size; i > pos; i--) {
            data[i] = data[i-1];
        }
        data[pos] = value;
        size++;
    }

    // Remove a value from the list
    // Best case O(1) - Erasing the last element therefore no shifting is needed
    // Worst case O(n) - Erasing the first element therefore the whole array needs to be shifted
    void erase(int pos) {
        if(isEmpty()) {
            cerr << "\nList is empty\n";
            return;
        }
        if(pos < 0 || pos >= size) {
            cerr << "\nInvalid position\n";
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

    // Reverse the array ( Using 2 pointers algorithm )
    // eg: [1, 2, 3] → [3, 2, 1]
    // O(n) - Loops over every element
    void reverse() {
        int L = 0, R = size-1;
        while(R > L) {
            int temp = data[L];
            data[L] = data[R];
            data[R] = temp;
            L++;
            R--;
        }
    }

    // Display the list using a stream
    // O(n) - Loops over all elements
    void display(ostream &out) const {
        out << "[ ";
        for(int i = 0; i < size; i++) {
            out << data[i] << " ";
        }
        out << "]\n";
    }
};

// O(n) - Uses the display method which loops over all elements
ostream &operator << (ostream &out, const DynamicList &list) {
    list.display(out);
    return out;
}
