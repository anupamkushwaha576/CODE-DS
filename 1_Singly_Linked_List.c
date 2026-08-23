#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Function Prototypes */
void insert_begin();
void insert_last();
void insert_random();
void delete_begin();
void delete_last();
void delete_random();
void search();
void display();
void count_nodes();
void update();
void reverse();
void delete_entire();

/* Main Function */
int main() {
    int choice = 0;
    while (choice != 12) {
        printf("\n\n********* Main Menu *********\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Random Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Random Position\n");
        printf("7. Search for an Element\n");
        printf("8. Display List\n");
        printf("9. Count Nodes\n");
        printf("10. Update Node\n");
        printf("11. Reverse List\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_last(); break;
            case 3: insert_random(); break;
            case 4: delete_begin(); break;
            case 5: delete_last(); break;
            case 6: delete_random(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: count_nodes(); break;
            case 10: update(); break;
            case 11: reverse(); break;
            case 12: delete_entire(); printf("Program terminated.\n"); break;
            default: printf("Invalid choice! Please enter 1-12.\n");
        }
    }
    return 0;
}

/* Insert at Beginning */
void insert_begin() {
    struct node *ptr;
    int item;
    ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("OVERFLOW\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = head;
    head = ptr;
    printf("Node inserted at beginning.\n");
}

/* Insert at End */
void insert_last() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("OVERFLOW\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    printf("Node inserted at end.\n");
}

/* Insert at Random Position */
void insert_random() {
    struct node *ptr, *temp;
    int item, loc, i;
    ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("OVERFLOW\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &item);
    ptr->data = item;
    printf("Enter location after which to insert: ");
    scanf("%d", &loc);
    temp = head;
    for (i = 0; i < loc; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Can't insert, location not found.\n");
            return;
        }
    }
    ptr->next = temp->next;
    temp->next = ptr;
    printf("Node inserted at position %d.\n", loc+1);
}

/* Delete from Beginning */
void delete_begin() {
    struct node *ptr;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    ptr = head;
    head = head->next;
    free(ptr);
    printf("Node deleted from beginning.\n");
}

/* Delete from End */
void delete_last() {
    struct node *ptr, *prev;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Only node deleted.\n");
        return;
    }
    ptr = head;
    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    free(ptr);
    printf("Node deleted from end.\n");
}

/* Delete from Random Position */
void delete_random() {
    struct node *ptr, *prev;
    int loc, i;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Enter location to delete: ");
    scanf("%d", &loc);
    ptr = head;
    for (i = 0; i < loc; i++) {
        prev = ptr;
        ptr = ptr->next;
        if (ptr == NULL) {
            printf("Can't delete, location not found.\n");
            return;
        }
    }
    prev->next = ptr->next;
    free(ptr);
    printf("Node deleted at position %d.\n", loc+1);
}

/* Search */
void search() {
    struct node *ptr = head;
    int item, i = 0, found = 0;
    printf("Enter item to search: ");
    scanf("%d", &item);
    while (ptr != NULL) {
        if (ptr->data == item) {
            printf("Item found at position %d.\n", i+1);
            found = 1;
            break;
        }
        ptr = ptr->next;
        i++;
    }
    if (!found) printf("Item not found.\n");
}

/* Display */
void display() {
    struct node *ptr = head;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

/* Count Nodes */
void count_nodes() {
    struct node *ptr = head;
    int count = 0;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    printf("Total nodes: %d\n", count);
}

/* Update Node */
void update() {
    struct node *ptr = head;
    int pos, newData, i;
    printf("Enter position to update: ");
    scanf("%d", &pos);
    printf("Enter new data: ");
    scanf("%d", &newData);
    for (i = 1; i < pos && ptr != NULL; i++) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Invalid position.\n");
        return;
    }
    ptr->data = newData;
    printf("Node updated at position %d.\n", pos);
}

/* Reverse List */
void reverse() {
    struct node *prev = NULL, *curr = head, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed.\n");
}

/* Delete Entire List */
void delete_entire() {
    struct node *ptr;
    while (head != NULL) {
        ptr = head;
        head = head->next;
        free(ptr);
    }
    printf("Entire list deleted.\n");
}
