//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        int i=0,j=0;
        string g="right";
        int previ=0,prevj=0;
        while(i>=0 and i<matrix.size() and j>=0 and j<matrix[0].size()){
            if(matrix[i][j]==1){
                if(g=="right"){
                    g="down";
            }
            else if(g=="left"){
                g="up";
            }else if(g=="up"){
                g="right";
            }
            else{
                g="left";
            }
            }
            
            previ=i;
            prevj=j;
            matrix[i][j]=0;
            if(g=="right"){
                j++;
            }
            else if(g=="left"){
                j--;
            }else if(g=="up"){
                i--;
            }
            else{
                i++;
            }
            
            
            
        }

        return {previ,prevj};
        
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends