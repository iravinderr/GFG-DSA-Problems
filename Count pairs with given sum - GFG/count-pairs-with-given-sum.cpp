//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int ctr = 0;
        map<int, int> present;
        // for(int i=0; i<n-1; i++){
        //     for(int j=i+1; j<n; j++){
        //         if(arr[i] + arr[j] == k){
        //             ctr++;
        //         }
        //     }
        // }
        
        for(int i=0; i<n; i++){
            present[arr[i]]++;
        }
        
        for(int i=0; i<n; i++){
            ctr += present[k-arr[i]];
            
            if(k-arr[i] == arr[i]){
                ctr--;
            }
        }
        
        return ctr/2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends