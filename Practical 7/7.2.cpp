#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node* front = NULL;
    Node* rear = NULL;

    int choice;
    int value;

    do
    {
        cout << "\n1. Arrive Patient";
        cout << "\n2. Attend Patient";
        cout << "\n3. Display Front";
        cout << "\n4. Display Queue";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "Enter patient token: ";
            cin >> value;

            Node* newNode = new Node();

            newNode->data = value;
            newNode->next = NULL;

            if(front == NULL)
            {
                front = newNode;
                rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }

            cout << "Patient added." << endl;
        }

        else if(choice == 2)
        {
            if(front == NULL)
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                Node* temp = front;

                cout << "Attended patient: " << front->data << endl;

                front = front->next;

                if(front == NULL)
                {
                    rear = NULL;
                }

                delete temp;
            }
        }

        else if(choice == 3)
        {
            if(front == NULL)
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout << "Front patient: " << front->data << endl;
            }
        }

        else if(choice == 4)
        {
            if(front == NULL)
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                Node* temp = front;

                cout << "Queue: ";

                while(temp != NULL)
                {
                    cout << temp->data << " ";
                    temp = temp->next;
                }

                cout << endl;
            }
        }

    } while(choice != 5);

    return 0;
}