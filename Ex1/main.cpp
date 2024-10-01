#include <iostream>
#include "stack.h"

using namespace std;

/**
 * @brief Main function to demonstrate the stack operations.
 */
int main() {
    Stack stack; // Create a stack object.

    // Push elements onto the stack.
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl; // Display the top element.

    // Pop elements from the stack and display them.
    cout << "Popped element: " << stack.pop() << endl; // Pop the top element.
    cout << "Popped element: " << stack.pop() << endl; // Pop the next element.

    // Display the top element after popping.
    cout << "Top element after popping: " << stack.peek() << endl;

    // Pop the last element.
    stack.pop();

    // Check if the stack is empty.
    if (stack.isEmpty()) {
        cout << "Stack is empty." << endl;
    }

    return 0; // Return 0 to indicate successful execution.
}
