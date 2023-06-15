//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // code here
        
        if(N <= 1){
            return 0;
        }
        
        int i=2;
        int noOfSquares = 1;
        while(i*i < N){
            noOfSquares++;
            i++;
        }
        
        return noOfSquares;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends