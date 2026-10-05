#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

void insertBegin(Node*& head, Node*& tail, int x) {
    Node* n = new Node(x);

    if (head == nullptr) {
        head = tail = n;
        return;
    }

    n->next = head;
    head->prev = n;
    head = n;
}

void insertEnd(Node*& head, Node*& tail, int x) {
    Node* n = new Node(x);

    if (head == nullptr) {
        head = tail = n;
        return;
    }

    tail->next = n;
    n->prev = tail;
    tail = n;
}

void insertAfter(Node* head, Node*& tail, int x, int value) {
    Node* temp = head;

    while (temp != nullptr && temp->data != x) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Song not found\n";
        return;
    }

    Node* n = new Node(value);
    n->next = temp->next;
    n->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = n;
    } else {
        tail = n;
    }

    temp->next = n;
}

void deleteNode(Node*& head, Node*& tail, int x) {
    Node* temp = head;

    while (temp != nullptr && temp->data != x) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Song not found\n";
        return;
    }

    if (temp->prev) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;
    }

    delete temp;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    insertBegin(head, tail, 10);
    insertEnd(head, tail, 20);
    insertEnd(head, tail, 40);
    insertAfter(head, tail, 20, 30);

    cout << "Playlist: ";
    display(head);

    deleteNode(head, tail, 20);

    cout << "\nAfter deletion: ";
    display(head);
    cout << endl;

    return 0;
}   