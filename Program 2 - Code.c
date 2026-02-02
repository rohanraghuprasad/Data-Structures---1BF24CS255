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

        // If operand, add to postfix
        if (isalnum(c)) {
            postfix[k++] = c;
        }

        // If '(', push to stack
        else if (c == '(') {
            push(c);
        }

        // If ')', pop until '('
        else if (c == ')') {
            while (peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }

        // If operator
        else {
            while (top != -1 &&
                  (precedence(peek()) > precedence(c) ||
                  (precedence(peek()) == precedence(c) && assoc(c) == 0))) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; // end string
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid infix expression: ");
    scanf("%s", infix);

    postfixConv(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}


