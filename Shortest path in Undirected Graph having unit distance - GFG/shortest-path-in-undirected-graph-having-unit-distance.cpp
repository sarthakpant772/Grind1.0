//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adj(N);
        vector<bool> vis(N,false);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
        vector<int> ans(N,INT_MAX);
        priority_queue<pair<int , int > , vector<pair<int , int >> , greater<pair<int , int >> > pq;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            vis[it.second]=true;
            ans[it.second]=min(ans[it.second] ,it.first);
            for(auto i:adj[it.second]){
                if(!vis[i]){
                    pq.push({it.first+1 , i});
                }
            }
        }
        
        for(auto &it: ans){
            if(it==INT_MAX){
                it=-1;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends