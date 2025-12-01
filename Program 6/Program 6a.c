#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head1 = NULL;
struct Node *head2 = NULL;

struct Node* createList(int n) {
    struct Node *head = NULL;
    struct Node *newNode, *tmp;
    int newdata;

    for (int i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return head;
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
    return head;
}

void sort(struct Node *head)
{
    struct Node *i, *j;
    int tmp;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

struct Node* reverse(struct Node* head)
{
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct Node* concatenate(struct Node *head1, struct Node* head2)
{
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node *tmp = head1;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = head2;
    return head1;
}

void display(struct Node *node) {
    if (node == NULL) {
        printf("List is empty\n");
        return;
    }

    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    int n1, n2, choice;

    while (1) {
        printf("\nOptions:\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort first list\n");
        printf("6. Sort second list\n");
        printf("7. Reverse first list\n");
        printf("8. Reverse second list\n");
        printf("9. Concatenate both lists\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many nodes for List 1? ");
                scanf("%d", &n1);
                head1 = createList(n1);
                break;

            case 2:
                printf("How many nodes for List 2? ");
                scanf("%d", &n2);
                head2 = createList(n2);
                break;

            case 3:
                printf("List 1: ");
                display(head1);
                break;

            case 4:
                printf("List 2: ");
                display(head2);
                break;

            case 5:
                sort(head1);
                printf("Sorted List 1: ");
                display(head1);
                break;

            case 6:
                sort(head2);
                printf("Sorted List 2: ");
                display(head2);
                break;

            case 7:
                head1 = reverse(head1);
                printf("Reversed List 1: ");
                display(head1);
                break;

            case 8:
                head2 = reverse(head2);
                printf("Reversed List 2: ");
                display(head2);
                break;

            case 9:
                head1 = concatenate(head1, head2);
                head2 = NULL;
                printf("Concatenation Result (List 1): ");
                display(head1);
                break;

            case 10:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
