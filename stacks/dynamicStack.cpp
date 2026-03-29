#include <iostream>
using namespace std;

/*
    Problems with the static array lists
    - They require continuous memory allocation
    - The size is fixed after initialization
    - Wasted memory ( if you create a stack of 1000 but use only 3, there is still 997 slots left )
    Solution → Linked List Stack
*/

class DynamicStack {
private:
    int capacity;
    int topIdx;
    int *data;

    void checkMemoryAllocation() {
        if(data == 0) {
            cerr << "\nMemory allocation failed\n";
            exit(1);
        }
        // Alternative to the if statement:
        // assert(data != 0);
    }

    void clearStack() {
        delete []data;
        data = NULL;
        topIdx = -1;
    }
public:
    // Constructor
    // O(1)
    DynamicStack(int cap = 8) {
        capacity = cap;
        data = new(nothrow) int[capacity];
        checkMemoryAllocation();
        topIdx = -1;
    }

    // Copy Constructor
    // O(n) - Always copies every element
    DynamicStack(const DynamicStack &original) {
        capacity = original.capacity;
        topIdx = original.topIdx;
        data = new(nothrow) int[capacity];
        checkMemoryAllocation();
        for(int i = 0; i <= topIdx; i++) {
            data[i] = original.data[i];
        }
    }

    // Destructor
    // O(1)
    ~DynamicStack() {
        clearStack();
    }

    // Assignment operator, used so the whole stack is copied instead of the address
    // Best case O(1) - If they are the same object therefore it returns immediately
    // Worst case O(n) - If they are different therefore we must iterate over all elements to copy
    const DynamicStack &operator = (const DynamicStack &original) {
        if(this == &original) return *this;
        if(capacity != original.capacity) {
            clearStack();
            capacity = original.capacity;
            data     = new(nothrow) int[capacity];
            checkMemoryAllocation();
        }
        topIdx = original.topIdx;
        for(int i = 0; i < topIdx; i++) {
            data[i] = original.data[i];
        }
        return *this;
    }

    // Check if the stack is empty
    // O(1)
    bool isEmpty() const {
        return topIdx == -1;
    }

    // Check if stack is full
    // O(1)
    bool isFull() const {
        return topIdx == capacity-1;
    }

    // Add an item to the top of the stack
    // O(1)
    void push(const int &val) {
        if(isFull()) {
            cerr << "\nStack is full\n";
            return;
        }
        data[++topIdx] = val;
    }

    // Remove the top item from the sack
    // O(1)
    void pop() {
        if(isEmpty()) return;
        topIdx--;
    }

    // Retrieve the top element in the stack
    // O(1)
    int top() const {
        return isEmpty() ? -1 : data[topIdx];
    }

    // Display the stack using a stream
    // Best case O(1) - If stack is empty therefore the loop never runs
    // Worst case O(n) - If stack is full therefore we iterate over every element 
    void display(ostream &out) const {
        for(int i = topIdx; i >= 0; i--) {
            out << data[i] << " ";
        }
        out << "\n";
    }
};

// O(n) - Uses the display method which loops over all elements
ostream &operator << (ostream &out, const DynamicStack &stack) {
    stack.display(out);
    return out;
}
