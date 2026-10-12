class Solution {
public:
    int n;
    int dp[12][10001];

    int solve(int idx, vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(idx >= n || amount < 0) return 1e9;

        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }

        int take = 1 + solve(idx, coins, amount-coins[idx]);
        int not_take = solve(idx+1, coins, amount);

        return dp[idx][amount] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        memset(dp,-1,sizeof(dp));
        
        int ans = solve(0, coins, amount);
        return ans >= 1e9 ? -1 : ans;  
    }
};