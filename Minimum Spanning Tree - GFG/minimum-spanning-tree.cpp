//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjoint{
  
  vector<int> size , parent;
  
  public:
  
  Disjoint(int n){
      size.resize(n , 0);
      
      parent.resize(n);
      for(int i=0;i<n;++i){
          parent[i]=i;
      }
  }
  
  
  int findParent(int i){
      if(i == parent[i])
        return i;
        
        return parent[i] = findParent(parent[i]);
  }
  
  
  void unionBySize(int u , int v){
      
      int pu = findParent(u);
      int pv = findParent(v);
      
      if(pu == pv)
        return ;
        
        
      if(size[pu]> size[pv] ){
          parent[pv] = pu;
          size[pu]+=size[pv];
      }
      else{
          parent[pu]= pv;
          size[pv]+=size[pu];
      }
  }
  
    
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        Disjoint dis(V);
        vector<pair<int ,pair<int ,int>>> vp;
        
        for(int i=0;i<V;i++) {
            for(auto it:adj[i]) {
                int adjnode = it[0];
                int wt = it[1];
                int node = i;
                
                vp.push_back({wt,{node,adjnode}});
            }
        }
        
        sort(vp.begin() , vp.end());
        
        int ans =0;
        for(auto it: vp){
            int d = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(dis.findParent(u)!=dis.findParent(v)){
                dis.unionBySize(u , v);
                ans+=d;
            }
        }
        
        return  ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends