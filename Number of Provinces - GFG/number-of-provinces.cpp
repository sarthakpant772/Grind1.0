//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    void dfs(vector<vector<int>> &adj , int i , vector<int> &vis){
        
        if(vis[i]!=-1)
            return;
            
        vis[i]=1;
        for(auto it: adj[i]){
            if( vis[it]==-1)
                dfs(adj , it , vis);
        }   
        
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int n = adj.size();
        int m = adj[0].size();
        vector<int> vis(V+1 , -1);
        
        vector<vector<int>> graph(V+1);
        
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(adj[i][j]==1){
                    graph[i+1].push_back(j+1);
                    graph[j+1].push_back(i+1);
                }
            }
        }
        int ans =0;
       for(int i=1;i<=V;++i){
           if(vis[i]==-1){
               ans++;
               dfs(graph , i , vis);
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends