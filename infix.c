#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

int intStack[MAX];
int intTop = -1;

char operators[] = "+-*/^";

int isEmpty() {
    return top == -1;
}

void push(char item) {
    if (top < MAX - 1) {
        stack[++top] = item;
    } else {
        printf("Stack Overflow\n");
    }
}

char pop() {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return '\0';
    }
}

char peek() {
    if (!isEmpty()) {
        return stack[top];
    }
    return '\0';
}

int isOperator(char ch) {
    for (int i = 0; operators[i] != '\0'; i++) {
        if (operators[i] == ch) return 1;
    }
    return 0;
}

int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int isRightAssociative(char op) {
    return op == '^';
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    top = -1; // reset stack
    int j = 0;
    int len = strlen(infix);

    for (int i = 0; i < len; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty() && peek() == '(') {
                pop(); // remove '('
            }
        } else if (isOperator(ch)) {
            while (!isEmpty() && peek() != '(' &&
                  ((precedence(peek()) > precedence(ch)) ||
                   (precedence(peek()) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

void infixToPrefix(char *infix, char *prefix) {
    int len = strlen(infix);
    char revInfix[MAX];
    strcpy(revInfix, infix);
    reverseString(revInfix);

    // Swap '(' and ')' after reversing
    for (int i = 0; i < len; i++) {
        if (revInfix[i] == '(')
            revInfix[i] = ')';
        else if (revInfix[i] == ')')
            revInfix[i] = '(';
    }

    char postfix[MAX];
    infixToPostfix(revInfix, postfix);

    reverseString(postfix);
    strcpy(prefix, postfix);
}

// Integer stack operations for evaluation
void intPush(int val) {
    if (intTop < MAX - 1) {
        intStack[++intTop] = val;
    } else {
        printf("Evaluation stack overflow\n");
    }
}

int intPop() {
    if (intTop >= 0) {
        return intStack[intTop--];
    } else {
        printf("Evaluation stack underflow\n");
        return 0;
    }
}

int evaluatePostfix(char *postfix) {
    intTop = -1;

    int len = strlen(postfix);

    for (int i = 0; i < len; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            intPush(ch - '0');
        } else if (isOperator(ch)) {
            int operand2 = intPop();
            int operand1 = intPop();
            int result = 0;

            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': 
                    if (operand2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    result = operand1 / operand2; 
                    break;
                case '^': 
                    result = 1;
                    for (int j = 0; j < operand2; j++) result *= operand1;
                    break;
            }
            intPush(result);
        }
    }
    return intPop();
}

void main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    int ch;
    printf("1. General Expression\n");
    printf("2. Number Expression\n");
    printf("Enter choice: ");
    scanf("%d", &ch); 		
    printf("Enter infix expression (single-digit operands): ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    infixToPrefix(infix, prefix);
    printf("Prefix: %s\n", prefix);
    if (ch == 2) {
    	int result = evaluatePostfix(postfix);
    	printf("Evaluation Result: %d\n", result);
    }
}

	 
	 
	
