//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int help(int arr[] , int n, int sum , int i , int x , vector<vector<int>> &dp){
	    int mod = 1e9+7;
	    if(i>=n){
	        if(sum==x){
	            return 1;
	        }
	        return 0;
	    }
	    int l =0 , r=0;
	    
	    if(dp[i][x]!=-1){
	        return dp[i][x];
	    }
	    
	    if(x+arr[i]<=sum){
	        l=help(arr,n,sum,i+1,x+arr[i],dp)%mod;
	    }
	    r=help(arr,n,sum,i+1,x,dp)%mod;
	    return dp[i][x]=  (l+r)%mod;
	    
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
      
        return help(arr,n,sum,0,0,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends