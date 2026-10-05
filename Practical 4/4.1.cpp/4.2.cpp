#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    struct Node* temp;

    if (newNode == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertFront(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (newNode == NULL) {
        return;
    }

    newNode->next = *head;
    *head = newNode;
}

void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode;
    struct Node* temp;
    int i;

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertFront(head, value);
        return;
    }

    newNode = createNode(value);
    if (newNode == NULL) {
        return;
    }

    temp = *head;
    for (i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position! Position is beyond queue length.\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position! Position is beyond queue length.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByValue(struct Node** head, int value) {
    struct Node* temp;
    struct Node* prev;

    if (*head == NULL) {
        printf("Queue is empty. Deletion not possible.\n");
        return;
    }

    temp = *head;
    prev = NULL;

    if (temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Patient token deleted.\n");
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Patient token not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Patient token deleted.\n");
}

void display(struct Node* head) {
    struct Node* temp = head;

    printf("Patient Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice;
    int token;
    int position;

    while (1) {
        printf("\n==============================\n");
        printf("Patient Queue Management System\n");
        printf("==============================\n");
        printf("1. Insert Critical Patient at Front\n");
        printf("2. Insert Routine Patient at End\n");
        printf("3. Insert Priority Patient at Position\n");
        printf("4. Delete Patient by Token\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the patient token: ");
                scanf("%d", &token);
                insertFront(&head, token);
                display(head);
                break;

            case 2:
                printf("Enter the patient token: ");
                scanf("%d", &token);
                insertEnd(&head, token);
                display(head);
                break;

            case 3:
                printf("Enter the patient token: ");
                scanf("%d", &token);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, token, position);
                display(head);
                break;

            case 4:
                printf("Enter the patient token to delete: ");
                scanf("%d", &token);
                deleteByValue(&head, token);
                display(head);
                break;

            case 5:
                display(head);
                break;

            case 6:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}    