#ifndef STACK_H
#define STACK_H

/**
 * @brief Node class to represent each element in the stack.
 */
class Node {
public:
    int data;        ///< Data to store the integer value.
    Node* next;      ///< Pointer to the next node in the stack.

    /**
     * @brief Constructor to initialize node with data.
     * @param val Integer value to be stored in the node.
     */
    Node(int val) : data(val), next(nullptr) {}
};

/**
 * @brief Stack class implemented using a linked list.
 */
class Stack {
private:
    Node* top;       ///< Pointer to the top node of the stack.

public:
    /**
     * @brief Constructor to initialize an empty stack.
     */
    Stack() : top(nullptr) {}

    /**
     * @brief Destructor to free the memory allocated for the stack.
     */
    ~Stack();

    /**
     * @brief Push a new value onto the stack.
     * @param value Integer value to be added to the stack.
     */
    void push(int value);

    /**
     * @brief Pop the top value from the stack.
     * @return The integer value removed from the stack.
     * @throw std::runtime_error if the stack is empty.
     */
    int pop();

    /**
     * @brief Check if the stack is empty.
     * @return True if the stack is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Get the top value of the stack without removing it.
     * @return The integer value at the top of the stack.
     * @throw std::runtime_error if the stack is empty.
     */
    int peek() const;
};

#endif // STACK_H
