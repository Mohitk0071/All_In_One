
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Top of stack
struct Node *top = NULL;


// PUSH
void PUSH(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d is pushed into stack\n", value);
}


// POP
void POP()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;

    printf("%d is popped from stack\n", top->data);

    top = top->next;

    free(temp);
}


// PEEK
void PEEK()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element is: %d\n", top->data);
}


// DISPLAY
void DISPLAY()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp = top;

    printf("Stack elements are:\n");

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}


// MAIN
int main()
{
    PUSH(10);
    PUSH(20);
    PUSH(30);

    DISPLAY();

    PEEK();

    POP();

    DISPLAY();

    return 0;
}