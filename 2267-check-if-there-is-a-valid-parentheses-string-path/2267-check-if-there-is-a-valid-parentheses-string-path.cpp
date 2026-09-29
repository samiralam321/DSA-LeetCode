class Solution {
public:
    int m,n;
    int t[105][105][205];

    bool solve(vector<vector<char>>& grid,int i,int j,int open,int close){
        if(i >= m || j >= n) return false;

        if(grid[i][j] == '(') open++;
        else close++;

        if(close > open) return false;

        if(i == m-1 && j == n-1) return open == close;

        if(t[i][j][open] != -1){
            return t[i][j][open];
        }

        bool right = solve(grid, i, j+1, open, close);
        bool down = solve(grid,i+1, j, open, close);

        return t[i][j][open] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if((m+n-1) % 2 != 0) return false;

        memset(t,-1,sizeof(t));
        return solve(grid,0,0,0,0);
    }
};