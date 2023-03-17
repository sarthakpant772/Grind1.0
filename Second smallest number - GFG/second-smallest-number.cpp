//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int s, int d){
        // code here 
        
        if(s==1 || d==1)
            return "-1";
            
        if(s>=9*d)
            return "-1";
        
        
        string ans(d,'0');
        
        int sum = s;
        
        int last =-1;
        
        for(int i=d-1;i>=0;--i){
            if(sum>9){
                ans[i]='9';
                sum-=9;
            }
            else if(sum>0){
                ans[i]='0'+sum;
                last =i;
                sum=0;
            }
            else{
                ans[i]='0';
            }
        }
        
        if(ans[0]=='0'){
            ans[0]='1';
            ans[last]-=1;
        }
        
        
        // cout<<ans<<endl;
        int l = d-2;
        while(ans[l]=='9')l--;;
        ans[l]+=1;
        ans[l+1]-=1;
        
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends