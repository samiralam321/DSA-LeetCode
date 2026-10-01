class Solution {
public:
    int dp[60];
    
    int solve(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        int result = INT_MIN;
        for(int i=1; i<n; i++){
            int product = i * max(n-i, solve(n-i));
            result = max(result, product);
        }
        return dp[n] = result;
    }

    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};