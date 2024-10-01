#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList list;

    // Inserting elements
    list.insert(5);  // 5
    list.display();

    list.insert(2);  // 2 5
    list.display();

    list.insert(7);  // 2 5 7
    list.display();

    list.insert(3);  // 2 3 5 7
    list.display();

    list.insert(1);  // 1 2 3 5 7
    list.display();

    return 0;
}
