class Solution {
public:
    int n;
    int t[1001][1001];

    int solve1(vector<vector<int>>& grid){
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += grid[i][i];
            grid[i][i] = 0;
        }
        return ans;
    }

    int solve2(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || i >= n || j < 0 || j >= n) return 0;
        if(i >= j) return 0;
        if(i == n-1 && j == n-1) return 0;

        if(t[i][j] != -1) return t[i][j];

        int left = grid[i][j] + solve2(i+1, j-1, grid);
        int mid = grid[i][j] + solve2(i+1, j, grid);
        int right = grid[i][j] + solve2(i+1, j+1, grid);

        return t[i][j] = max({left, mid, right});
    }

    int solve3(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || i >= n || j < 0 || j >= n) return 0;
        if(j >= i) return 0;
        if(i == n-1 && j == n-1) return 0;

        if(t[i][j] != -1) return t[i][j];

        int top = grid[i][j] + solve3(i-1, j+1, grid);
        int mid = grid[i][j] + solve3(i, j+1, grid);
        int right = grid[i][j] + solve3(i+1, j+1, grid);

        return t[i][j] = max({top, mid, right});
    }

    int maxCollectedFruits(vector<vector<int>>& grid) {
        n = grid.size();

        int ans1 = solve1(grid);

        memset(t,-1,sizeof(t));
        int ans2 = solve2(0, n-1, grid);

        memset(t,-1,sizeof(t));
        int ans3 = solve3(n-1, 0, grid);

        return ans1 + ans2 + ans3;
    }
};