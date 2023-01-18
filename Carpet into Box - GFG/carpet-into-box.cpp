//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int solve(int a , int b , int c, int d){
        if(a<=c and b<=d)
            return 0;
        
        if(a>c) return 1+ solve(floor(a/2),b,c,d);
        if(b>d) return 1+ solve(a,floor(b/2),c,d);
    }
    int carpetBox(int a, int b, int c, int d){
        //code here
       
        
        
        
        return min(solve(a,b,c,d),solve(a,b,d,c));
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends