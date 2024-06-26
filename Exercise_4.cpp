// Time Complexity : O(nlogn)
// Space Complexity : O(n)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : didn't remember merge sort; even after looking at the pseudo code and the explanantion, was not able to code; finally saw the code and understood

#include<stdlib.h> 
#include<stdio.h> 
  
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
      int n1 = m - l + 1;
      int n2 = r - m;

      int L[n1], M[n2];

      for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
      for (int j = 0; j < n2; j++)
        M[j] = arr[m + 1 + j];

      
      int i, j, k;
      i = 0;
      j = 0;
      k = l;

      
      while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
          arr[k] = L[i];
          i++;
        } else {
          arr[k] = M[j];
          j++;
        }
        k++;
      }

      
      while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
      }

      while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
      }
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) {
        
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        
        merge(arr, l, m, r);
    }
} 
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
}