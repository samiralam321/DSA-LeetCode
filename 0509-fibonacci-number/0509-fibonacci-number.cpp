class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n<=1) return n;

        if(dp[n] != -1){  // means if it is already solved
            return dp[n];  // so send the answer directly
        }
        return dp[n] = solve(n-1, dp) + solve(n-2, dp); // also store the result
    }
    int fib(int n) {


        vector<int> dp(n+1, -1);
        return solve(n,dp);
        
    }
};