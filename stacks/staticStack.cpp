#include <iostream>
using namespace std;

// The amount of items the stack can take
const int CAPACITY = 8;

/*
    Problems with the static array stacks
    - They require continuous memory allocation
    - The size is fixed after initialization ( can waste space )
    Solution → Dynamic Array Stack
*/

class StaticStack {
private:
    int data[CAPACITY];
    int topIdx;
public:
    // Constructor
    // O(1)
    StaticStack() {
        topIdx = -1;
    }

    // Check if the stack is empty
    // O(1)
    bool isEmpty() const {
        return topIdx == -1;
    }

    // Add an item to the top of the stack
    // O(1) - Appends a value to the array and increments the topIdx with no iterations
    void push(const int &val) {
        if(topIdx == CAPACITY-1) {
            cerr << "\nStack is full\n";
            return;
        }
        data[++topIdx] = val;
    }

    // Remove the top item from the sack
    // O(1) - Decrements the topIdx only
    void pop() {
        if(isEmpty()) {
            cerr << "\nStack is empty\n";
            return;
        }
        topIdx--;
    }

    // Display the stack using a stream
    // Best case O(1) - If stack is empty therefore the loop never runs
    // Worst case O(n) - If the stack is full therefore it iterates over all elements
    void display(ostream &out) const {
        for(int i = topIdx; i >= 0; i--) {
            out << data[i] << " ";
        }
        out << "\n";
    }

    // Retrieve the top element in the stack
    // O(1) - Returns a value from the array using the index
    int top() const {
        if(isEmpty()) {
            cerr << "\nStack is empty\n";
            return -1;
        } else {
            return data[topIdx];
        }
    }
};

// O(n) - Uses the display method which loops over all elements
ostream &operator << (ostream &out, const StaticStack &stack) {
    stack.display(out);
    return out;
}
