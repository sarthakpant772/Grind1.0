//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &cost) {
        // write your code here
        if(cost.size()==1 and cost[0].size()==1)
            return cost[0][0];
        if(cost[0].size()==1)
            return -1;
            
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> k;
        for(int i=0;i<cost[0].size();++i){
            k.push({cost[0][i],i});
        }
        
        int N = cost.size();    
            // cout<<k.top().first;
        for(int i=1;i<N;++i){
            priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> check;
            pair<int,int> x , y;
            x = k.top();
            k.pop();
            y= k.top();
            k.pop();
            
            for(int j=0;j<cost[0].size();++j){
                if(j!= x.second){
                    check.push({cost[i][j]+x.first,j});
                }
                else{
                    check.push({cost[i][j]+y.first,j});
                }
            }
            k=check;
            
            // cout<<x<<" "<<y<<" "<<z<<endl;
            
            
          
        }
        
        return k.top().first;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends