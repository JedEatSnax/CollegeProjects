#include <iostream>
#include <queue>
#include <windows.h>
#include <psapi.h>

using namespace std;

void showQueue(queue<int> myQueue) {
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;
}

void printMemoryUsage() {
    PROCESS_MEMORY_COUNTERS pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    std::cout << "Peak RAM used: " << pmc.PeakWorkingSetSize / 1024 << " KB\n";
}

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

    printMemoryUsage();

    return 0;
}
