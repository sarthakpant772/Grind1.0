//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int start =-1 , end=-1;
	    
	    
	    int l =0 , r=n-1;
	    
	    while(l<=r){
	        int mid = (l+r)/2;
	        
	        if(arr[mid]>x){
	            r= mid-1;
	        }
	        else if(arr[mid]<x){
	            l=mid+1;
	        }
	        else{
	            start = mid;
	            r = mid-1;
	        }
	    }
	    
	    if(start==-1)
	        return 0;
	        
	   l=0  , r=n-1;
	   
	    while(l<=r){
                int mid = (l+r)/2;
    	        
    	        if(arr[mid]>x){
    	            r= mid-1;
    	        }
    	        else if(arr[mid]<x){
    	            l=mid+1;
    	        }
    	        else{
    	            end = mid;
    	            l = mid+1;
    	        }
	    } 
	   // cout<<start<<" "<<end<<endl;
	    return end-start+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends