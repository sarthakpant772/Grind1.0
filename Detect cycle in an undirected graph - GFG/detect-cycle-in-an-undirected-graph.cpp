//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfs(vector<int> adj[] , vector<int> &vis , int i , int parent){
        
    
        vis[i]=1;
        
        for(auto it: adj[i]){
           if(vis[it]==-1){
               if(dfs(adj , vis , it , i)){
                   return true;
               }
           }
           else if(it!=parent){
               return true;
           }
        }
        
        return false;
    }
    
    
    bool bfs(vector<int> adj[] , vector<int> &vis, int i){
        unordered_map<int,int> mp;
        mp[i]=-1;
        vis[i]=1;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            for(auto it: adj[x]){
                if(vis[it]==-1){
                    vis[it]=1;
                    q.push(it);
                    mp[it]=x;
                }
                else{
                    if(it!=mp[x]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V+1,-1);
        
        for(int i=0;i<V;++i){
            if(vis[i]==-1){
                if(bfs(adj , vis , i)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends