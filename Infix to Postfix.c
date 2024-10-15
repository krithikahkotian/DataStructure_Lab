#include <stdio.h>
#include <ctype.h>
#define STACK_SIZE 20

void push(char stck[], char ele, int *top) {
    stck[++(*top)] = ele;
}

char pop(char stck[], int *top) {
    return (stck[(*top)--]);
}

int pr(char op) {
    switch (op) {
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
        default: return 0;
    }
}

int main() {
    char infix[STACK_SIZE], stck[STACK_SIZE], ch;
    int i = 0, top = -1;
    
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    push(stck, '#', &top);
    
    while (infix[i] != '\0') {
        if (isalpha(infix[i])) {
            printf("%c", infix[i]);
        } else if (infix[i] == '(') {
            push(stck, infix[i], &top);
        } else if (infix[i] == ')') {
            while (stck[top] != '(') {
                ch = pop(stck, &top);
                printf("%c", ch);
            }
            pop(stck, &top);
        } else {
            while (stck[top] != '#' && pr(infix[i]) <= pr(stck[top])) {
                ch = pop(stck, &top);
                printf("%c", ch);
            }
            push(stck, infix[i], &top);
        }
        i++;
    }
    
    while (stck[top] != '#') {
        ch = pop(stck, &top);
        printf("%c", ch);
    }

    return 0;
}
