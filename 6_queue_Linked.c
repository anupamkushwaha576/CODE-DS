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
void isEmpty();
void display();

int main()
{
    int choice;

    while (1)
    {
        printf("\n====================================\n");
        printf("       QUEUE USING LINKED LIST\n");
        printf("====================================\n");

        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Is Empty\n");
        printf("5. Display\n");
        printf("6. Exit\n");

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
                display();
                break;

            case 6:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


/* ====================================
           ENQUEUE
   Insert at REAR
   ==================================== */

void enqueue()
{
    struct node *newnode;
    int value;

    printf("Enter element: ");
    scanf("%d", &value);

    /* Create new node */
    newnode = (struct node *)malloc(sizeof(struct node));

    /* Memory allocation condition */
    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    /* Store data */
    newnode->data = value;
    newnode->next = NULL;

    /* Queue is empty */
    if (front == NULL)
    {
        front = newnode;
        rear = newnode;

        printf("%d inserted as first element.\n", value);
    }

    /* Queue is not empty */
    else
    {
        rear->next = newnode;
        rear = newnode;

        printf("%d inserted at rear.\n", value);
    }
}


/* ====================================
           DEQUEUE
   Delete from FRONT
   ==================================== */

void dequeue()
{
    struct node *temp;

    /* Queue is empty */
    if (front == NULL)
    {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    /* Store the front node */
    temp = front;

    printf("%d deleted from queue.\n", temp->data);

    /* Move front to next node */
    front = front->next;

    /* If deleted node was the only node */
    if (front == NULL)
    {
        rear = NULL;
    }

    /* Free deleted node */
    free(temp);
}


/* ====================================
              PEEK
   Show FRONT element
   ==================================== */

void peek()
{
    /* Queue is empty */
    if (front == NULL)
    {
        printf("Queue is empty. No front element.\n");
        return;
    }

    /* Queue is not empty */
    printf("Front element = %d\n", front->data);
}


/* ====================================
            IS EMPTY
   ==================================== */

void isEmpty()
{
    if (front == NULL)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("Queue is NOT Empty.\n");
    }
}


/* ====================================
             DISPLAY
   ==================================== */

void display()
{
    struct node *temp;

    /* Queue is empty */
    if (front == NULL)
    {
        printf("Queue is Empty.\n");
        return;
    }

    temp = front;

    printf("Queue: ");

    /* Traverse from FRONT to REAR */
    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
        {
            printf(" -> ");
        }

        temp = temp->next;
    }

    printf(" -> NULL\n");
}