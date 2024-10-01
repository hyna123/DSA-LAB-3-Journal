#include "LinkedList.h"
#include <iostream>
using namespace std;

// Node constructor to initialize node with data
Node::Node(int val) {
    data = val;
    next = nullptr;
}

// LinkedList constructor to initialize an empty list
LinkedList::LinkedList() {
    head = nullptr;
}

// LinkedList destructor to clean up the memory
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Function to insert a new value into the list in ascending order
void LinkedList::insert(int value) {
    Node* newNode = new Node(value);

    // If the list is empty or the new value is smaller than the head value
    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } 
    else {
        // Find the correct position to insert the new node
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        // Insert the new node in its correct position
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to display the list
void LinkedList::display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
