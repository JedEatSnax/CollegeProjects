#include <iostream>
#include <stack>
using namespace std;

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
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
