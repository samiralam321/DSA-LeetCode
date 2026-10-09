
class Solution {
public:
    int m,n;
    int t[71][71][71];
    vector<int> colDir = {-1,0,1};

    bool isSafe(int col){
        return col >= 0 && col < n;
    }

    int solve(vector<vector<int>>& grid, int row, int c1, int c2){

        if(row == m){
            return 0;
        }

        if(t[row][c1][c2] != -1){
            return t[row][c1][c2];
        }

        int cherries = grid[row][c1];

        if(c1 != c2){
            cherries += grid[row][c2];
        }

        int ans = 0;
        for(int x : colDir){
            for(int y : colDir){
                int nextC1 = c1 + x;
                int nextC2 = c2 + y;

                if(isSafe(nextC1) && isSafe(nextC2)){
                    int next = solve(grid, row+1, nextC1, nextC2);
                    ans = max(ans, next);
                }
            }
        }
        return t[row][c1][c2] = cherries + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(t, -1, sizeof(t));
        return solve(grid, 0, 0, n-1);
    }
};
