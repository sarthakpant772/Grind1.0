//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int dp[1001][1001];
	public:
	    
	    int recur(string &s1 , string &s2 , int n , int m){
	        if(n==0 || m==0)
	            return 0;
	            
	        if(s1[n-1]==s2[m-1] and n!=m){
	            return recur(s1 , s2, n-1 , m-1)+1;
	        }
	        else{
	            return max(recur(s1 , s2, n-1, m) , recur(s1 , s2 , n , m-1));
	        }
	    }
	    
	    int memo(string &s1 , string &s2 , int n , int m){
	        if(n==0 || m==0)
	            return 0;
	            
	       if(dp[n][m]!=-1)
	            return dp[n][m];
	            
	        if(s1[n-1]==s2[m-1] and n!=m){
	            return  dp[n][m]= memo(s1 , s2, n-1 , m-1)+1;
	        }
	        else{
	            return dp[n][m]= max(memo(s1 , s2, n-1, m) , memo(s1 , s2 , n , m-1));
	        }
	    }
	    
	    
	
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    memset(dp , -1 , sizeof(dp));
		    return memo(str , str , n , n );
		    
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends