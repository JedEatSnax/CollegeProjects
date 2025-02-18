# Doubly Linked List in C++

## Overview
This project implements a **doubly linked list** in C++. It supports operations such as inserting and deleting nodes at different positions, as well as displaying the list in both forward and reverse directions.

## Data Structure

### Node Structure
- **Definition:**  
  Each node in the list is defined by the `Node` class, which contains:
  - `int data`: The data stored in the node.
  - `Node* next`: A pointer to the next node in the list.
  - `Node* prev`: A pointer to the previous node in the list.

### Functions
- **Purpose:**  
  Functions are provided to manipulate the doubly linked list, including insertion, deletion, and traversal operations.
- **Key Functions:**
  - **Insertion:**
    - `void insertAtBeginning(Node*& head, int data)`: Inserts a node at the beginning of the list.
    - `void insertAtEnd(Node*& head, int data)`: Inserts a node at the end of the list.
    - `void insertAtPosition(Node*& head, int data, int position)`: Inserts a node at a specified 1-based position.
  - **Deletion:**
    - `void deleteAtBeginning(Node*& head)`: Deletes the first node in the list.
    - `void deleteAtEnd(Node*& head)`: Deletes the last node in the list.
    - `void deleteAtPosition(Node*& head, int position)`: Deletes a node from a specified position.
  - **Traversal:**
    - `void printListForward(Node* head)`: Prints the list elements in a forward direction.
    - `void printListReverse(Node* head)`: Prints the list elements in a reverse direction.

## Operations and Their Processes

### 1. Insertion Operations

#### `void insertAtBeginning(Node*& head, int data)`
- **Purpose:**  
  Inserts a new node at the start of the list.
- **Process:**
  1. Create a new node with the given value.
  2. Set the new node's `next` pointer to the current `head`.
  3. If the list is not empty, set the current `head`'s `prev` pointer to the new node.
  4. Update `head` to point to the new node.

#### `void insertAtEnd(Node*& head, int data)`
- **Purpose:**  
  Appends a new node at the end of the list.
- **Process:**
  1. Create a new node with the given value.
  2. If the list is empty, update `head` to point to the new node.
  3. Otherwise, traverse to the last node and update its `next` pointer to the new node.
  4. Set the new node's `prev` pointer to the last node.

#### `void insertAtPosition(Node*& head, int data, int position)`
- **Purpose:**  
  Inserts a new node at the specified 1-based position.
- **Process:**
  1. Validate that the position is ≥ 1.
  2. If the position is 1, call `insertAtBeginning`.
  3. Otherwise, traverse the list to reach the node just before the target position.
  4. Print an error message if the position is out of range.
  5. Otherwise, adjust pointers to insert the new node.

### 2. Deletion Operations

#### `void deleteAtBeginning(Node*& head)`
- **Purpose:**  
  Removes the first node from the list.
- **Process:**
  1. Check if the list is empty.
  2. Update `head` to point to the second node.
  3. If the list is not empty, set the second node's `prev` pointer to `nullptr`.
  4. Delete the original first node.

#### `void deleteAtEnd(Node*& head)`
- **Purpose:**  
  Removes the last node from the list.
- **Process:**
  1. Check if the list is empty.
  2. If there is only one node, delete it and set `head` to `nullptr`.
  3. Otherwise, traverse to the second-to-last node.
  4. Delete the last node and update the second-to-last node's `next` pointer to `nullptr`.

#### `void deleteAtPosition(Node*& head, int position)`
- **Purpose:**  
  Deletes a node at a specified 1-based position.
- **Process:**
  1. Validate that the position is ≥ 1.
  2. If the position is 1, call `deleteAtBeginning`.
  3. Otherwise, traverse to the node just before the target node.
  4. Print an error message if the target position is out of range.
  5. Adjust pointers to remove the target node and delete it.

### 3. Traversal Operations

#### `void printListForward(Node* head)`
- **Purpose:**  
  Prints the elements of the list in the forward direction.
- **Process:**
  1. Check if the list is empty; print a message.
  2. Otherwise, traverse the list from `head` to `nullptr`, printing each node’s data followed by a space.
  3. End the printed sequence with a new line.

#### `void printListReverse(Node* head)`
- **Purpose:**  
  Prints the elements of the list in a reverse direction.
- **Process:**
  1. Traverse to the last node of the list.
  2. Check if the list is empty; print a message.
  3. Otherwise, traverse the list from the last node to `head`, printing each node’s data followed by a space.
  4. End the printed sequence with a new line.


## References
Code retrieved from [GeekforGeeks](https://www.geeksforgeeks.org/doubly-linked-list-in-cpp/?ref=ml_lbp) with the help of ChatGPT and Copilot
