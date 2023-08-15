//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>> vp(N);
        
        for(auto it:edges){
            vp[it[0]].push_back({it[1] , it[2]});
        }
        
        vector<int> dis(N , INT_MAX);
        dis[0]=0;
        queue<int > q;
        q.push(0);
        
        while(!q.empty()){
            
            int n  = q.size();
            while(n--){
                int x = q.front();
                q.pop();
                
                for(auto it:vp[x]){
                    if(dis[it.first]>dis[x]+it.second){
                        q.push(it.first);
                        dis[it.first] = dis[x]+it.second;
                    }
                }   
            }
            
        }
        
        for(auto &it :dis){
            if(it == INT_MAX){
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends