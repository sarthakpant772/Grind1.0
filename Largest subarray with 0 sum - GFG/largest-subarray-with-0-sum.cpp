//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        
        vector<int> pre(n,0);
        map<int,int> mp;
        pre[0] = A[0];
        mp[A[0]] = 0;
        int ans =0;
        if(pre[0]==0)
            ans = 1;
        for(int i=1;i<n;++i){
            pre[i] = A[i]+pre[i-1];
            
            if(pre[i] ==0 ){
                ans = max(ans , i+1);
            }
            
            if(mp.count((pre[i]))){
                ans = max( ans , i - mp[pre[i]]);
            }
            
            if(mp.count(pre[i])){
                continue;
            }
            
            mp[pre[i]]=i;
            
        }   
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
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends