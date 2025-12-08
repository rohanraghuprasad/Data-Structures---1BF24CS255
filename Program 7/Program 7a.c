#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;


void createList(int n) {
    int data;
    for (int i = 1; i <=n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

void pushFirst(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }
}

void pushEnd(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAny(int data, int pos) {
    if (pos == 1) {
        pushFirst(data);
        return;
    }

    struct Node *tmp = head;
    for (int i = 1; i < pos - 1 && tmp != NULL; i++) {
        tmp = tmp->next;
    }

    if (tmp == NULL || tmp->next == NULL) {
        pushEnd(data);
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = tmp->next;
    newNode->prev = tmp;
    tmp->next->prev = newNode;
    tmp->next = newNode;
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *tmp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    free(tmp);
}

void deleteEnd() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *tmp = tail;
    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    free(tmp);
}

void deleteAny(int val) {
    struct Node *tmp = head;

    while (tmp != NULL && tmp->data != val)
        tmp = tmp->next;

    if (tmp == NULL) {
        printf("Value %d not found.\n", val);
        return;
    }

    if (tmp == head) {
        deleteFirst();
    } else if (tmp == tail) {
        deleteEnd();
    } else {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        free(tmp);
    }
}
void displayForward() {
    struct Node *tmp = head;
    printf("List(Forward): ");
    while (tmp != NULL) {
        printf("%d<->", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void displayBackward() {
    struct Node *tmp = tail;
    printf("List (Backward): ");
    while (tmp != NULL) {
        printf("%d<->", tmp->data);
        tmp = tmp->prev;
    }
    printf("NULL\n");
}

int main() {
    int n, choice, data, pos;

    printf("How many nodes to create initially? ");
    scanf("%d", &n);
    createList(n);
    displayForward();
    displayBackward();

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Display Forward\n");
        printf("6. Display Backward\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                pushFirst(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                pushEnd(data);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAny(data, pos);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteAny(data);
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
