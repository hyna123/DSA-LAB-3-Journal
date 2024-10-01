#include <iostream>
using namespace std;

/**
 * @brief Node class to represent each element in the linked list.
 */
class Node {
public:
    char data;       ///< Data to store the character.
    Node* next;      ///< Pointer to the next node in the list.

    /**
     * @brief Constructor to initialize node with data.
     * @param val Character value to be stored in the node.
     */
    Node(char val) {
        data = val;
        next = nullptr;
    }
};

/**
 * @brief LinkedList class to manage a singly linked list.
 */
class LinkedList {
public:
    Node* head;      ///< Pointer to the head (first node) of the list.

    /**
     * @brief Constructor to initialize an empty list.
     */
    LinkedList() {
        head = nullptr; // Set head to null for an empty list.
    }

    /**
     * @brief Destructor to clean up all the nodes and free memory.
     */
    ~LinkedList() {
        Node* current = head; // Start from the head node.
        while (current != nullptr) {
            Node* next = current->next; // Store next node before deleting.
            delete current;             // Delete the current node.
            current = next;             // Move to the next node.
        }
    }

    /**
     * @brief Function to insert a character at the end of the list.
     * @param value Character value to be inserted.
     */
    void insert(char value) {
        Node* newNode = new Node(value); // Create a new node with the given value.

        if (head == nullptr) {
            head = newNode; // If the list is empty, set the new node as the head.
        } else {
            Node* current = head;
            // Traverse the list to find the last node.
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode; // Append the new node at the end.
        }
    }

    /**
     * @brief Function to display the list (for testing purposes).
     */
    void display() const {
        Node* current = head; // Start from the head node.
        while (current != nullptr) {
            cout << current->data; // Print the data of each node.
            current = current->next; // Move to the next node.
        }
        cout << endl; // Newline for readability after displaying the list.
    }
};

/**
 * @brief Stand-alone function to concatenate two lists.
 * @param list1 First linked list.
 * @param list2 Second linked list.
 * @return A new linked list containing elements from both input lists.
 */
LinkedList concatenate(const LinkedList& list1, const LinkedList& list2) {
    LinkedList result; // Create a new list to store the concatenated result.

    // Copy elements from list1.
    Node* current = list1.head;
    while (current != nullptr) {
        result.insert(current->data); // Insert each element from list1 into the result.
        current = current->next;
    }

    // Copy elements from list2.
    current = list2.head;
    while (current != nullptr) {
        result.insert(current->data); // Insert each element from list2 into the result.
        current = current->next;
    }

    return result; // Return the concatenated list.
}

/**
 * @brief Stand-alone function to find the intersection of two lists.
 * @param list1 First linked list.
 * @param list2 Second linked list.
 * @return A new linked list containing elements that are common in both input lists.
 */
LinkedList intersection(const LinkedList& list1, const LinkedList& list2) {
    LinkedList result; // Create a new list to store the intersection.

    // Compare elements of list1 with list2.
    Node* current1 = list1.head;
    while (current1 != nullptr) {
        Node* current2 = list2.head;
        while (current2 != nullptr) {
            if (current1->data == current2->data) {
                // Check if the current1's data is already in the result list.
                Node* currentRes = result.head;
                bool alreadyExists = false;
                while (currentRes != nullptr) {
                    if (currentRes->data == current1->data) {
                        alreadyExists = true; // Found the same element in the result.
                        break;
                    }
                    currentRes = currentRes->next;
                }
                if (!alreadyExists) {
                    result.insert(current1->data); // Insert the data into result if not already present.
                }
                break; // Stop checking current2 since we found a match.
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }

    return result; // Return the intersection list.
}

/**
 * @brief Stand-alone function to compare two lists lexicographically.
 * @param list1 First linked list.
 * @param list2 Second linked list.
 * @return 0 if both lists are equal, 1 if the first list is greater, -1 if the second list is greater.
 */
int compare(const LinkedList& list1, const LinkedList& list2) {
    Node* current1 = list1.head;
    Node* current2 = list2.head;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->data < current2->data) {
            return -1; // First list is lexicographically smaller.
        }
        else if (current1->data > current2->data) {
            return 1;  // First list is lexicographically greater.
        }
        current1 = current1->next; // Move to the next node in the first list.
        current2 = current2->next; // Move to the next node in the second list.
    }

    // If both lists have been traversed and are of the same length.
    if (current1 == nullptr && current2 == nullptr) {
        return 0;  // Both lists are equal.
    }
    else if (current1 == nullptr) {
        return -1; // First list is shorter, thus lexicographically smaller.
    }
    else {
        return 1;  // Second list is shorter, thus lexicographically smaller.
    }
}

/**
 * @brief Main function to test the above implementations.
 */
int main() {
    LinkedList list1; // Create the first linked list.
    LinkedList list2; // Create the second linked list.

    // Insert characters into list 1.
    list1.insert('a');
    list1.insert('b');
    list1.insert('c');

    // Insert characters into list 2.
    list2.insert('b');
    list2.insert('c');
    list2.insert('d');

    // Display both lists.
    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();

    // Concatenate the two lists.
    LinkedList concatenatedList = concatenate(list1, list2);
    cout << "Concatenated List: ";
    concatenatedList.display();

    // Find the intersection of the two lists.
    LinkedList intersectedList = intersection(list1, list2);
    cout << "Intersection of Lists: ";
    intersectedList.display();

    // Compare the two lists lexicographically.
    int comparisonResult = compare(list1, list2);
    if (comparisonResult == 0) {
        cout << "The two lists are lexicographically equal." << endl;
    } else if (comparisonResult == 1) {
        cout << "List 1 is lexicographically greater." << endl;
    } else {
        cout << "List 2 is lexicographically greater." << endl;
    }

    return 0; // Return 0 to indicate successful execution.
}
