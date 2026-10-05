#include <iostream>
using namespace std;

int main()
{
    int size;

    cout << "Enter queue size: ";
    cin >> size;

    int queue[100];

    int front = -1;
    int rear = -1;

    int choice;
    int value;

    do
    {
        cout << "\n1. Join Queue";
        cout << "\n2. Serve Visitor";
        cout << "\n3. Display Front";
        cout << "\n4. Display Queue";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "Enter token number: ";
            cin >> value;

            if((rear + 1) % size == front)
            {
                cout << "Queue is full." << endl;
            }
            else
            {
                if(front == -1)
                {
                    front = 0;
                }

                rear = (rear + 1) % size;
                queue[rear] = value;

                cout << "Token added." << endl;
            }
        }

        else if(choice == 2)
        {
            if(front == -1)
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout << "Served token: " << queue[front] << endl;

                if(front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else
                {
                    front = (front + 1) % size;
                }
            }
        }

        else if(choice == 3)
        {
            if(front == -1)
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout << "Front token: " << queue[front] << endl;
            }
        }

        else if(choice == 4)
        {
            if(front == -1)
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout << "Queue: ";

                int i = front;

                while(true)
                {
                    cout << queue[i] << " ";

                    if(i == rear)
                        break;

                    i = (i + 1) % size;
                }

                cout << endl;
            }
        }

    } while(choice != 5);

    return 0;
}