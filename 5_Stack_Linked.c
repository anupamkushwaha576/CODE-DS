#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

/* PUSH */
void push()
{
    int value;

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    printf("%d pushed into stack\n", value);
}

/* POP */
void pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;

    printf("%d popped from stack\n", top->data);

    top = top->next;

    free(temp);
}

/* PEEK */
void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element = %d\n", top->data);
}

/* DISPLAY */
void display()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp = top;

    printf("Stack elements:\n");

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

/* isEmpty */
void isEmpty()
{
    if (top == NULL)
        printf("Stack is Empty\n");
    else
        printf("Stack is Not Empty\n");
}

/* MAIN */
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. isEmpty\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                isEmpty();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}