//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string s1="",s2="";
        
        for(int i=0;i<str.size();++i){
            if(str[i]>='a' and str[i]<='z'){
                s1+=str[i];
            }
            else{
                s2+=str[i];
            }
        }
        
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        int k=0;
        int i=0,j=0;
        string ans="";
        while(k<str.size()){
            if(str[k]>='a' and str[k]<='z'){
                ans+=s1[i++];
            }
            else{
                ans+=s2[j++];
            }
            k++;
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
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends