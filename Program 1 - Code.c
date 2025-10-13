#include <stdio.h>

int N;
int stack[100], top = -1;

void push(int val) {
    if (top == N - 1) {
        printf("\nOverflow\n");
    } else {
        top++;
        stack[top] = val;
        printf("\n%d pushed to stack\n", val);
    }
}

int pop() {
    if (top == -1) {
        printf("Underflow\n");
        return -1;
    } else {
        int val = stack[top];
        top--;
        return val;
    }
}

int peek() {
    if (top == -1) {
        printf("\nStack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

int main() {
    int choice, val;

    // Move input for stack size inside main
    printf("Enter size of stack: ");
    scanf("%d", &N);

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to be pushed: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                val = pop();
                if (val != -1) {
                    printf("%d popped from stack\n", val);
                }
                break;
            case 3:
                val = peek();
                if (val != -1) {
                    printf("Top element is %d\n", val);
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
