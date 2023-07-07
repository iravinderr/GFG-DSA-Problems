//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(stack<int>& s, int x){
        if(s.size() == 0){
            s.push(x);
            return;
        }
        
        int val = s.top();
        s.pop();
        solve(s, x);
        s.push(val);
    }

    void Reverse(stack<int> &St){
        
        if(St.size() == 0){
            return;
        }
        
        int val = St.top();
        St.pop();
        Reverse(St);
        
        solve(St, val);
        
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends