# Queue Operations in C++

## Overview
This project demonstrates using the C++ Standard Library `std::queue` container. The program illustrates basic queue operations such as insertion, deletion, swapping, and displaying the contents of a queue. It uses a helper function to print the queue's contents without modifying the original queue.

## Code Snippet
```cpp
int main() {
    queue<int> myQueue;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    myQueue.push(50);

    queue<int> myQueue2;
    myQueue2.push(100);
    myQueue2.push(200);
    myQueue2.push(300);

    cout << "Initial myQueue: ";
    showQueue(myQueue);

    cout << "myQueue size: " << myQueue.size() << endl;
    cout << "myQueue front: " << myQueue.front() << endl;
    cout << "myQueue back: " << myQueue.back() << endl;

    myQueue.swap(myQueue2);
    cout << "After swapping the contents of myQueue and myQueue2:" << endl;
    cout << "myQueue front: " << myQueue.front() << endl;
    cout << "myQueue2 front: " << myQueue2.front() << endl;

    myQueue.pop();
    cout << "After popping the front element from myQueue, it is now: ";
    showQueue(myQueue);

    return 0;
}
```

## Output
```
Initial myQueue: 10 20 30 40 50
myQueue size: 5
myQueue front: 10
myQueue back: 50
After swapping the contents of myQueue and myQueue2:
myQueue front: 100
myQueue2 front: 10
After popping the front element from myQueue, it is now: 200 300

Process finished with exit code 0
```

## Features
- **Queue Insertion:** Adding elements to the queue using `push()`.
- **Queue Deletion:** Removing elements from the queue using `pop()`.
- **Queue Information:** Displaying the size, front, and back elements.
- **Swapping Queues:** Exchanging the contents of two queues using `swap()`.
- **Queue Display:** A custom function `showQueue()` that prints the entire queue.

## References
Code retrieved from [GeeksforGeeks](https://www.geeksforgeeks.org/queue-cpp-stl/) with the help of ChatGPT and Copilot
