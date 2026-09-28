class Solution {
public:
    int m,n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int i, int j, int k, int cost){
        if(i>=m || j>=n){
            return -1e9;
        }

        int newCost = cost + (grid[i][j] > 0 ? 1 : 0);

        if(newCost > k){
            return -1e9;
        }

        if(i == m-1 && j == n-1){
            return grid[i][j];
        }

        if(dp[i][j][newCost] != -1){
            return dp[i][j][newCost];
        }

        int right = grid[i][j] + solve(grid, i, j+1, k, newCost);
        int down = grid[i][j] + solve(grid, i+1, j, k, newCost);

        return dp[i][j][newCost] = max(right, down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        dp.resize(m, vector<vector<int>>(n, vector<int>(k+1, -1)));

        int result = solve(grid, 0, 0, k, 0);

        return result < 0 ? -1 : result;
    }
};