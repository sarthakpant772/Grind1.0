//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n+1 , 1) , hash(n+1);
        
        for(int i=0;i<n;++i){
            hash[i]=i;
        }
        
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(arr[j]<arr[i] and dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
        }
        
        int len =0;
        int ind =-1;
        for(int i=0;i<n;++i){
            if(dp[i]>len){
                len = dp[i];
                ind = i;
            }
        }
        
        vector<int> temp;
         temp.push_back(arr[ind]);
        
        while(hash[ind]!=ind){
            ind = hash[ind];
            temp.push_back(arr[ind]);
        }
        
        reverse(temp.begin() , temp.end());
        
        return temp;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends