#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head_ref = NULL;


void createList(int n) {
    struct Node *newNode, *tmp;
    int newdata;

    for(int i = 1; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &newdata);
        newNode->data = newdata;
        newNode->next = NULL;

        if (head_ref == NULL) {
            head_ref = newNode;
        } else {
            tmp->next = newNode;
        }
        tmp = newNode;
    }
}


void pushFirst(struct Node **head, int newdata) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newdata;
    newNode->next = *head;
    *head = newNode;
}


void pushAny(struct Node **head, int newdata, int pos) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = newdata;

    if (pos == 1) {
        ptr->next = *head;
        *head = ptr;
        return;
    }

    struct Node *tmp = *head;
    for (int i = 1; i < pos - 1 && tmp != NULL; i++) {
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        printf("Invalid position\n");
        free(ptr);
        return;
    }

    ptr->next = tmp->next;
    tmp->next = ptr;
}


void pushEnd(struct Node **head, int newdata) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head;

    newNode->data = newdata;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}


void display(struct Node *node) {
    printf("\nCurrent Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    int n, choice, data, pos;

    printf("How many nodes do you want to create initially? ");
    scanf("%d", &n);
    createList(n);
    display(head_ref);

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Any Position\n");
        printf("3. Insert at End\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                pushFirst(&head_ref, data);
                display(head_ref);
                break;
            case 2:
                printf("Enter position and data: ");
                scanf("%d %d", &pos, &data);
                pushAny(&head_ref, data, pos);
                display(head_ref);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                pushEnd(&head_ref, data);
                display(head_ref);
                break;
            case 4:
                display(head_ref);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
