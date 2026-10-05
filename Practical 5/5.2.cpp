#include <iostream>
using namespace std;

struct SNode {
    int data;
    SNode* next;
};

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

void insertS(SNode*& head, int x, int pos) {
    SNode* n = new SNode{x, nullptr};

    if (head == nullptr) {
        head = n;
        n->next = head;
        return;
    }

    if (pos == 1) {
        SNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        n->next = head;
        temp->next = n;
        head = n;
        return;
    }

    SNode* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    n->next = temp->next;
    temp->next = n;
}

void deleteS(SNode*& head, int x) {
    if (head == nullptr) {
        return;
    }

    if (head->data == x) {
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        SNode* last = head;
        while (last->next != head) {
            last = last->next;
        }

        SNode* temp = head;
        head = head->next;
        last->next = head;
        delete temp;
        return;
    }

    SNode* temp = head;
    while (temp->next != head && temp->next->data != x) {
        temp = temp->next;
    }

    if (temp->next != head) {
        SNode* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

void displayS(SNode* head) {
    if (head == nullptr) {
        cout << "Empty\n";
        return;
    }

    SNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << "\n";
}

void insertD(DNode*& head, int x, int pos) {
    DNode* n = new DNode{x, nullptr, nullptr};

    if (head == nullptr) {
        head = n;
        n->next = head;
        n->prev = head;
        return;
    }

    if (pos == 1) {
        DNode* last = head->prev;

        n->next = head;
        n->prev = last;
        last->next = n;
        head->prev = n;
        head = n;
        return;
    }

    DNode* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    n->next = temp->next;
    n->prev = temp;
    temp->next->prev = n;
    temp->next = n;
}

void deleteD(DNode*& head, int x) {
    if (head == nullptr) {
        return;
    }

    DNode* temp = head;

    do {
        if (temp->data == x) {
            if (temp->next == temp) {
                delete temp;
                head = nullptr;
                return;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (temp == head) {
                head = temp->next;
            }

            delete temp;
            return;
        }

        temp = temp->next;
    } while (temp != head);
}

void displayD(DNode* head) {
    if (head == nullptr) {
        cout << "Empty\n";
        return;
    }

    DNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << "\n";
}

int main() {
    SNode* shead = nullptr;
    DNode* dhead = nullptr;

    int n;
    cin >> n;

    while (n--) {
        string op;
        cin >> op;

        if (op == "join") {
            int x, pos;
            cin >> x >> pos;

            insertS(shead, x, pos);
            insertD(dhead, x, pos);
        } else if (op == "leave") {
            int x;
            cin >> x;

            deleteS(shead, x);
            deleteD(dhead, x);
        } else if (op == "display") {
            cout << "Singly: ";
            displayS(shead);

            cout << "Doubly: ";
            displayD(dhead);
        }
    }

    return 0;
}