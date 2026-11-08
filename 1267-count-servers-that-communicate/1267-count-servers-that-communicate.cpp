class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> cntRow(m,0);
        vector<int> cntCol(n,0);

        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 1){
                    cntRow[row] += 1;
                    cntCol[col] += 1;
                }
            }
        }
        int ans = 0;
        for(int row=0; row<m; row++){
            for(int col = 0; col<n; col++){
                if(grid[row][col] == 1 && (cntRow[row] > 1 || cntCol[col] > 1)){
                    ans++;
                }
            }
        }
        return ans;  
    }
};