#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
   int data;
   struct node*left;
   struct node*right;


} node ;

node* create ( int val ){
    node * ptr = (node*) malloc(sizeof(node));

    ptr->data= val;
    ptr -> left = NULL;
    ptr -> right= NULL;

    return ptr;
}

node*buildtree(int a[],int * idx,int n){
 if (*idx>=n) return NULL;

 int val = a[*idx ];
 (*idx)++;

 if(val == -1)return NULL;

  node * root = create(val);

  //printf(" %d ",root->data);

  root -> left = buildtree( a,idx,n);
  root -> right = buildtree( a,idx,n);
  return root;

}

void preorder(node * root){
 
    if(root == NULL) return;
  
    printf("%d " ,root->data);
     preorder(root->left);
     preorder(root->right);
}


void inorder(node * root){
 
    if(root == NULL) return;
   inorder(root->left);
    printf("%d " ,root->data);
     inorder(root->right);
}



void postorder(node * root){
 
    if(root == NULL) return;
  
    postorder(root->left);
    postorder(root->right);
    printf("%d " ,root->data); 
}



int main(){
 int a [] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  int n = sizeof(a)/sizeof(a[0]);
  int idx= 0;

   node * parent = buildtree(a,&idx,n);
   printf("Preorder Traversal: ");
   preorder( parent);
   printf("\n########################\n");
   printf("Inorder Traversal: ");
   inorder( parent);

   printf("\n########################\n");
   printf("postorder Traversal: ");
   postorder( parent);




}








