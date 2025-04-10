# Stack Operations in C++

## Overview
This project demonstrates the usage of the C++ Standard Library's `std::stack` container.

## Midterms Analysis
After running the program 5 times, `printMemoryUsage()` shows an average of 3472.8 KBs peak RAM usage. In addition, the program was run 5 times on [JDoodle](https://www.jdoodle.com/online-compiler-c++) and was compiled and executed in an average of 1.661 seconds. Lastly, the worst time complexity of the program is O(n).

## Code Snippet
```cpp
int main() {
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    cout << "Size of stack: " << myStack.size() << endl;
    cout << "Top element: " << myStack.top() << endl;

    cout << "Stack elements: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    cout << endl;
    if (myStack.empty() == false) {
        cout << "Stack is not empty" << endl;
    }
    else {
        cout << "Stack is empty" << endl;
    }

    printMemoryUsage();

    return 0;
}
```

## Output
```
Size of stack: 5
Top element: 5
Stack elements: 5 4 3 2 1
Stack is empty
Peak RAM used: 3468 KB

Process finished with exit code 0
```

## Features
- **Stack Insertion:** Adding elements to the queue using `push()`.
- **Stack Deletion:** Removing elements from the queue using `pop()`.
- **Stack Top Element:** Retrieves the top element using `.top()`.
- **Stack Empty Check:** Checks if the stack is empty using `.empty()`.
