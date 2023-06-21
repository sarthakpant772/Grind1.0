//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    int flo =-1 , cei=-1;
    
    int l = 0 , r = n-1;
    sort(arr, arr+n);
    while(l<=r){
        int mid = (l+r)/2;
        if(x>arr[mid]){
            flo = arr[mid];
            l = mid+1;
        }
        else if(x<arr[mid]){
            cei=arr[mid];
            r=mid-1;
        }
        else{
            return {arr[mid] ,arr[mid]};
        }
        
    }
    
    
    return {flo , cei};
}