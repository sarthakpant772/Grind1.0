//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> int_to_bin(int n){
            vector<int> binary;
            for(int i=31;i>=0;--i){
                int temp = ((n>>i)&1);
                binary.push_back(temp);
            }
            
            return binary;
        }
        
         int bin_to_int(vector<int> &bin){
            int ans = 0;
            for(int i=0;i<32;++i){
                ans = (ans<<1);
                // int_to_bin(ans);
                if(bin[i]>0){
                    // cout<<" i = "<<i<<" "<<bin[i]<<endl;
                    ans= ans+1;
                }
            }
            return ans;
        }
    
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            // code here
            vector<vector<int>> hash(N,vector<int>(32,0));
            for(int i=0;i<Q;++i){
                int l = U[i][0]-1;
                int r = U[i][1];
                int x = U[i][2];
                // cout<<x<<" ";
                vector<int> temp = int_to_bin(x);
                for(int j=0;j<32;++j){
                    hash[l][j] += temp[j];
                    if(r!=N)   hash[r][j] -= temp[j];
                }
            }
            vector<int> ans;
            vector<int> cur_bin(32,0);
            for(int i=0;i<N;++i){
                for(int j=0;j<32;++j){
                    // cout<<hash[i][j];
                    cur_bin[j] += hash[i][j];
                }
                // cout<<endl;
                // cout<<bin_to_int(cur_bin)<<"    ";
                ans.push_back(bin_to_int(cur_bin));
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
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends