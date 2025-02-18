# Singly Linked List in C++

## Overview
Using an object-oriented approach, this project implements a **singly linked list** in C++. The linked list supports common operations such as inserting and deleting nodes at various positions and displaying the list. A destructor is also implemented to ensure that all dynamically allocated memory is properly released when the list is no longer used.

## Data Structure

### Node Structure
- **Definition:**  
  Each node in the list is defined by the `Node` struct, which contains:
  - `int data`: The data stored in the node.
  - `Node* next`: A pointer to the next node in the list.

### SinglyLinkedList Class
- **Purpose:**  
  The `SinglyLinkedList` class encapsulates the linked list, managing the `head` pointer (which points to the first node) and providing methods for list operations.
- **Key Components:**
  - **Private Member:**
    - `Node* head`: Points to the first node in the list.
  - **Public Methods:**
    - `insertAtBeginning(int value)`: Inserts a node at the beginning.
    - `insertAtEnd(int value)`: Inserts a node at the end.
    - `insertAtPosition(int value, int position)`: Inserts a node at a specified 1-based position.
    - `deleteFromBeginning()`: Deletes the first node.
    - `deleteFromEnd()`: Deletes the last node.
    - `deleteFromPosition(int position)`: Deletes a node from a specified position.
    - `display() const`: Displays the list elements.
  - **Destructor:**
    - `~SinglyLinkedList()`: Cleans up all nodes to prevent memory leaks.

## Operations and Their Processes

### 1. Insertion Operations

#### `insertAtBeginning(int value)`
- **Purpose:**  
  Inserts a new node at the start of the list.
- **Process:**
  1. Create a new node with the given value.
  2. Set the new node's `next` pointer to the current `head`.
  3. Update `head` to point to the new node.

#### `insertAtEnd(int value)`
- **Purpose:**  
  Appends a new node at the end of the list.
- **Process:**
  1. Create a new node with the given value and set its `next` pointer to `nullptr`.
  2. If the list is empty, update `head` to point to the new node.
  3. Otherwise, traverse the last node and update its `next` pointer to the new node.

#### `insertAtPosition(int value, int position)`
- **Purpose:**  
  Inserts a new node at the specified 1-based position.
- **Process:**
  1. Validate that the position is ≥ 1.
  2. If the position is 1, call `insertAtBeginning`.
  3. Otherwise, traverse the list to reach the node just before the target position.
  4. Print an error message if the position is out of range.
  5. Otherwise, adjust pointers to insert the new node.

### 2. Deletion Operations

#### `deleteFromBeginning()`
- **Purpose:**  
  Removes the first node from the list.
- **Process:**
  1. Check if the list is empty.
  2. Update `head` to point to the second node.
  3. Delete the original first node.

#### `deleteFromEnd()`
- **Purpose:**  
  Removes the last node from the list.
- **Process:**
  1. Check if the list is empty.
  2. If there is only one node, delete it and set `head` to `nullptr`.
  3. Otherwise, traverse to the second-to-last node.
  4. Delete the last node and update the second-to-last node's `next` pointer to `nullptr`.

#### `deleteFromPosition(int position)`
- **Purpose:**  
  Deletes a node at a specified 1-based position.
- **Process:**
  1. Validate that the position is ≥ 1.
  2. If the position is 1, call `deleteFromBeginning`.
  3. Otherwise, traverse to the node just before the target node.
  4. Print an error message if the target position is out of range.
  5. Adjust pointers to remove the target node and delete it.

### 3. Display Operation

#### `display() const`
- **Purpose:**  
  Prints the elements of the list.
- **Process:**
  1. Check if the list is empty; print a message.
  2. Otherwise, traverse the list from `head` to `nullptr`, printing each node’s data followed by an arrow (`->`).
  3. End the printed sequence with `NULL`.

### 4. Destructor

#### `~SinglyLinkedList()`
- **Purpose:**  
  Frees all dynamically allocated nodes when the `SinglyLinkedList` object is destroyed, preventing memory leaks.
- **Process:**
  1. Traverse the list starting from `head`.
  2. Store the next pointer for each node, delete the current node, and then move to the next node.
- **Importance:**  
  Ensures proper cleanup of memory, which is crucial for applications that rely on dynamic memory allocation.

## References
Code retrieved from [GeeksforGeeks](https://www.geeksforgeeks.org/cpp-linked-list/) with the help of ChatGPT and Copilot
