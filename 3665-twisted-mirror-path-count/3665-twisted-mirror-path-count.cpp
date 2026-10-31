class Solution {
public:
    int m, n;
    int MOD = 1e9 + 7;
    int t[501][501][2];

    int solve(vector<vector<int>>& grid, int i, int j, int cameFrom){
        if(i >= m || j >= n) return 0;
        if(i == m - 1 && j == n - 1) return 1;


        if(t[i][j][cameFrom] != -1){
            return t[i][j][cameFrom];
        }

        int ans = 0;

        if(grid[i][j] == 1){
            if(cameFrom == 0){
                ans = solve(grid, i+1, j, 1);
            }
            else{
                ans = solve(grid, i, j+1, 0);
            }
        }
        else{
            int right = solve(grid, i, j+1, 0);
            int down = solve(grid, i+1, j, 1);
            ans = (right + down) % MOD;
        }
        return t[i][j][cameFrom] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(t, -1, sizeof(t));
        return solve(grid, 0, 0, 0);
    }
};