#include <iostream>
using namespace std;

template <typename T> class Node {
public:
    T data;
    Node<T>* next;

    explicit Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T> class CircularLinkedList {
private:
    Node<T>* head;

public:
    CircularLinkedList() { head = nullptr; }

    ~CircularLinkedList() {
        if (head != nullptr) {
            Node<T>* temp = head;
            do {
                Node<T>* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            } while (temp != head);
        }
    }

    void insertAtFirst(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAtPosition(T value, int position)
    {
        if (position <= 1 || head == nullptr) {
            insertAtFirst(value);
        }
        else {
            Node<T>* newNode = new Node<T>(value);
            Node<T>* temp = head;
            for (int i = 1; i < position - 1 && temp->next != head; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteFromFirst()
    {
        if (head == nullptr)
            return;
        if (head->next == head) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Node<T>* tempHead = head;
            temp->next = head->next;
            head = head->next;
            delete tempHead;
        }
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
            return;
        if (head->next == head) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* temp = head;
            Node<T>* prev = nullptr;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
    }

    void deleteByKey(T key)
    {
        if (head == nullptr)
            return;
        if (head->data == key) {
            deleteFromFirst();
            return;
        }
        Node<T>* temp = head;
        Node<T>* prev = nullptr;
        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != key);

        if (temp->data == key) {
            prev->next = temp->next;
            delete temp;
        }
    }

    void display()
    {
        if (head == nullptr)
            return;
        Node<T>* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }
};

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
