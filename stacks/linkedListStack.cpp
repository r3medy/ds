#include <iostream>
#include "../lists/linkedList.cpp";
using namespace std;

class LinkedListStack {
private:
    // Same as head
    Node *top;

    void clearStack() {
        Node *curr = top;
        while(curr != NULL) {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
        top = NULL;
    }
public:
    // Constructor
    // O(1)
    LinkedListStack() {
        top = NULL;
    }

    // Copy constructor
    // Best case O(1) - The original stack is empty therefore returns immediately
    // Worst case O(n) - The original isn't empty therefore we iterate over all nodes to copy
    LinkedListStack(const LinkedListStack &original) {
        top = NULL;
        if(original.isEmpty()) return;

        Node *originalPtr = original.top,
             *lastPtr     = NULL;
        
        while(originalPtr != NULL) {
            Node *newNode = new Node(originalPtr->value);
            if(lastPtr == NULL) top = newNode;
            else lastPtr->next = newNode;

            lastPtr = newNode;
            originalPtr = originalPtr->next;
        }
    }

    // Destructor
    // Best case O(1) - If stack is already empty
    // Worst case O(n) - If stack isn't empty therefore it iterates over every node to delete
    ~LinkedListStack() {
        clearStack();
    }

    // Assignment operator, used so the whole stack is copied instead of the address
    // Best case O(1) - If they are the same object therefore it returns immediately
    // Worst case O(n) - If they are different objects therefore it iterates over every node to copy
    const LinkedListStack &operator = (const LinkedListStack &original) {
        if(this == &original) return *this;
        clearStack();
        if(!original.isEmpty()) {
            Node *originalPtr = original.top,
                 *lastPtr     = NULL;
        
            while(originalPtr != NULL) {
                Node *newNode = new Node(originalPtr->value);
                if(lastPtr == NULL) top = newNode;
                else lastPtr->next = newNode;

                lastPtr = newNode;
                originalPtr = originalPtr->next;
            }
        }
        return *this;
    }

    // Check if the stack is empty
    // O(1)
    bool isEmpty() const {
        return top == NULL;
    }

    // Add an item to the top of the stack
    // O(1)
    void push(const int &val) {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    // Remove the top item from the sack
    // O(1)
    void pop() {
        if(isEmpty()) return;
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    // Retrieve the top element in the stack
    // O(1)
    int topValue() const {
        if(isEmpty()) {
            cout << "\nStack is empty\n";
            return -1;
        }
        return top->value;
    }

    // Clears the stack
    // Best case O(1) - If stack is already empty
    // Worst case O(n) - If stack isn't empty therefore it iterates over every node to delete
    void clear() {
        clearStack();
    }

    // Display the stack using a stream
    // Best case O(1) - If stack is empty therefore the loop never runs
    // Worst case O(n) - If stack isn't empty therefore it iterates over every node
    void display(ostream &out) const {
        Node *curr = top;
        while(curr != NULL) {
            out << curr->value << " ";
            curr = curr->next;
        }
        out << "\n";
    }
};

// O(n) - Uses the display method which iterates over all elements
ostream &operator << (ostream & out, const LinkedListStack & stack) {
    stack.display(out);
    return out;
}
