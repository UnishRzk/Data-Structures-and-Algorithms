#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char c) {
    stack[++top] = c;
}

char pop() {
    if(top == -1)
        return '\0';
    return stack[top--];
}

// Check if character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Return precedence of operator
int precedence(char c) {
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Reverse a string in place
void reverse(char *exp) {
    int i = 0, j = strlen(exp) - 1;
    while(i < j) {
        char temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
        i++;
        j--;
    }
}

// Convert infix expression to postfix expression
void infixToPostfix(char *infix, char *postfix) {
    int i, k = 0;
    for(i = 0; infix[i] != '\0'; i++) {
        // If operand, add to postfix expression
        if(isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }
        // If '(', push to stack
        else if(infix[i] == '(') {
            push(infix[i]);
        }
        // If ')', pop until '(' is encountered
        else if(infix[i] == ')') {
            while(top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            if(top != -1 && stack[top] == '(')
                pop(); // Remove '('
        }
        // If operator, pop operators from stack with higher or equal precedence
        else if(isOperator(infix[i])) {
            while(top != -1 && isOperator(stack[top]) &&
                 ((precedence(infix[i]) < precedence(stack[top])) ||
                 (precedence(infix[i]) == precedence(stack[top]) && infix[i] != '^'))) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }
    // Pop any remaining operators in the stack
    while(top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], reversed[MAX], postfix[MAX], prefix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    // Step 1: Reverse the infix expression
    strcpy(reversed, infix);
    reverse(reversed);
    
    // Step 2: Replace '(' with ')' and vice versa
    for(int i = 0; reversed[i] != '\0'; i++) {
        if(reversed[i] == '(')
            reversed[i] = ')';
        else if(reversed[i] == ')')
            reversed[i] = '(';
    }
    
    // Reset stack for fresh conversion
    top = -1;
    
    // Step 3: Convert reversed infix expression to postfix
    infixToPostfix(reversed, postfix);
    
    // Step 4: Reverse the postfix expression to get prefix
    strcpy(prefix, postfix);
    reverse(prefix);
    
    printf("Prefix expression: %s\n", prefix);
    
    return 0;
}
