//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        
        int count=0;
        
        for(int i=0;i<S.size();++i){
            int cap =0,sma=0;
            if(S[i]>='A' and S[i]<='Z'){
                cap++;
            }
            else if(S[i]>='a' and S[i]<='z'){
                sma++;
            }
            for(int j=i+1;j<S.size();++j){
            if(S[j]>='A' and S[j]<='Z'){
                cap++;
            }
            else if(S[j]>='a' and S[j]<='z'){
                sma++;
            }
            
            
            if(cap==sma){
                count++;
            }
            
            
            }
        }
        
        return count;
        // code here
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends