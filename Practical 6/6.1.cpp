
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the stack: ";
    cin >> n;

    int stack[100];
    int top = -1;

    int operations;
    cout << "Enter the number of operations to perform: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        string operation;
        cout << "Enter an operation: ";
        cin >> operation;

        if (operation == "place") {
            int tray;
            cin >> tray;

            if (top == n - 1) {
                cout << "Stack Overflow" << endl;
            } else {
                top++;
                stack[top] = tray;
                cout << "Top plate is: " << stack[top] << endl;
            }
        } else if (operation == "take") {
            if (top == -1) {
                cout << "Stack is empty" << endl;
            } else {
                cout << "Plate is: " << stack[top] << endl;
                top--;

                if (top == -1) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Next tray is: " << stack[top] << endl;
                }
            }
        } else {
            cout << "Invalid Operation" << endl;
        }
    }

    return 0;
}