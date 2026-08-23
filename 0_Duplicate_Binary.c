#include <stdio.h>

int binary(int arr[] , int low ,int high, int key){

if(low>high) return -1;
int mid = (low + high)/2;
if(arr[mid] == key){
  int newans = binary( arr , low, mid - 1,key);
  if(newans == -1)
    return mid;
  return newans;
}

else if( arr[mid]>key)
  return binary( arr ,low,mid-1,key );
else
   return binary( arr ,mid+1,high,key);



};

int rbinary(int arr[] , int low ,int high, int key){
if(low>high) return -1;
int mid = (low + high)/2;
if(arr[mid] == key){
  int newans = rbinary( arr ,mid +1,  high,key);
  if(newans == -1)
    return mid;
  return newans;
}

else if( arr[mid]>key)
  return rbinary( arr ,low,mid-1,key );
else
   return rbinary( arr ,mid+1,high,key);
};


int main() {
    int  arr[] ={ 2, 3,3, 4,4,4,4, 10, 40 };
    int n = sizeof(arr)/sizeof(arr[0]);

    int f =10;
    int r = binary(arr,0,n-1,f);
   int k = rbinary(arr,0,n-1,f);
    int count = k-r+1;

    if(k==-1){
      printf(" not found");
      
    }

    else  
    printf("\n duplicate : %d ",count );
    
    
    

  


    return 0;
}
