
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int pow;
    struct node *next;
};

/* Function declarations */
struct node *create();
void display(struct node *);
struct node *add(struct node *, struct node *);

/* ========================= MAIN ========================= */

int main()
{
    struct node *start1 = NULL;
    struct node *start2 = NULL;
    struct node *start3 = NULL;

    printf("\nEnter 1st Polynomial\n");
    start1 = create();

    printf("\nEnter 2nd Polynomial\n");
    start2 = create();

    printf("\n1st Polynomial:\n");
    display(start1);

    printf("\n2nd Polynomial:\n");
    display(start2);

    /* Addition */
    start3 = add(start1, start2);

    printf("\nAdded Polynomial:\n");
    display(start3);

    return 0;
}

/* ========================= CREATE ========================= */

struct node *create()
{
    struct node *start = NULL;
    struct node *temp = NULL;
    struct node *newnode;
    char ch;

    do
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        printf("Enter coefficient and power: ");
        scanf("%d%d", &newnode->coeff, &newnode->pow);

        newnode->next = NULL;

        /* First node */
        if (start == NULL)
        {
            start = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Press y to continue: ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    return start;
}

/* ========================= DISPLAY ========================= */

void display(struct node *start)
{
    struct node *temp = start;

    if (start == NULL)
    {
        printf("0\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->pow);

        temp = temp->next;

        if (temp != NULL)
        {
            printf(" + ");
        }
    }

    printf("\n");
}

/* ========================= ADDITION ========================= */

struct node *add(struct node *start1, struct node *start2)
{
    struct node *start3 = NULL;
    struct node *temp3 = NULL;
    struct node *newnode;

    while (start1 != NULL && start2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        newnode->next = NULL;

        /* Same powers */
        if (start1->pow == start2->pow)
        {
            newnode->coeff = start1->coeff + start2->coeff;
            newnode->pow = start1->pow;

            start1 = start1->next;
            start2 = start2->next;
        }

        /* First polynomial has greater power */
        else if (start1->pow > start2->pow)
        {
            newnode->coeff = start1->coeff;
            newnode->pow = start1->pow;

            start1 = start1->next;
        }

        /* Second polynomial has greater power */
        else
        {
            newnode->coeff = start2->coeff;
            newnode->pow = start2->pow;

            start2 = start2->next;
        }

        /* Insert node into result */
        if (start3 == NULL)
        {
            start3 = newnode;
            temp3 = newnode;
        }
        else
        {
            temp3->next = newnode;
            temp3 = newnode;
        }
    }

    /* Remaining terms of first polynomial */
    while (start1 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        newnode->coeff = start1->coeff;
        newnode->pow = start1->pow;
        newnode->next = NULL;

        if (start3 == NULL)
        {
            start3 = newnode;
            temp3 = newnode;
        }
        else
        {
            temp3->next = newnode;
            temp3 = newnode;
        }

        start1 = start1->next;
    }

    /* Remaining terms of second polynomial */
    while (start2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        newnode->coeff = start2->coeff;
        newnode->pow = start2->pow;
        newnode->next = NULL;

        if (start3 == NULL)
        {
            start3 = newnode;
            temp3 = newnode;
        }
        else
        {
            temp3->next = newnode;
            temp3 = newnode;
        }

        start2 = start2->next;
    }

    return start3;
}