#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *next;
    Node(int val) {
        value = val;
        next = 0;
    }
};

class LinkedList {
private:
    Node *head;
    int size;

    void clearList() {
        Node *curr = head;

        while(curr != NULL) {
            // Create a new node containing the next node of the original
            Node *next = curr->next;
            // Delete the current node
            delete curr;
            // Replace the current node with the next node of the original
            curr = next;
        }
    }
public:
    // Constructor
    // O(1)
    LinkedList() {
        head = NULL;
        size = 0;
    }

    // Copy constructor
    // O(n) - Iterates over every node
    LinkedList(const LinkedList &original) {
        head = NULL;
        size = original.size;
        if(size == 0) return;

        // Head of the original list
        Node *originalPtr = original.head;
        // Keep track of the last created node
        Node *lastPtr = NULL;

        while(originalPtr != NULL) {
            // Create a new node with the value of the current original pointer value
            Node *newNode = new Node(originalPtr->value);
            // Check if there is no last created pointer ( first iteration ) we set the head to the newly created node
            if(lastPtr == NULL) head = newNode;
            // Else we append the newly created node to it
            else lastPtr->next = newNode;
            // Set the last created pointer to the one we just created
            lastPtr = newNode;
            // Move the original pointer up a node
            originalPtr = originalPtr->next;
        }
    }

    // Destructor for when the list goes out of scope
    // O(n) - calls the clearList method which iterates over every node
    ~LinkedList() {
        clearList();
        head = NULL;
        size = 0;
    }

    // Assignment operator, used so the whole list is copied instead of the address
    // eg: myList = otherList
    // Best case O(1) - They are the same object therefore it's returned
    // Worst case O(n) - different objects therefore all old nodes are deleted then we copy all new ones
    const LinkedList &operator=(const LinkedList &original) {
        if(this == &original) return *this;
        
        clearList();
        head = NULL;
        size = original.size;

        if(size == 0) return *this;

        head = NULL;

        Node *curr = original.head;
        Node *last = NULL;
        while(curr != NULL) {
            Node *newNode = new Node(curr->value);

            if(last == NULL) head = newNode;
            else last->next = newNode;

            curr = curr->next;
            last = newNode;
        }

        return *this;
    }

    // Check if the list is empty
    // O(1)
    bool isEmpty() {
        return size == 0;
    }

    // Insert an item at a given position
    // Best case O(1) - Inserting at the beginning therefore we don't need to iterate over the list
    // Worst case O(n) - Inserting at the end therefore we need to iterate over all nodes to reach the end
    void insert(int val, int pos) {
        if(pos < 0 || pos > size) {
            cerr << "\nInvalid position\n";
            return;
        }

        Node *newNode = new Node(val);
        // If the position is 0 we make the newly created node's next point to the current head
        // and the current head is now the newly created node
        if(pos == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node *prev = head;
            int i = 0;
            // Loop over the list until we reach pos-1
            while(i != pos-1) {
                prev = prev->next;
                i++;
            }
            // Make the newly created node's next point to the previous's next
            newNode->next = prev->next;
            // Mkae the previous' next point to the newly created node
            prev->next = newNode;
        }
        size++;
    }

    // Remove a value from the list
    // Best case O(1) - Deleting the head
    // Worst case O(n) - Deleting from the end therefore we need to iterate over all nodes
    void erase(int pos) {
        if(pos < 0 || pos >= size) {
            cerr << "\nInvalid position\n";
            return;
        }

        if(pos == 0) {
            Node *temp = head;
            head = head->next;
            delete temp;
        } else {
            int i = 0;
            Node *prev = head;
            // Loop until we reach pos-1
            while(i != pos-1) {
                prev = prev->next;
                i++;
            }
            // Make a temporary node that points to pos, which we want to delete
            Node *temp = prev->next;
            // Make the previous point to the prev which is at pos-1
            prev->next = temp->next;
            // Delete the temporary node from memory
            delete temp;
        }
        size--;
    }

    // Clear the list
    // O(n) - We iterate over every node
    void clear() {
        clearList();
        head = NULL;
        size = 0;
    }

    // Search for the index of a specific value in the linked list
    // Best case O(1) - If the value is at position 0
    // Worst case O(n) - If the value is the last node therefore we iterate over every node
    int search(int val) {
        int idx = 0;
        Node *ptr = head;
        for(int i = 0; i < size; i++) {
            if(ptr->value == val) return i;
            else ptr = ptr->next;
        }
        return -1;
    }

    // Display the list using a stream
    // O(n) - We iterate over every node
    void display(ostream &out) const {
        Node *ptr = head;
        while(ptr != NULL) {
            out << ptr->value << " ";
            ptr = ptr->next;
        }
    }

    // Returns the number of nodes / items in a linked list
    // O(1)
    int nodeCount() {
        return size;
    }

    // Reverse the order of the linked list
    // O(n) - We iterate over every node
    void reverse() {
        // NULL    [1] → [2] → [3] → [4] → NULL
        // NULL ← [1]   [2] → [3] → [4] → NULL
        // NULL ← [1] ← [2]   [3] → [4] → NULL
        // NULL ← [1] ← [2] ← [3]   [4] → NULL
        // NULL ← [1] ← [2] ← [3] ← [4]
        Node *prev = NULL, *curr = head, *next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    // Checks if the list is in ascending order
    // Best case O(1) - If the size is <= 1 we immediately return
    // Worst case O(n) - Must iterate over every node to check
    bool inAscendingOrder() {
        if(size <= 1) return true;
        Node *prev = head,
             *next = head->next;

        while(next != NULL) {
            if(prev->value > next->value) return false;
            prev = next;
            next = next->next;
        }

        return true;
    }
};

// O(n) - Uses the display method which loops over all elements
ostream &operator << (ostream &out, const LinkedList &list) {
    list.display(out);
    return out;
}
