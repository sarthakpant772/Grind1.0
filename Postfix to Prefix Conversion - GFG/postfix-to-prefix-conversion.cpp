//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack<string> st;
        
        for(auto it: post_exp){
            
            if(it=='^'||it=='*'||it=='/'||it=='+'||it=='-'){
                
                string x,y;
                
                if(!st.empty()){
                    x=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    y=st.top();
                    st.pop();
                }
                
                string temp = it+y+x;
                
                st.push(temp);
            }
            else{
                string temp ="";
                temp+=it;
                
                st.push(temp);
            }
            
        }
        if(!st.empty())
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends