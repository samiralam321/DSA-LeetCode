class Solution {
public:
    long long n;
    long long dp[1000001];
    long long solve(vector<vector<int>>& questions, int i){
        if(i > n-1) return 0;

        if(dp[i] != -1){
            return dp[i];
        }

        long long take = questions[i][0] + solve(questions, i + questions[i][1] + 1); 
        long long skip = solve(questions, i+1);

        return dp[i] = max(take, skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        memset(dp, -1, sizeof(dp));
        return solve(questions, 0);
    }
};