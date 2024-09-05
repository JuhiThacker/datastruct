#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Define a stack with maximum size
#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, char element) {
    if (!isFull(s)) {
        s->data[++(s->top)] = element;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    } else {
        printf("Stack underflow\n");
        return '\0';
    }
}

// Function to get the top element of the stack
char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    } else {
        return '\0';
    }
}

// Function to check the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        // If the character is an operand, add it to postfix
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        // If the character is '(', push it to the stack
        else if (infix[i] == '(') {
            push(&s, infix[i]);
        }
        // If the character is ')', pop and output until '(' is found
        else if (infix[i] == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '(' from stack
        }
        // If the character is an operator
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
        i++;
    }

    // Pop all the operators from the stack
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    // Get the infix expression from the user
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert to postfix
    infixToPostfix(infix, postfix);

    // Output the postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}