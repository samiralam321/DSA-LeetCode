class Solution {
public:
    int dp[23][23];

    int solve(vector<int>& nums, int i, int j){
        if(i > j) return 0;
        if(i == j) return nums[i];

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int takeLeft = nums[i] + min(
            solve(nums, i+2, j),
            solve(nums, i+1, j-1)
        );

        int takeRight = nums[j] + min(
            solve(nums, i+1, j-1),
            solve(nums, i, j-2)
        );
        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int total = accumulate(nums.begin(), nums.end(), 0);

        int player1 = solve(nums, 0, nums.size()-1);
        int player2 = total - player1;

        return player1 >= player2;
    }
};