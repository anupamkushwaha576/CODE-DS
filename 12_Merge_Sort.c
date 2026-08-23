#include<stdio.h>

void merge(int arr[], int low, int mid, int high) { 
    int i = low, j = mid + 1, k = 0;
    int temp[high-low+1];

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) 
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    
    while (j <= high) {
        temp[k++] = arr[j++];
    }
    
    for (i = 0; i <= k; i++) {
        arr[low + i] = temp[i];
    }
}

void mergesort( int arr [] ,int low ,int high){
  if (low < high)
    {
        int mid = (low + high) / 2;

        mergesort(arr, low, mid);       // Left half
        mergesort(arr, mid + 1, high); // Right half

        merge(arr, low, mid, high);    // Merge
    }


}



int main(){
    int arr [] = {1, 3, 5, 7};
    
    int n = sizeof(arr)/sizeof(arr[0]);
  
    
 

    mergesort(arr,0, n-1);

   
    for(int i=0;i<n;i++){
        printf(" %d ", arr[i]);
    }




}