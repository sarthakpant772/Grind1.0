//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    void flush(vector<int> & a){
        for(int i=0;i<a.size();++i){
            a[i]=0;
        }
    }
  
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        vector<int> a(26,0);
        vector<Node*> ans;
        // while(head!=NULL){
        //     a.push_back(head);
        //     head=head->next;
        // }
        
        vector<int> check(26,0) , tag(26,0);
        
        for(int i=0;i<s.size();++i){
            tag[s[i]-'a']++;
            // check[a[i]->data-'a']++;
        }
        
        Node *prev=head , *cur=head , *justprev=NULL;
        
        
        int c=0;
        
        while(cur){
            if(c<s.size()){
                a[cur->data-'a']++;
                c++;
            }
            else{
                if(a==tag){
                    ans.push_back(prev);
                    justprev->next = NULL;
                    justprev=NULL;
                    prev = cur;
                    flush(a);
                    if(!cur){
                        break;
                    }
                    c=1;
                    a[cur->data-'a']++;
                }
                else{
                    a[prev->data-'a']--;
                    a[cur->data-'a']++;
                    prev=prev->next;
                }
            }
            
            justprev=cur;
            cur=cur->next;
        }
        
        
        if(a==tag){
            ans.push_back(prev);
            justprev->next=NULL;
            justprev=NULL;
        }
        
        
        
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends