#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int peek(struct Stack* stack) {
    return stack->array[stack->top];
}

int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '$';
}

void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    return -1;
}

void infixToPostfix(char* expression) {
    int i, k;
    struct Stack* stack = createStack(strlen(expression));
    if (!stack) return;

    for (i = 0, k = -1; expression[i]; ++i) {
        if (isOperand(expression[i]))
            expression[++k] = expression[i];
        else if (expression[i] == '(')
            push(stack, expression[i]);
        else if (expression[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                expression[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(') return;
            else pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack)))
                expression[++k] = pop(stack);
            push(stack, expression[i]);
        }
    }

    while (!isEmpty(stack))
        expression[++k] = pop(stack);
    expression[++k] = '\0';
}

void reverseString(char* str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    reverseString(infix);
    infixToPostfix(infix);
    reverseString(infix);
    strcpy(prefix, infix);
}

int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    int i, operand1, operand2, result;

    for (i = 0; postfix[i]; ++i) {
        if (isdigit(postfix[i])) {
            push(stack, postfix[i] - '0');
        } else {
            operand2 = pop(stack);
            operand1 = pop(stack);

            switch (postfix[i]) {
                case '+': push(stack, operand1 + operand2); break;
                case '-': push(stack, operand1 - operand2); break;
                case '*': push(stack, operand1 * operand2); break;
                case '/': push(stack, operand1 / operand2); break;
            }
        }
    }
    result = pop(stack);
    return result;
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    // Remove newline character if present
    if (infix[strlen(infix) - 1] == '\n')
        infix[strlen(infix) - 1] = '\0';

    char postfix[MAX_SIZE];
    infixToPostfix(infix);
    printf("Postfix expression: %s\n", infix);

    char prefix[MAX_SIZE];
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    int result = evaluatePostfix(infix);
    printf("Postfix evaluation result: %d\n", result);

    return 0;
}

