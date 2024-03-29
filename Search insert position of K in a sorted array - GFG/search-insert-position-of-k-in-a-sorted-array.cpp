//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>arr, int N, int k)
    {
        // code here
        int l = 0  , r=N-1;
        int ans =N;
        while(l<=r){
            int mid = (l+r)/2;
            
            if(arr[mid]==k)
                return mid;
            if(arr[mid]>k){
                ans = mid;
                r = mid-1;
            }
            else{
                // ans = mid;
                l = mid+1;
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
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends