#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define size 15
#define min 1
#define max 99

int main(){

 int arr[size];

 srand(time(NULL));
 for(int i = 0;i<size;i++){
    arr[i]= (rand()%(max-min+1)) + min;
 }

 for(int i = 0;i<size;i++){
    printf("%d ,",arr[i]);
 }



}