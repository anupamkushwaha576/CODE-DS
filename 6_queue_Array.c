#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

/* Function declarations */
void enqueue();
void dequeue();
void peek();
void isEmpty();
void isFull();
void display();

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== LINEAR QUEUE =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Is Empty\n");
        printf("5. Is Full\n");
        printf("6. Display\n");
        printf("7. Exit\n");

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
                isEmpty();
                break;

            case 5:
                isFull();
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/* ================= ENQUEUE ================= */
void enqueue()
{
    int value;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow! Queue is Full.\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;

    printf("%d inserted into queue.\n", value);
}

/* ================= DEQUEUE ================= */
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow! Queue is Empty.\n");
        return;
    }

    printf("%d deleted from queue.\n", queue[front]);

    front++;

    /* Reset queue when it becomes empty */
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

/* ================= PEEK ================= */
void peek()
{
    if (front == -1)
    {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Front element = %d\n", queue[front]);
}

/* ================= IS EMPTY ================= */
void isEmpty()
{
    if (front == -1)
        printf("Queue is Empty.\n");
    else
        printf("Queue is NOT Empty.\n");
}

/* ================= IS FULL ================= */
void isFull()
{
    if (rear == MAX - 1)
        printf("Queue is Full.\n");
    else
        printf("Queue is NOT Full.\n");
}

/* ================= DISPLAY ================= */
void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Queue elements: ");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}