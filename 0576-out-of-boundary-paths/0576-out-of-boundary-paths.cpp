class Solution {
public:
    int dp[50][50][51];
    int MOD = 1e9+7;

    long long solve(int m, int n, int row, int col, int moves){
        if(row < 0 || row >= m || col < 0 || col >= n) return 1;
        if(moves == 0) return 0;

        if(dp[row][col][moves] != -1){
            return dp[row][col][moves];
        }

        long long ans =
            solve(m, n, row-1, col, moves-1) +
            solve(m, n, row+1, col, moves-1) +
            solve(m, n, row, col-1, moves-1) +
            solve(m, n, row, col+1, moves-1);

        return dp[row][col][moves] = ans % MOD;
    }

    int findPaths(int m,int n,int maxMove,int startRow,int startColumn){
        for(int i=0;i<50;i++){
            for(int j=0;j<50;j++){
                for(int k=0;k<51;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(m, n, startRow, startColumn, maxMove);
    }
};