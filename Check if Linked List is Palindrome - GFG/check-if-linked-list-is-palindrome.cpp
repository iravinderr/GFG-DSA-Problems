//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

#include <vector>

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverse(Node* &head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node* newHead = reverse(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        // int length = 1;
        // Node* temp = head;
        // while(temp->next != NULL){
        //     temp = temp->next;
        //     length++;
        // }
        
        // int firstHalf = length - (length/2);
        
        // temp = head;
        // int ctr=1;
        // while(ctr != firstHalf){
        //     temp = temp->next;
        // }
        
        
        // // Node* secondHead = reverse(temp->next);
        // temp->next = reverse(temp->next);
        
        // Node* ptr1 = head;
        // Node* ptr2 = temp->next;
        
        // while(ptr1 != temp && ptr2 != NULL){
        //     if(ptr1->data != ptr2->data){
        //         return false;
        //     }
        //     ptr1 = ptr1->next;
        //     ptr2 = ptr2->next;
        // }
        
        // return true;
        
        vector<int> values;
        Node* temp = head;
        while(temp != NULL){
            values.push_back(temp->data);
            temp = temp->next;
        }
        
        int i=0, j=values.size()-1;
        while(i < j){
            if(values.at(i) != values.at(j)){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends