#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

/* Function declarations */
void insertFront();
void insertRear();
void deleteFront();
void deleteRear();
void peekFront();
void peekRear();
void display();

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
    if (front == NULL)
        return 1;
    else
        return 0;
}

/* Insert at Front */
void insertFront()
{
    int value;

    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    /* If deque is empty */
    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        newnode->next = front;
        front->prev = newnode;
        front = newnode;
    }

    printf("%d inserted at Front.\n", value);
}

/* Insert at Rear */
void insertRear()
{
    int value;

    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    /* If deque is empty */
    if (rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        newnode->prev = rear;
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d inserted at Rear.\n", value);
}

/* Delete from Front */
void deleteFront()
{
    struct node *temp;
    int value;

    if (isEmpty())
    {
        printf("Deque Underflow!\n");
        return;
    }

    temp = front;
    value = temp->data;

    /* Only one node */
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        front->prev = NULL;
    }

    free(temp);

    printf("%d deleted from Front.\n", value);
}

/* Delete from Rear */
void deleteRear()
{
    struct node *temp;
    int value;

    if (isEmpty())
    {
        printf("Deque Underflow!\n");
        return;
    }

    temp = rear;
    value = temp->data;

    /* Only one node */
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        rear = rear->prev;
        rear->next = NULL;
    }

    free(temp);

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

    printf("Front element = %d\n", front->data);
}

/* Peek Rear */
void peekRear()
{
    if (isEmpty())
    {
        printf("Deque is Empty!\n");
        return;
    }

    printf("Rear element = %d\n", rear->data);
}

/* Display */
void display()
{
    struct node *temp;

    if (isEmpty())
    {
        printf("Deque is Empty!\n");
        return;
    }

    temp = front;

    printf("Deque: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}