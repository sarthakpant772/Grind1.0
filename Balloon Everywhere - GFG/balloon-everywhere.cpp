//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        string k = "balloon";
        vector<int> check(26,0);
        for(int i=0;i<s.size();++i){
            check[s[i]-'a']++;
        }
        int ans = INT_MAX;
        for(int i=0;i<k.size();++i){
            if(k[i]=='o' || k[i]=='l')
            ans=min(ans,check[k[i]-'a']/2);
            else
            ans=min(ans,check[k[i]-'a']);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends