#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createList(int n) {
    struct Node *newNode, *tmp;
    int newdata;

    for (int i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &newdata);

        newNode->data = newdata;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tmp = newNode;
        } else {
            tmp->next = newNode;
            tmp = newNode;
        }
    }
}

void popFirst() {
    if (head == NULL) {
        printf("\nEmpty list");
        return;
    }
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    printf("\nNode at first position deleted");
}

void popAny(int pos) {
    if (pos == 1) {
        popFirst();
        return;
    }

    struct Node *ptr1 = head, *ptr2;
    int i;

    for (i = 1; i < pos; i++) {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
        if (ptr1 == NULL) {
            printf("\nInvalid number, please enter within range");
            return;
        }
    }

    ptr2->next = ptr1->next;
    free(ptr1);
    printf("\nNode at position %d deleted", pos);
}

void popEnd() {
    if (head == NULL) {
        printf("\nEmpty");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("\nDeleted the only node in the list");
        return;
    }

    struct Node *ptr1 = head, *ptr2;

    while (ptr1->next != NULL) {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }

    ptr2->next = NULL;
    free(ptr1);
    printf("\nNode at last position deleted");
}

void display(struct Node *node) {
    printf("\nCurrent linked list: ");
    while (node != NULL) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    int n, choice, pos;

    printf("How many nodes do you want to create initially? ");
    scanf("%d", &n);

    createList(n);
    display(head);

    while (1) {
        printf("\nOptions:\n");
        printf("1. Delete at Beginning\n");
        printf("2. Delete at Any Position\n");
        printf("3. Delete at End\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                popFirst();
                break;
            case 2:
                printf("Enter position of element to be deleted: ");
                scanf("%d", &pos);
                popAny(pos);
                break;
            case 3:
                popEnd();
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
