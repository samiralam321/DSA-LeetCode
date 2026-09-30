class Solution {
public:
    double dp[26][26][105];

    double solve(int n, int row, int col, int k){
        if(row < 0 || row >=n || col < 0 || col >= n){
            return 0;
        }
        if(k == 0) return 1;

        if(dp[row][col][k] != -1){
            return dp[row][col][k];
        }

        vector<pair<int,int>> dir = {
            {-2,-1},
            {-2,1},
            {-1,-2},
            {-1,2},
            {1,-2},
            {1,2},
            {2,-1},
            {2,1}
        };

        double ans = 0;
        for(auto it : dir){
            int newRow = row + it.first;
            int newCol = col + it.second;

            ans += solve(n,newRow, newCol, k-1);
        }
        return dp[row][col][k] = ans / 8.0;
    }
    double knightProbability(int n, int k, int row, int column) {
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                for(int x=0; x<105; x++){
                    dp[i][j][x] = -1.0;
                }
            }
        }
        return solve(n,row,column,k);   
    }
};