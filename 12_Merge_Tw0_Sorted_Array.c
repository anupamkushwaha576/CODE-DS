#include<stdio.h>
 void merge( int a [], int b [],int c [] ,int n,int m){ 
  int i =0,j=0,k=0;
  while(i<n && j< m){
        if(a[i]<b [j]) 
        c[k++] = a[i++];
        else
         c[k++] =b[j++];
    }

    while(i<n) c[k++]=a[i++];
    while(j<m) c[k++] = b[j++];

 }


int main(){
    int a [] = {1, 3, 5, 7};
    int b [] =  {2, 4, 6, 8};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);

 //   printf(" %d %d", n,m);
    int c [n + m];
    int p = sizeof(c)/sizeof(c[0]);

    merge(a,b,c,n,m);

    for(int i=0;i<p;i++){
        printf(" %d ", c[i]);
    }




}