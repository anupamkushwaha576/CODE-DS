#include <stdio.h>


int main() {
    int  arr[] ={ 2,3, 3 ,3, 4 };
    int n = sizeof(arr)/sizeof(arr[0]);

   int count = 0;

   int k =4;
   for(int i =0;i<n;i++){
   if(arr[i]==k)
     count=count+1 ;

   }

   printf("%d", count);
    return 0;
}