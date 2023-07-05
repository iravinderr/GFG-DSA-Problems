//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* &head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node* newHead = reverse(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
    
    Node* add(Node* head){
        int carry = 1;
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while(head != NULL){
            int sum = head->data + carry;
            
            int digit = sum%10;
            Node* newNode = new Node(digit);
            temp->next = newNode;
            temp = temp->next;
            
            carry = sum/10;
            
            head = head->next;
        }
        
        while(carry != 0){
            int sum = carry;
            
            int digit = sum%10;
            Node* newNode = new Node(digit);
            temp->next = newNode;
            temp = temp->next;
            
            carry = sum/10;
        }
        
        return ans->next;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        head = reverse(head);
        
        Node* ans = add(head);

        ans = reverse(ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends