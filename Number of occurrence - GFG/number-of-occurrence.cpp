//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int x) {
	    // code here
	    int l = 0 , r = n-1;
	    int first=-1 , last=-1;
	    
	    while(l<=r){
	        int mid = (l+r)/2;
	        
	        if(nums[mid]>=x){
	            r=  mid-1;
	            first = mid;
	        }
	        else{
	            l = mid+1;
	        }
	        
	    }
	    
	    if(first!=-1){
	        l =0 , r = n-1;
	        while(l<=r){
	            int mid = (l+r)/2;
	            
	            if(nums[mid]<=x){
	                l =  mid+1;
	                last = mid;
	            }
	            else{
	                r = mid-1;
	            }
	        }
	        
	    }
	    else return 0;
	    
	    return (last - first)+1;
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