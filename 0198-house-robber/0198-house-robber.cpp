class Solution {
public:
    int dp[101];
    int n;
    int solve(vector<int>& nums, int idx){
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int steal = nums[idx] + solve(nums, idx+2);
        int skip = solve(nums, idx+1);

        return dp[idx] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1, sizeof(dp));
        n = nums.size();
        int i = 0;

        int ans = solve(nums, i);
        return ans;   
    }
};