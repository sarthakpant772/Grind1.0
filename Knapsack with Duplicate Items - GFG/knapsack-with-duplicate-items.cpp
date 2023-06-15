//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int dp[1010][1010];
public:
    int recur(int val[] , int wt[] , int n , int W){
        
        if(n==0){
            return 0;
        }
        
        
        if(wt[n-1]>W){
            return recur(val,wt,n-1 ,W);
        }
        else{
            return max(recur(val,wt,n, W-wt[n-1])+val[n-1], recur(val,wt,n-1,W));
        }
        
        
    }
    
    int memo(int val[] , int wt[] , int n , int W){
        if(n==0){
            return 0;
        }
        
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        
        if(wt[n-1]>W){
            return dp[n][W]=memo(val , wt , n-1 , W);
        }
        else{
            return dp[n][W] = max(val[n-1]+memo(val , wt , n , W-wt[n-1]),memo(val , wt , n-1 , W));
        }
        
    }
    
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        
        return memo(val,wt,N,W);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends