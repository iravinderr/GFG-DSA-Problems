//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int len1 = m-l+1;
         int len2 = r-m;
         
         int* left = new int[len1];
         int* right = new int[len2];
         
         int k=l;
         for(int i=0; i<len1; i++){
             left[i] = arr[k++];
         }
         
         k = m + 1;
         for(int j=0; j<len2; j++){
             right[j] = arr[k++];
         }
         
         k=l;
         int i=0, j=0;
         while(i < len1 && j < len2){
             if(left[i] < right[j]){
                 arr[k++] = left[i++];
             }
             else{
                 arr[k++] = right[j++];
             }
         }
         
         while(i < len1){
             arr[k++] = left[i++];
         }
         
         while(j < len2){
             arr[k++] = right[j++];
         }
         
         delete left;
         delete right;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l >= r){
            return;
        }
        
        int m = l + ((r-l)/2);
        
        //function call for left half array
        mergeSort(arr, l, m);
        
        //function call for right half array
        mergeSort(arr, m+1, r);
        
        //merging the two sorted arrays obtained
        merge(arr, l, m, r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends