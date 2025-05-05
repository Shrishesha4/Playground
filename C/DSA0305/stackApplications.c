#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};


void push(struct Stack* s, char value) {
    if (s->top == MAX_SIZE - 1) return;
    s->items[++(s->top)] = value;
}

char pop(struct Stack* s) {
    if (s->top == -1) return '\0';
    return s->items[(s->top)--];
}

char peek(struct Stack* s) {
    if (s->top == -1) return '\0';
    return s->items[s->top];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return -1;
}

void infixToPostfix(char* infix) {
    struct Stack s = {-1};
    int i, j = 0;
    char postfix[MAX_SIZE];
    
    for (i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(&s, infix[i]);
        }
        else if (infix[i] == ')') {
            while (s.top > -1 && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else {
            while (s.top > -1 && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    
    while (s.top > -1) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
    
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    printf("Infix expression: %s\n", infix);
    infixToPostfix(infix);
    
    return 0;
}