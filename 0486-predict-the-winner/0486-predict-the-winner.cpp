class Solution {
public:
    int n;
    int t[21][21];
    int solve(vector<int>& nums , int i, int j){
        if(i > j) return 0;

        if(i == j) return nums[i];

        if(t[i][j] != -1){
            return t[i][j];
        }

        int take_i = nums[i] + min(solve(nums, i+2, j), solve(nums, i+1, j-1));
        int take_j = nums[j] + min(solve(nums, i+1, j-1), solve(nums, i, j-2));

        return t[i][j] = max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();

        memset(t,-1,sizeof(t));

        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int player1 = solve(nums, 0, n-1);

        int player2 = total_sum - player1;

        return player1 >= player2;
        
    }
};