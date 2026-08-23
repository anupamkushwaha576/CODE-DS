#include <stdio.h>

 int binary_search(int arr[], int low , int high ,int key){

        
     
     while(low<=high){

      int mid = low + (high - low) / 2 ;

       if(arr[mid]== key) return mid;
       if(arr[mid]>key) high = mid-1;
       if(arr[mid]<key) low = mid +1;

       
     }
   
 return -1;




        

 }

int main() {
 int  arr[] ={ 2, 3, 4, 10, 40 };
   int n = sizeof(arr)/sizeof(arr[0]);

  int result = binary_search(arr ,0 ,n-1,10);
  if (result ==-1) 
  printf(" not found");
  else
   printf(" found ");


 }
