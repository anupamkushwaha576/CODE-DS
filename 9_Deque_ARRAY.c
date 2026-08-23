#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

/* Function declarations */
void insertFront();
void insertRear();
void deleteFront();
void deleteRear();
void peekFront();
void peekRear();
void display();

int isFull();
int isEmpty();

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== DEQUE OPERATIONS =====\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Peek Front\n");
        printf("6. Peek Rear\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                peekFront();
                break;

            case 6:
                peekRear();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/* Check Empty */
int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

/* Check Full */
int isFull()
{
    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
        return 1;
    else
        return 0;
}

/* Insert at Front */
void insertFront()
{
    int value;

    if (isFull())
    {
        printf("Deque Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }

    deque[front] = value;

    printf("%d inserted at Front.\n", value);
}

/* Insert at Rear */
void insertRear()
{
    int value;

    if (isFull())
    {
        printf("Deque Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;

    printf("%d inserted at Rear.\n", value);
}

/* Delete from Front */
void deleteFront()
{
    int value;

    if (isEmpty())
    {
        printf("Deque Underflow!\n");
        return;
    }

    value = deque[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    printf("%d deleted from Front.\n", value);
}

/* Delete from Rear */
void deleteRear()
{
    int value;

    if (isEmpty())
    {
        printf("Deque Underflow!\n");
        return;
    }

    value = deque[rear];

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }

    printf("%d deleted from Rear.\n", value);
}

/* Peek Front */
void peekFront()
{
    if (isEmpty())
    {
        printf("Deque is Empty!\n");
        return;
    }

    printf("Front element = %d\n", deque[front]);
}

/* Peek Rear */
void peekRear()
{
    if (isEmpty())
    {
        printf("Deque is Empty!\n");
        return;
    }

    printf("Rear element = %d\n", deque[rear]);
}

/* Display */
void display()
{
    int i;

    if (isEmpty())
    {
        printf("Deque is Empty!\n");
        return;
    }

    printf("Deque: ");

    i = front;

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}