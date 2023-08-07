//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string s) {
        // *-A/BC-/AKL
        // ak/l- bc/
        
        stack<string> st;
        
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]=='^' or s[i]=='/' or s[i]=='*' or s[i]=='+' or s[i]=='-'){
                string first = st.top();
                st.pop();
                string second = st.top();
                st.pop();
                string ans = first+second+s[i];
                st.push(ans);
            }
            else{
                string temp ="";
                temp+=s[i];
                st.push(temp);
            }
        }
        
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends