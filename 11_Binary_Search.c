#include <stdio.h>
 int binary_search( int arr[] , int low,int high,int key) {
    if (low > high) return -1; // Element not found

    int mid = low + (high-low)/2;

    if(arr[mid]==key) return mid;

    else if (arr[mid]>key) return binary_search(arr,low ,mid-1,key);
    
    else  return binary_search(arr,mid+1, high,key);


}

int main() {
 int  arr[] ={ 2, 3, 4, 10, 40 };
   int n = sizeof(arr)/sizeof(arr[0]);

  int result = binary_search(arr ,0 ,n-1,10);
  if (result !=-1) 
  printf(" found");
  else
   printf(" not found ");


 }
