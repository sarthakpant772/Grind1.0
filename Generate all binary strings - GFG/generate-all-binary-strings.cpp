//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void help(int n , string s , bool check){
        if(s.size()==n){
            cout<<s<<" ";
            return;
        }
        
        
        
        s+='0';
        help(n,s,false);
        s.pop_back();
        
        if(!check){
            s+='1';
            help(n,s,true);
            s.pop_back();
        }
        
        
    }
    void generateBinaryStrings(int num){
        //Write your code
        
        help(num ,"",false);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends