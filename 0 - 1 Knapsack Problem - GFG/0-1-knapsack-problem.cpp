//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    int dp[1010][1010];
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int recur(int W , int wt[] , int val[] , int i , int cost, int n){
        if(i>=n){
            return 0;
        }
        
        int temp=0;
        if(W>=wt[i]){
            temp+=val[i]+recur(W-wt[i] ,wt ,val  ,i+1 , cost+val[i],n);
        }
        
        return max(temp,(recur(W , wt ,val , i+1 , cost ,n)));

    }
    int memo(int W , int wt[] , int val[] ,int n){
        
      
        if(W==0 || n==0)
            return 0;
        
        
        if(dp[n][W]!=-1)
            return dp[n][W];
    
        
        if(W>=wt[n-1]){
            return dp[n][W]= max((val[n-1]+memo(W-wt[n-1] , wt, val , n-1)) , memo(W , wt , val , n-1) );
        }
        else{
            return dp[n][W] = memo(W,wt,val,n-1);
        }
      
    }
    
    
    
    int  Tab(int W, int wt[], int val[], int n){
        
        
        for(int i=0;i<=n;++i){
            for(int j=0;j<=W;++j){
                if(i==0||j==0)
                    dp[i][j]=0;
            }
        }
        
        
        for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++){
            if(wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j-wt[i-1]] + val[i-1], dp[i-1][j]);
        }
    }
        
        return dp[n][W];
        
    }
 
    int knapSack(int W, int wt[], int val[], int n) 
    {
        memset(dp, -1, sizeof(dp)); 
        return Tab(W,wt,val,n);
        
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends