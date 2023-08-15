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
        
        vector<int> dis(N, INT_MAX);
        vector<vector<int>> graph(N);
        
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        // int d =0;
        queue<pair<int , int>> q;
        
        q.push({src , 0});
        dis[src]=0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int i =q.front().first;
                int d = q.front().second;
                q.pop();
                
                for(auto it:graph[i]){
                    if(dis[it]==INT_MAX){
                        dis[it] = min(dis[it] , d+1);
                        q.push({it , dis[it]});
                        
                    }
                }
            }
        }
        
        for(auto &it: dis){
            if(it ==INT_MAX){
                it = -1;
            }
        }
        
        return dis;
        
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