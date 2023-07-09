//{ Driver Code Starts
#include <bits/stdc++.h>

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

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    
    Node* merge(Node* l1 , Node* l2){
        
        Node* temp = new Node(0);
        Node* cur = temp;
        
        while(l1 and l2){
            if(l1->data < l2->data){
                cur->next = l1;
                l1=l1->next;
            }
            else{
                cur->next = l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        
        if(l1!=NULL){
            cur->next = l1;
        }
        if(l2){
            cur->next = l2;
        }
        
        return temp->next;
        
    }
    
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        
        if(!head || !head->next)
            return head;
        
        Node* temp=NULL , *slow = head , *fast= head;
        
        while(fast and fast->next){
            temp = slow;
            slow=slow->next;
            fast = fast->next->next;
        }
        
        temp->next = NULL;
        
        Node* l1 = segregate(head);
        Node* l2 = segregate(slow);
        
       return  merge(l1,l2);
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends