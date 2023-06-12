//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
        
        int MOD = 1e9+7;
        int mod = 1e9+7;
	public:
	
	int recur(int arr[] , int n , int sum){     
	   if(n==0){
            
            if(sum==0){
                return 1;
            }
            return 0;
	        
	   }
	        
	   if(arr[n-1]>sum){
	       return recur(arr,n-1,sum)%MOD;
	   }
	   else {
	       return (recur(arr,n-1,sum-arr[n-1])%MOD+recur(arr,n-1,sum)%MOD)%MOD;
	   }
	}
	
	int memo(int arr[] , int n , int sum , vector<vector<int>> &dp){
	    
	    if(n==0){
	        if(sum==0){
	            return 1;
	        }
	        return 0;
	    }
	    
	    if(dp[n][sum]!=-1){
	        return dp[n][sum];
	    }
	    
	   if(arr[n-1]>sum){
	       return dp[n][sum]=memo(arr,n-1,sum,dp)%MOD;
	   }
	   else {
	       return dp[n][sum]=(memo(arr,n-1,sum-arr[n-1],dp)%MOD+memo(arr,n-1,sum,dp)%MOD)%MOD;
	   }
	   
	   
	    
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1 , vector<int>(sum+1,-1));
        return memo(arr,n,sum,dp);
        
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