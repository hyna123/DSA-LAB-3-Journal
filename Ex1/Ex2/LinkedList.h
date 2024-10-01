#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Node class to represent each element in the linked list
class Node {
public:
    int data;    // To store the value
    Node* next;  // Pointer to the next node

    // Constructor to initialize node with data
    Node(int val);
};

// LinkedList class
class LinkedList {
private:
    Node* head;  // Pointer to the first node in the list

public:
    // Constructor to initialize an empty list
    LinkedList();

    // Destructor to clean up the memory
    ~LinkedList();

    // Function to insert a new value into the list in ascending order
    void insert(int value);

    // Function to display the list
    void display();
};

#endif
