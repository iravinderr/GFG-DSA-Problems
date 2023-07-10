//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isSafe(vector<vector<int>> &m, int n, int row, int col, vector<vector<bool>>& visited){
        if((row >= 0 && row < n) && (col >= 0 && col < n) && m[row][col] == 1 && visited[row][col] != 1){
            return true;
        }
        
        return false;
    }
    
    void solve(vector<vector<int>> &m, int n, int row, int col, string path, vector<string>& ans,
    vector<vector<bool>>& visited){
        
        if(row == n-1 && col == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[row][col] = true;
        
        // DOWN
        if(isSafe(m, n, row+1, col, visited)){
            solve(m, n, row+1, col, path + 'D', ans, visited);
        }
        
        // LEFT
        if(isSafe(m, n, row, col-1, visited)){
            solve(m, n, row, col-1, path + 'L', ans, visited);
        }
        
        // RIGHT
        if(isSafe(m, n, row, col+1, visited)){
            solve(m, n, row, col+1, path + 'R', ans, visited);
        }

        // UP
        if(isSafe(m, n, row-1, col, visited)){
            solve(m, n, row-1, col, path + 'U', ans, visited);
        }
        
        visited[row][col] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0] == 0){
            return ans;
        }
        
        string path;
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        
        solve(m, n, 0, 0, path, ans, visited);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends