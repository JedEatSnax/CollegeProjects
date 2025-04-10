#include <iostream>
#include <stack>
#include <windows.h>
#include <psapi.h>

using namespace std;

void printMemoryUsage() {
    PROCESS_MEMORY_COUNTERS pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    std::cout << "Peak RAM used: " << pmc.PeakWorkingSetSize / 1024 << " KB\n";
}

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
