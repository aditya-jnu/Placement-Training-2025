#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Insert at beginning
void insertAtHead(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Insert at end
void insertAtEnd(Node*& head, int d) {
    Node* temp = new Node(d);
    if (!head) {
        head = temp;
        return;
    }
    Node* curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = temp;
}

// Insert at any index (0-based)
void insertAtIndex(Node*& head, int d, int index) {
    if (index == 0) {
        insertAtHead(head, d);
        return;
    }
    Node* temp = new Node(d);
    Node* curr = head;
    for (int i = 0; curr != nullptr && i < index - 1; i++) {
        curr = curr->next;
    }
    if (!curr) return; // Invalid index
    temp->next = curr->next;
    curr->next = temp;
}

// Delete at beginning
void deleteAtHead(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete at end
void deleteAtEnd(Node*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* curr = head;
    while (curr->next->next) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
}

// Delete at index (0-based)
void deleteAtIndex(Node*& head, int index) {
    if (index == 0) {
        deleteAtHead(head);
        return;
    }
    Node* curr = head;
    for (int i = 0; curr && i < index - 1; i++) {
        curr = curr->next;
    }
    if (!curr || !curr->next) return;
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}

// Delete first occurrence of node with given value
void deleteByValue(Node*& head, int val) {
    if (!head) return;
    if (head->data == val) {
        deleteAtHead(head);
        return;
    }
    Node* curr = head;
    while (curr->next && curr->next->data != val) {
        curr = curr->next;
    }
    if (curr->next) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
}

// Test cases
int main() {
    Node* head = nullptr;

    cout << "\n--- Insert at Head ---\n";
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    printList(head); // 20 -> 10 -> NULL

    cout << "\n--- Insert at End ---\n";
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    printList(head); // 20 -> 10 -> 30 -> 40 -> NULL

    cout << "\n--- Insert at Index ---\n";
    insertAtIndex(head, 25, 2);
    insertAtIndex(head, 15, 1);
    printList(head); // 20 -> 15 -> 10 -> 25 -> 30 -> 40 -> NULL

    cout << "\n--- Delete at Head ---\n";
    deleteAtHead(head);
    printList(head); // 15 -> 10 -> 25 -> 30 -> 40 -> NULL
    deleteAtHead(head);
    printList(head); // 10 -> 25 -> 30 -> 40 -> NULL

    cout << "\n--- Delete at End ---\n";
    deleteAtEnd(head);
    printList(head); // 10 -> 25 -> 30 -> NULL
    deleteAtEnd(head);
    printList(head); // 10 -> 25 -> NULL

    cout << "\n--- Delete at Index ---\n";
    deleteAtIndex(head, 1);
    printList(head); // 10 -> NULL
    deleteAtIndex(head, 0);
    printList(head); // NULL

    cout << "\n--- Delete by Value ---\n";
    insertAtEnd(head, 5);
    insertAtEnd(head, 15);
    insertAtEnd(head, 25);
    insertAtEnd(head, 15);
    printList(head); // 5 -> 15 -> 25 -> 15 -> NULL
    deleteByValue(head, 15);
    printList(head); // 5 -> 25 -> 15 -> NULL
    deleteByValue(head, 5);
    printList(head); // 25 -> 15 -> NULL

    return 0;
}
