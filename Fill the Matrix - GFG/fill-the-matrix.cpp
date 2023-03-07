//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        vector<vector<int>> mat (N,vector<int> (M,0));
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        mat[x-1][y-1]=1;
        
        queue<pair<pair<int,int>,int>> q;
        
        q.push({{x-1,y-1},0});
        
        int ans =0;
        while(!q.empty()){
            
            auto it  = q.front();
            ans = it.second;
            q.pop();
            
            for(int i=0;i<4;++i){
                if(it.first.first+dx[i]>=0 and it.first.first+dx[i]<N and it.first.second+dy[i]>=0 and it.first.second+dy[i]<M and mat[it.first.first+dx[i]][it.first.second+dy[i]]!=1){
                    mat[it.first.first+dx[i]][it.first.second+dy[i]]=1;
                    q.push({{it.first.first+dx[i] ,it.first.second+dy[i]}, it.second+1});
                }
            }
            
        }
        
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends