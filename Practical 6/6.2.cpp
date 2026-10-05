#include <iostream>
using namespace std;

struct Node {
    string page;
    Node* next;
};

int main() {
    Node* top = nullptr;
    int operations;

    cout << "Enter the number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        string operation;
        cout << "Enter operation (visit/back): ";
        cin >> operation;

        if (operation == "visit") {
            string page;
            cout << "Enter page: ";
            cin >> page;

            Node* newNode = new Node();
            newNode->page = page;
            newNode->next = top;
            top = newNode;

            cout << "Current page: " << top->page << endl;
        } else if (operation == "back") {
            if (top == nullptr) {
                cout << "No page history" << endl;
            } else if (top->next == nullptr) {
                cout << "No previous page" << endl;
            } else {
                Node* temp = top;
                top = top->next;
                delete temp;
                cout << "Current page: " << top->page << endl;
            }
        } else {
            cout << "Invalid operation" << endl;
        }
    }

    return 0;
}
