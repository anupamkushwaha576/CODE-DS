#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Function declarations */
void insertBeginning();
void insertEnd();
void insertAtPosition();
void deleteBeginning();
void deleteEnd();
void deleteAtPosition();
void search();
void display();

int main() {
    int choice = 0;
    while (choice != 9) {
        printf("\n********* MAIN MENU *********\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search for an Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertBeginning(); break;
            case 2: insertEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6: deleteAtPosition(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: printf("Program terminated.\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

/* INSERT AT BEGINNING */
void insertBeginning() {
    struct node *newnode, *temp;
    int item;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) { printf("Overflow!\n"); return; }
    printf("Enter data: ");
    scanf("%d", &item);
    newnode->data = item;
    if (!head) {
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;
        while (temp->next != head) temp = temp->next;
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
    printf("Node inserted at beginning.\n");
}

/* INSERT AT END */
void insertEnd() {
    struct node *newnode, *temp;
    int item;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) { printf("Overflow!\n"); return; }
    printf("Enter data: ");
    scanf("%d", &item);
    newnode->data = item;
    if (!head) {
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newnode;
        newnode->next = head;
    }
    printf("Node inserted at end.\n");
}

/* INSERT AT POSITION */
void insertAtPosition() {
    struct node *newnode, *temp;
    int item, pos, i;
    if (!head) { printf("List is empty! Use beginning/end insert first.\n"); return; }
    newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) { printf("Overflow!\n"); return; }
    printf("Enter data: ");
    scanf("%d", &item);
    printf("Enter position: ");
    scanf("%d", &pos);
    newnode->data = item;

    if (pos == 1) { insertBeginning(); free(newnode); return; }

    temp = head;
    for (i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position not found!\n");
            free(newnode);
            return;
        }
    }
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Node inserted at position %d.\n", pos);
}

/* DELETE FROM BEGINNING */
void deleteBeginning() {
    struct node *temp, *last;
    if (!head) { printf("Underflow!\n"); return; }
    if (head->next == head) {
        free(head); head = NULL;
        printf("Node deleted.\n"); return;
    }
    last = head;
    while (last->next != head) last = last->next;
    temp = head;
    head = head->next;
    last->next = head;
    free(temp);
    printf("Node deleted from beginning.\n");
}

/* DELETE FROM END */
void deleteEnd() {
    struct node *temp, *prev;
    if (!head) { printf("Underflow!\n"); return; }
    if (head->next == head) {
        free(head); head = NULL;
        printf("Node deleted.\n"); return;
    }
    temp = head;
    while (temp->next != head) { prev = temp; temp = temp->next; }
    prev->next = head;
    free(temp);
    printf("Node deleted from end.\n");
}

/* DELETE FROM POSITION */
void deleteAtPosition() {
    struct node *temp, *prev;
    int pos, i;
    if (!head) { printf("Underflow!\n"); return; }
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (pos == 1) { deleteBeginning(); return; }
    temp = head;
    for (i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == head) {
            printf("Position not found!\n");
            return;
        }
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d.\n", pos);
}

/* SEARCH */
void search() {
    struct node *temp;
    int item, pos = 1, found = 0;
    if (!head) { printf("List is empty!\n"); return; }
    printf("Enter element to search: ");
    scanf("%d", &item);
    temp = head;
    do {
        if (temp->data == item) {
            printf("Element %d found at position %d.\n", item, pos);
            found = 1; break;
        }
        temp = temp->next; pos++;
    } while (temp != head);
    if (!found) printf("Element not found.\n");
}

/* DISPLAY */
void display() {
    struct node *temp;
    if (!head) { printf("List is empty!\n"); return; }
    temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD)\n");
}
