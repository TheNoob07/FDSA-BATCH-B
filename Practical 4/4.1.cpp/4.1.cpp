#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertFront(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    if (newNode == NULL) {
        return;
    }

    newNode->next = *head;
    *head = newNode;
}

void insertEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    struct Node *temp;

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

void insertAtPosition(struct Node **head, int value, int position) {
    struct Node *newNode;
    struct Node *temp;
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
    for (i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position! Position is beyond list length.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByValue(struct Node **head, int value) {
    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (*head == NULL) {
        printf("Queue is empty. Deletion not possible.\n");
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Patient token %d not found.\n", value);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Patient token %d deleted.\n", value);
}

void display(struct Node *head) {
    struct Node *temp = head;

    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, token, position;

    while (1) {
        printf("\n---- Hospital Patient Queue ----\n");
        printf("1. Insert critical patient at front\n");
        printf("2. Insert routine patient at end\n");
        printf("3. Insert priority patient at position\n");
        printf("4. Delete patient by token\n");
        printf("5. Display queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter patient token: ");
                scanf("%d", &token);
                insertFront(&head, token);
                display(head);
                break;

            case 2:
                printf("Enter patient token: ");
                scanf("%d", &token);
                insertEnd(&head, token);
                display(head);
                break;

            case 3:
                printf("Enter patient token: ");
                scanf("%d", &token);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, token, position);
                display(head);
                break;

            case 4:
                printf("Enter patient token to delete: ");
                scanf("%d", &token);
                deleteByValue(&head, token);
                display(head);
                break;

            case 5:
                display(head);
                break;

            case 6:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}