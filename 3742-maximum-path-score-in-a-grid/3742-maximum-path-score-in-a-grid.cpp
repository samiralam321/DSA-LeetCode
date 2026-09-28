class Solution {
public:
    int m,n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int i, int j, int k, int cost){
        if(i>=m || j>=n){
            return INT_MIN;
        }
        int newCost = cost + (grid[i][j] > 0 ? 1 : 0);

        if(newCost > k){
            return INT_MIN;
        }

        if(dp[i][j][newCost] != -1){
            return dp[i][j][newCost];
        }

        if(i == m-1 && j == n-1){
            return dp[i][j][newCost] = grid[i][j];
        }

        int right = solve(grid, i, j+1, k, newCost);
        int down = solve(grid, i+1, j, k, newCost);

        int bestNext = max(right, down);

        if(bestNext == INT_MIN){
            return dp[i][j][newCost] = INT_MIN;
        }
        return dp[i][j][newCost] = grid[i][j] + bestNext;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        dp.resize(m, vector<vector<int>>(n, vector<int>(k+1, -1)));

        int result = solve(grid, 0, 0, k, 0);
        return result == INT_MIN ? -1 : result;
    }
};