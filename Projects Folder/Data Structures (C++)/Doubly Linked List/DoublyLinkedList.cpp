#include <iostream>
#include <windows.h>
#include <psapi.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    explicit Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

void insertAtBeginning(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node*& head, int data, int position) {
    if (position < 1) {
        cout << "Position should be >= 1." << endl;
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    Node* newNode = new Node(data);
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position greater than the number of nodes." << endl;
        delete newNode; // Prevent memory leak
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "The list is already empty." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "The list is already empty." << endl;
        return;
    }
    Node* temp = head;
    if (temp->next == nullptr) {
        head = nullptr;
        delete temp;
        return;
    }
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
}

void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "The list is already empty." << endl;
        return;
    }
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position is greater than the number of nodes." << endl;
        return;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    delete temp;
}

void printListForward(Node* head) {
    Node* temp = head;
    cout << "Forward List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printListReverse(Node* head) {
    Node* temp = head;
    if (temp == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    cout << "Reverse List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void printMemoryUsage() {
    PROCESS_MEMORY_COUNTERS pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    std::cout << "Peak RAM used: " << pmc.PeakWorkingSetSize / 1024 << " KB\n";
}

int main() {
    Node* head = nullptr;

    // Insertion Operations
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtBeginning(head, 5);
    insertAtPosition(head, 15, 2);

    cout << "After Insertions:" << endl;
    printListForward(head);
    printListReverse(head);

    // Deletion Operations
    deleteAtBeginning(head);
    deleteAtEnd(head);
    deleteAtPosition(head, 2);

    cout << "After Deletions:" << endl;
    printListForward(head);

    printMemoryUsage();

    return 0;
}
