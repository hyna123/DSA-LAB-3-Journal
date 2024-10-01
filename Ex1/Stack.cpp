#include <iostream>
#include <stdexcept>
#include "stack.h"

using namespace std;

Stack::~Stack() {
    while (!isEmpty()) {
        pop(); // Free all nodes in the stack.
    }
}

void Stack::push(int value) {
    Node* newNode = new Node(value); // Create a new node with the value.
    newNode->next = top;             // Point new node to the current top.
    top = newNode;                   // Update top to the new node.
}

int Stack::pop() {
    if (isEmpty()) {
        throw runtime_error("Stack is empty. Cannot pop."); // Handle underflow.
    }
    Node* temp = top;            // Temporarily store the top node.
    int poppedValue = temp->data; // Store the value to return.
    top = top->next;             // Move top to the next node.
    delete temp;                 // Free memory of the popped node.
    return poppedValue;          // Return the popped value.
}

bool Stack::isEmpty() const {
    return top == nullptr; // Stack is empty if top is null.
}

int Stack::peek() const {
    if (isEmpty()) {
        throw runtime_error("Stack is empty. Cannot peek."); // Handle empty stack.
    }
    return top->data; // Return the data of the top node.
}
