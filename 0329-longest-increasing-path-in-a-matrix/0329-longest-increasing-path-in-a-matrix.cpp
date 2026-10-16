class Solution {
public:
    int m,n;
    int dp[201][201];
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    bool isSafe(int i,int j){
        return (i>=0 && i<m && j>=0 && j<n);
    }

    int solve(int i, int j, vector<vector<int>>& matrix){

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 1;

        for(auto dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(isSafe(i_,j_) && matrix[i_][j_] > matrix[i][j]){
                int path = 1 + solve(i_,j_,matrix);
                ans = max(ans,path);
            }
        }
        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        int ans = 0;
        
        memset(dp,-1,sizeof(dp));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, solve(i,j,matrix));
            }
        }
        return ans;
    }
};