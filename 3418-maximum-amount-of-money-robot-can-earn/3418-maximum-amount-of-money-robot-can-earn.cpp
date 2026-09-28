class Solution {
public:
    int m,n;
    int t[501][501][3];

    int solve(int i,int j,vector<vector<int>>& coins,int neutra){
        if(i>=m || j>=n) return -1e9;

        if(t[i][j][neutra] != -1e9){
            return t[i][j][neutra];
        }

        if(i == m-1 && j == n-1){
            if(coins[i][j] < 0 && neutra > 0){
                return t[i][j][neutra] = 0;
            }
            return t[i][j][neutra] = coins[i][j];
        }
        int take = coins[i][j] + max(
            solve(i+1,j,coins,neutra),
            solve(i,j+1,coins,neutra)
        );

        int skip = -1e9;
        if(coins[i][j] < 0 && neutra > 0){
            int skipDown = solve(i+1,j,coins,neutra-1);
            int skipRight = solve(i,j+1,coins,neutra-1);

            skip = max(skipDown,skipRight);
        }
        return t[i][j][neutra] = max(take,skip);
    }

    int maximumAmount(vector<vector<int>>& coins){
        m = coins.size();
        n = coins[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<3;k++){
                    t[i][j][k] = -1e9;
                }
            }
        }
        return solve(0,0,coins,2);
    }
};