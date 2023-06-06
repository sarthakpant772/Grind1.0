//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        vector<pair<int,int>> vp;
        int dead = 0;
        for(int i =0 ;i<n;++i){
            vp.push_back({arr[i].profit,arr[i].dead});
            dead = max(dead ,arr[i].dead);
        }
        
        
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        int count=0 , profit =0;   
        
        
        vector<int> temp (dead+1 , 0);
        
        
        for(auto it:vp){
            
            int i=it.second;
            
            
            while(i>=1){
                if(temp[i]==0){
                    temp[i]=1;
                    profit+=it.first;
                    count++;
                    
                    // cout<<it.first<<" "<<it.second<<endl;
                    break;
                }
                    i--;
            }
        }
        
        
        
        
        return {count , profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends