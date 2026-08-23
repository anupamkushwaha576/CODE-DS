#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* Function Declarations */
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void search();
void display_forward();
void display_backward();
void count();
void update();
void reverse();
void delete_all();

int main() {
    int choice = 0;
    while (choice != 14) {
        printf("\n*********Main Menu*********\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Last\n");
        printf("3. Insert after a Location\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from Last\n");
        printf("6. deletion_specified \n");
        printf("7. Search\n");
        printf("8. Display Forward\n");
        printf("9. Display Backward\n");
        printf("10. Count Nodes\n");
        printf("11. Update Node\n");
        printf("12. Reverse List\n");
        printf("13. Delete Entire List\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insertion_beginning(); break;
            case 2: insertion_last(); break;
            case 3: insertion_specified(); break;
            case 4: deletion_beginning(); break;
            case 5: deletion_last(); break;
            case 6: deletion_specified(); break;
            case 7: search(); break;
            case 8: display_forward(); break;
            case 9: display_backward(); break;
            case 10: count(); break;
            case 11: update(); break;
            case 12: reverse(); break;
            case 13: delete_all(); break;
            case 14: printf("Program terminated.\n"); delete_all(); exit(0);
            default: printf("Please enter valid choice..\n");
        }
    }
    return 0;
}

/* Insert at Beginning */
void insertion_beginning() {
    struct node *ptr;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL) { printf("OVERFLOW\n"); return; }
    printf("Enter Item value: ");
    scanf("%d",&item);
    ptr->data=item;
    ptr->prev=NULL;
    ptr->next=head;
    if(head!=NULL) head->prev=ptr;
    head=ptr;
    printf("Node inserted at beginning.\n");
}

/* Insert at Last */
void insertion_last() {
    struct node *ptr,*temp;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){ printf("OVERFLOW\n"); return; }
    printf("Enter value: ");
    scanf("%d",&item);
    ptr->data=item; ptr->next=NULL;
    if(head==NULL){ ptr->prev=NULL; head=ptr; }
    else {
        temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=ptr; ptr->prev=temp;
    }
    printf("Node inserted at last.\n");
}

/* Insert after a Location */
void insertion_specified() {
    struct node *ptr,*temp=head;
    int item,loc,i;
    if(head==NULL){ printf("List empty.\n"); return; }
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){ printf("OVERFLOW\n"); return; }
    printf("Enter value: "); scanf("%d",&item);
    printf("Enter location after which to insert: "); scanf("%d",&loc);
    for(i=1;i<loc && temp!=NULL;i++) temp=temp->next;
    if(temp==NULL){ printf("Location not found.\n"); free(ptr); return; }
    ptr->data=item; ptr->next=temp->next; ptr->prev=temp;
    if(temp->next!=NULL) temp->next->prev=ptr;
    temp->next=ptr;
    printf("Node inserted successfully.\n");
}

/* Delete from Beginning */
void deletion_beginning() {
    struct node *ptr;
    if(head==NULL){ printf("UNDERFLOW\n"); return; }
    ptr=head; head=head->next;
    if(head!=NULL) head->prev=NULL;
    printf("Deleted element = %d\n",ptr->data);
    free(ptr);
}
/* Delete from Last */
void deletion_last() {
    struct node *ptr;
    if(head==NULL) {
        printf("UNDERFLOW\n");
        return;
    }
    ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;

    if(ptr->prev != NULL) {
        ptr->prev->next = NULL;   // disconnect the last node
    } else {
        head = NULL;              // list had only one node
    }

    printf("Deleted element = %d\n", ptr->data);
    free(ptr);
}

/* Delete after a Location */
void deletion_specified() {
    struct node *ptr=head,*temp;
    int val;
    printf("Enter the data after which node is to be deleted: ");
    scanf("%d",&val);
    while(ptr!=NULL && ptr->data!=val) ptr=ptr->next;
    if(ptr==NULL || ptr->next==NULL){ printf("Can't delete.\n"); return; }
    temp=ptr->next; ptr->next=temp->next;
    if(temp->next!=NULL) temp->next->prev=ptr;
    printf("Deleted element = %d\n",temp->data);
    free(temp);
}

/* Search */
void search() {
    struct node *ptr=head; int item,i=1,found=0;
    if(ptr==NULL){ printf("Empty List\n"); return; }
    printf("Enter item to search: "); scanf("%d",&item);
    while(ptr!=NULL){
        if(ptr->data==item){ printf("Item found at location %d\n",i); found=1; }
        ptr=ptr->next; i++;
    }
    if(!found) printf("Item not found\n");
}

/* Display Forward */
void display_forward() {
    struct node *ptr=head;
    if(ptr==NULL){ printf("List empty\n"); return; }
    printf("Forward List:\n");
    while(ptr!=NULL){ printf("%d ",ptr->data); ptr=ptr->next; }
    printf("\n");
}

/* Display Backward */
void display_backward() {
    struct node *ptr=head;
    if(ptr==NULL){ printf("List empty\n"); return; }
    while(ptr->next!=NULL) ptr=ptr->next;
    printf("Backward List:\n");
    while(ptr!=NULL){ printf("%d ",ptr->data); ptr=ptr->prev; }
    printf("\n");
}

/* Count Nodes */
void count() {
    struct node *ptr=head; int total=0;
    while(ptr!=NULL){ total++; ptr=ptr->next; }
    printf("Total nodes = %d\n",total);
}

/* Update Node */
void update() {
    struct node *ptr=head; int loc,item,i;
    printf("Enter location to update: "); scanf("%d",&loc);
    for(i=1;i<loc && ptr!=NULL;i++) ptr=ptr->next;
    if(ptr==NULL){ printf("Location not found.\n"); return; }
    printf("Current value = %d\n",ptr->data);
    printf("Enter new value: "); scanf("%d",&item);
    ptr->data=item; printf("Node updated.\n");
}

/* Reverse List */
void reverse() {
    struct node *current=head,*temp=NULL;
    if(head==NULL){ printf("List empty\n"); return; }
    while(current!=NULL){
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    if(temp!=NULL) head=temp->prev;
    printf("List reversed.\n");
}

/* Delete Entire List */
void delete_all() {
    struct node *ptr;
    while(head!=NULL){ ptr=head; head=head->next; free(ptr); }
    printf("Entire list deleted.\n");
}
