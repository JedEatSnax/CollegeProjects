# Binary Tree Implementation in C++

## Overview
This project uses templates to demonstrate a generic C++ implementation of a **Binary Tree** in C++. The implementation includes operations for inserting nodes (using level order insertion), deleting nodes (with recursive deletion), searching for a value, and traversing the tree in various orders (inorder, preorder, postorder, and level order). This code is an excellent learning resource for understanding tree data structures and recursion in C++.

## Midterms Analysis
After running the program 5 times, `printMemoryUsage()` shows an average of 3471.2 KBs peak RAM usage. In addition, the program was run 5 times on [JDoodle](https://www.jdoodle.com/online-compiler-c++) and was compiled and executed in an average of 2.048 seconds. Lastly, the worst time complexity of the program is O(n).


## Code Snippet
```cpp
int main() {
    BinaryTree<int> tree;

    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    tree.insertNode(6);

    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "Preorder traversal: ";
    tree.preorder();

    cout << "Postorder traversal: ";
    tree.postorder();

    cout << "Level order traversal: ";
    tree.levelOrder();

    cout << "Searching for 7: " << (tree.search(7) ? "Found" : "Not Found") << endl;
    cout << "Searching for 6: " << (tree.search(6) ? "Found" : "Not Found") << endl;

    tree.deleteNode(3);
    cout << "Inorder traversal after removing 3: ";
    tree.inorder();

    tree.printMemoryUsage();

    return 0;
}
```

## Output
```
Inorder traversal: 4 2 5 1 6 3
Preorder traversal: 1 2 4 5 3 6
Postorder traversal: 4 5 2 6 3 1
Level order traversal: 1 2 3 4 5 6
Searching for 7: Not Found
Searching for 6: Found
Inorder traversal after removing 3: 4 2 5 1 6
Peak RAM used: 3472 KB

Process finished with exit code 0
```

## Data Structures

### Node Class (Template)
The `Node` class represents each node in the binary tree:
- **data**: The value stored in the node (of generic type `T`).
- **left**: Pointer to the left child.
- **right**: Pointer to the right child.

## BinaryTree Class (Template)
The `BinaryTree` class encapsulates the tree operations and maintains a pointer to the root of the node:
- **root**: Pointer to the root node.
- **Destructor** Cleans up the tree by repeatedly deleting nodes.

## Operations and Their Processes

### 1. Insertion

`insertNode(T value)`
Inserts a node in level order. If the tree is empty, the new node becomes the root.

### 2. Deletion

`deleteNode(T value)`
Deletes a node with the specified value using a recursive method. It handles all three cases:
a. Node with no children.
b. Node with no child.
c. Node with two children (using the inorder successor).

### 3. Searching

`search(T value)`
Returns `true` if the value is found in the tree, otherwise it is `false`.

### 4. Traversal Methods
a. `inorder()`
b. `preorder()`
c. `postorder()`
d. `levelOrder()`

## References
Code retrieved from [GeeksforGeeks](https://www.geeksforgeeks.org/binary-tree-in-cpp/) with the help of ChatGPT and Copilot
