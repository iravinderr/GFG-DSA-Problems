//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
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
    //Function to add two numbers represented by linked list.
    
    Node* add(Node* first, Node* second){
        
        Node* ans = new Node(-1);
        Node* temp = ans;
        int carry = 0;
        
        while(first != NULL && second != NULL){
            
            int sum = (first->data) + (second->data) + carry;
            
            int digit = sum%10;
            Node* newNode = new Node(digit);
            temp->next = newNode;
            temp = temp->next;
            
            carry = sum/10;
            
            first = first->next;
            second = second->next;
        }
        
        
        while(first != NULL){
            int sum = (first->data) + carry;
            
            int digit = sum%10;
            Node* newNode = new Node(digit);
            temp->next = newNode;
            temp = temp->next;
            
            carry = sum/10;
            first = first->next;
        }
        
        while(second != NULL){
            int sum = (second->data) + carry;
            
            int digit = sum%10;
            Node* newNode = new Node(digit);
            temp->next = newNode;
            temp = temp->next;
            
            carry = sum/10;
            second = second->next;
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
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        
        Node* ans = add(first, second);
        
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
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends