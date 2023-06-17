//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    
    void bfs(vector<vector<int>> &grid , int i , int j,vector<pair<int,int>> &vec ){
        
        queue<pair<int,int>> q;
        
        q.push({i,j});
        grid[i][j]=-1;
        vector<pair<int,int>> vp={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto val = q.front();
            vec.push_back({val.first-i , val.second-j});
            q.pop();
            for(auto it:vp){
                int a = val.first+it.first;
                int b = val.second +it.second;
                if(a>=0 and b>=0 and a<grid.size() and b<grid[0].size() and grid[a][b]==1){
                    q.push({a,b});
                    grid[a][b]=-1;
                }
            }
        }
        
    }
    
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int ans =0;
        set<vector<pair<int,int>>> st;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                
                if(grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    bfs(grid , i , j,vec);
                    st.insert(vec);
                    // break;
                }
            }
        }
        
        
        // for(int i=0;i<grid.size();++i){
        //     for(int j=0;j<grid[0].size();++j){
                
        //       cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends