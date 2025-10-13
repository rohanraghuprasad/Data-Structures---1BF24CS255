#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int top = -1;
char stack[MAX];

void push(char c) {
    if (top == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek() {
    if (top == -1) {
        return -1;
    }
    return stack[top];
}

int precede(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
            return 0;
    }
    return -1;
}

int assoc(char c) {
    if (c == '^')
        return 1;
    return 0;
}

void postfixConv(char infix[], char postfix[]) {
    int i, k = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (peek() != -1 && peek() != '(')
                postfix[k++] = pop();
            if (peek() == '(')
                pop();
            else
                printf("Mismatched parentheses.\n");
        } else {
            while (top != -1 && ((precede(peek()) > precede(c)) ||
                   (precede(peek()) == precede(c) && assoc(c) == 0))) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }


    while (top != -1) {
        if (peek() == '(' || peek() == ')') {
            printf("Mismatched parentheses.\n");
            return;
        }
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid infix expression: ");
    scanf("%s", infix);

    postfixConv(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
