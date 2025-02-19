Testing
```cpp
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
```
