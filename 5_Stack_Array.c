#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

/* PUSH */
void push()
{
    int value;

    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    top++;
    stack[top] = value;

    printf("%d pushed into stack\n", value);
}

/* POP */
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("%d popped from stack\n", stack[top]);

    top--;
}

/* PEEK */
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element = %d\n", stack[top]);
}

/* DISPLAY */
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

/* isEmpty */
void isEmpty()
{
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Stack is Not Empty\n");
}

/* isFull */
void isFull()
{
    if (top == MAX - 1)
        printf("Stack is Full\n");
    else
        printf("Stack is Not Full\n");
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
        printf("6. isFull\n");
        printf("7. Exit\n");

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
                isFull();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}