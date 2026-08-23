#include<stdio.h>
  void swap(int *a,int *b){
    int temp = *a;
    *a= *b;
    *b = temp;
  }

int partition( int a[], int low ,int high){
 
    int p = a[high];
    int i = low-1;

    for(int j =low ; j<high;j++){
        if(a[j]<=p){
            i++;
            swap(&a[i],&a[j]);
        }
    }
   swap (&a[i+1], &a[high]);

   return i+1;
}


void quicksort(int a[], int low ,int high){
    if(low<high){
    int p =partition( a,  low ,high);
     quicksort(a,low,p-1);
     quicksort(a,p+1,high);


    

     }
}
int main(){


    int a [] = {10,3,5,12,4};
    int n = sizeof(a)/sizeof(a[0]);

    quicksort(a, 0,n-1);
     for(int i =0;i<n ;i++){
        printf("%d ", a[i]);
     }
 
return 0;
  }