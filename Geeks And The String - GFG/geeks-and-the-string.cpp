//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();++i){
            if(st.empty()){
                st.push(s[i]);
                
            }
            else
            if(s[i]!=st.top()){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        
        string g;
        while(!st.empty()){
            g+=st.top();
            st.pop();
        }
        
        reverse(g.begin(),g.end());
        return g.size()==0?"-1":g;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends