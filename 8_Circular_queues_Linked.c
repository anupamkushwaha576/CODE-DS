#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

/* Function declarations */
void enqueue();
void dequeue();
void peek();
void display();

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== CIRCULAR QUEUE USING LINKED LIST =====\n");
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
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/* ================= ENQUEUE ================= */

void enqueue()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;

    /* If queue is empty */
    if (front == NULL)
    {
        front = newnode;
        rear = newnode;

        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;

        rear->next = front;
    }

    printf("%d inserted successfully.\n", value);
}

/* ================= DEQUEUE ================= */

void dequeue()
{
    struct node *temp;
    int value;

    /* If queue is empty */
    if (front == NULL)
    {
        printf("Circular Queue is EMPTY!\n");
        return;
    }

    temp = front;
    value = temp->data;

    /* Only one node */
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    free(temp);

    printf("%d deleted successfully.\n", value);
}

/* ================= PEEK ================= */

void peek()
{
    if (front == NULL)
    {
        printf("Circular Queue is EMPTY!\n");
        return;
    }

    printf("Front element = %d\n", front->data);
}

/* ================= DISPLAY ================= */

void display()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Circular Queue is EMPTY!\n");
        return;
    }

    temp = front;

    printf("Circular Queue: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;

    } while (temp != front);

    printf("\n");
}