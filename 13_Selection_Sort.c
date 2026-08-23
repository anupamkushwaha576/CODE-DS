#include <stdio.h>
int main() {
   int arr[] = {2,4,6,5,3 ,2};
   int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n-1;i++){

        for(int j =0;j<n;j++){
       if(arr[j+1]<arr[j]){
        int temp = arr[j];
        arr[j]= arr[j+1];
        arr[j+1]= temp;

       }

        }


    }
   for(int i =0;i<=n;i++){
        printf("%d ",arr[i]);
    }





}