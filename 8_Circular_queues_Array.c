#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

/* Function declarations */
void enqueue();
void dequeue();
void peek();
void display();

int isFull();
int isEmpty();

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== CIRCULAR QUEUE =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

/* Check whether queue is full */
int isFull()
{
    return ((rear + 1) % MAX == front);
}

/* Check whether queue is empty */
int isEmpty()
{
    return (front == -1);
}

/* Insert element */
void enqueue()
{
    int value;

    if (isFull())
    {
        printf("Circular Queue is FULL!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;

    printf("%d inserted successfully.\n", value);
}

/* Delete element */
void dequeue()
{
    int value;

    if (isEmpty())
    {
        printf("Circular Queue is EMPTY!\n");
        return;
    }

    value = queue[front];

    if (front == rear)
    {
        /* Only one element was present */
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    printf("%d deleted successfully.\n", value);
}

/* Display front element */
void peek()
{
    if (isEmpty())
    {
        printf("Circular Queue is EMPTY!\n");
        return;
    }

    printf("Front element = %d\n", queue[front]);
}

/* Display all elements */
void display()
{
    int i;

    if (isEmpty())
    {
        printf("Circular Queue is EMPTY!\n");
        return;
    }

    printf("Circular Queue: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}