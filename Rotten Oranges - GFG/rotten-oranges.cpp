//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
    int x[] = {0, 0, -1, 1};
    int y[] = {-1, 1, 0, 0};
    queue<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();
    int totalTomato = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            }
            if (grid[i][j] == 1) {
                totalTomato++;
            }
        }
    }

    int cost = 0;
    while (!q.empty()) {
        int size = q.size();
        bool flag = false; // flag to track if any orange rots in this iteration
        while (size--) {
            auto it = q.front();
            q.pop();
            int px = it.first;
            int py = it.second;

            for (int i = 0; i < 4; ++i) {
                int nx = px + x[i];
                int ny = py + y[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                    q.push({nx, ny});
                    grid[nx][ny] = 2; // mark the adjacent orange as rotten
                    totalTomato--;
                    flag = true; // set flag to true as an orange rotted
                }
            }
        }
        if (flag) {
            cost++; // increment the cost only if any orange rotted in this iteration
        }
    }

    return totalTomato == 0 ? cost : -1;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends