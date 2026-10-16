class Solution {
public:
    const int mod = 1e9 + 7;
    int m,n;
    vector<vector<int>> dp;

    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    int solve(int r, int c, vector<vector<int>>& grid){
        if(dp[r][c] != -1) {
            return dp[r][c];
        }

        int ways = 1;
        for(auto d : dir){
            int nr = r + d.first;
            int nc = c + d.second;

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > grid[r][c]){
                ways = (ways + solve(nr, nc, grid)) % mod;
            }
        }

        return dp[r][c] = ways;
    }

    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<int>(n, -1));

        int ans = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = (ans + solve(i, j, grid)) % mod;
            }
        }
        return ans;
    }
};
