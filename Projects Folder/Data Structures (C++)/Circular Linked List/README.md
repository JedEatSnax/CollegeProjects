# Circular Linked List in C++

## Overview
This project demonstrates a generic implementation of a **Circular Linked List** in C++ using templates. The implementation supports common operations such as insertion, deletion, and display of the list. The list is circular, meaning the last node points back to the head, and is designed to handle different data types through C++ templates.

## Code Snippet
```cpp
int main()
{
    CircularLinkedList<int> cll;

    cout << "Circular linked list after inserting node at the beginning:" << endl;
    cll.insertAtFirst(10);
    cll.display();

    cout << "Circular linked list after inserting 20,30,40,50 at the end:" << endl;
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    cll.insertAtEnd(50);
    cll.display();

    cout << "Circular linked list after inserting 15 at position 2:" << endl;
    cll.insertAtPosition(15, 2);
    cll.display();

    cout << "Circular linked list after deleting the first node:" << endl;
    cll.deleteFromFirst();
    cll.display();

    cout << "Circular linked list after deleting the last node:" << endl;
    cll.deleteFromEnd();
    cll.display();

    cout << "Circular linked list after deleting node with key 30:" << endl;
    cll.deleteByKey(30);
    cll.display();

    return 0;
}
```

## Output
```
Circular linked list after inserting 15 at position 2:
10 -> 15 -> 20 -> 30 -> 40 -> 50 -> HEAD
Circular linked list after deleting the first node:
15 -> 20 -> 30 -> 40 -> 50 -> HEAD
Circular linked list after deleting the last node:
15 -> 20 -> 30 -> 40 -> HEAD
Circular linked list after deleting node with key 30:
15 -> 20 -> 40 -> HEAD

Process finished with exit code 0
```

## Data Structures

### Node Class (Template)
The `Node` class represents each node in the circular linked list:
- **data**: The value stored in the node (generic type `T`).
- **next**: A pointer to the next node in the list.


### CircularLinkedList Class (Template)
The `CircularLinkedList` class encapsulates all the operations on the circular linked list:
- **head**: A pointer to the first node in the list.
- **Destructor**: Iterates through the list and frees allocated memory.

## Operations and Their Processes

### 1. Insertion Operations

#### `insertAtFirst(T value):`
- Inserts a new node at the beginning of the list.

#### `insertAtEnd(T value):`
- Appends a new node at the end of the list.

#### `insertAtPosition(T value, int position):`
- Inserts a new node at the specified 1-based position. If the position is less than or equal to 1 or the list is empty, it defaults to inserting at the beginning.

### 2. Deletion Operations

#### `deleteFromFirst():`
- Removes the first node in the list and updates the head pointer accordingly.

#### `deleteFromEnd():`
- Deletes the last node in the list.

#### `deleteByKey(T key):`
- Deletes the node that contains the specified key (value).

### 3. Display Operation

#### `display():`
- Traverses the list and prints the data of each node in order, ending with a marker indicating the list is circular (i.e., HEAD).

## References
Code retrieved from [GeeksforGeeks](https://www.geeksforgeeks.org/circular-linked-list-in-cpp/) with the help of ChatGPT and Copilot
