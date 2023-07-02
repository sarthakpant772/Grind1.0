//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int help(vector<vector<int>> &grid , int i ,int j, vector<vector<int>> &dp){
        if(i<0 or j<0 or i>=grid.size() or j>=3){
            return 0;
        }
        
        if(i==grid.size()-1){
            return grid[i][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans =-1;
        
        for(int k=0;k<3;++k){
            if(k!=j){
                ans = max(ans , help(grid,i+1,k,dp));
            }
        }
        return dp[i][j]=ans+grid[i][j];
        
    }
    
    int maximumPoints(vector<vector<int>>& grid, int n) {
        // Code here
        vector<vector<int>> dp(n , vector<int>(3,-1));
        
        
        return max(max(help(grid , 0 , 0 , dp),help(grid , 0 , 1 , dp)),help(grid , 0 , 2 , dp));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends