// Time Complexity : O(nlogn)
// Space Complexity : O(n)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : had a basic idea of approach, but wasn't able to code; looked at the solution and understood
#include <bits/stdc++.h> 
using namespace std; 
  
// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* This function is same in both iterative and recursive*/
int partition(int arr[], int l, int h) 
{ 
    //Do the comparison and swapping here 
    int pivot = arr[h];   
      int i = l - 1;  
      for(int j = l; j < h; j++) {
        if(arr[j] <= pivot) {             
          i++;            
          swap(&arr[i], &arr[j]);
        }
      }  
      swap(&arr[i + 1], &arr[h]);  
      return (i + 1);
} 
  
/* A[] --> Array to be sorted,  
l --> Starting index,  
h --> Ending index */
void quickSortIterative(int arr[], int l, int h) 
{ 
    //Try to think that how you can use stack here to remove recursion.
    int stack[h - l + 1]; 
    int top = -1; 
    stack[++top] = l; 
    stack[++top] = h; 
    while (top >= 0) { 
        h = stack[top--]; 
        l = stack[top--]; 
        int pivot_pos = partition(arr, l, h); 
  
         
        if (pivot_pos - 1 > l) { 
            stack[++top] = l; 
            stack[++top] = pivot_pos - 1; 
        } 
  
         
        if (pivot_pos + 1 < h) { 
            stack[++top] = pivot_pos + 1; 
            stack[++top] = h; 
        } 
    }
} 
  
// A utility function to print contents of arr 
void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3 }; 
    int n = sizeof(arr) / sizeof(*arr); 
    quickSortIterative(arr, 0, n - 1); 
    printArr(arr, n); 
    return 0; 
} 