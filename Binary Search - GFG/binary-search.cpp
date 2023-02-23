//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        int s = 0, e = n-1; // initialising the index pointers
        int midIndex = s + ((e-s)/2); // mid index of the array
        int ans = -1;
        
        while(s <= e){ // the loop will run only if starting index is less than or equal to the ending index
            if(arr[midIndex] == k){ // if the element at mid index is equal to the key, then return the index
                ans = midIndex;
                return ans;
            }
            else if(arr[midIndex] < k){ // if the element at mid index is lesser than the key, it means the key is present in the next half of the array. So the starting index pointer is to be shifted to mid index + 1
                s = midIndex + 1;
            }
            else{
                e = midIndex - 1; // if the element at mid index is greater than the key, it means the key is present in the prior half of the array. So the ending index pointer is to be shifted to mid index - 1
            }
            midIndex = s + ((e-s)/2); // calculating the midIndex for the new obtained array
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends