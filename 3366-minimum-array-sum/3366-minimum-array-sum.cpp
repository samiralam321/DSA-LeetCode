class Solution {
public:
    int n;
    int dp[101][101][101];

    int solve(vector<int>& nums, int k, int i, int op1, int op2){
        if(i == n) return 0;

        if(dp[i][op1][op2] != -1){
            return dp[i][op1][op2];
        }

        int result = INT_MAX;

        // case 1 : apply op1
        if(op1 > 0){
            int newVal = (nums[i]+1)/2;
            int applyop1 = newVal + solve(nums, k, i+1, op1-1, op2);
            result = min(result, applyop1);
        }

        //case 2 : apply op2
        if(op2 > 0 && nums[i] >= k){
            int newVal = (nums[i] - k);
            int applyop2 = newVal + solve(nums, k, i+1, op1, op2-1);
            result = min(result, applyop2);
        }

        //case 3 : first op1 ----> op2
        if(op1 > 0 && op2 > 0){
            int newVal = (nums[i]+1)/2;

            if(newVal >= k){
                newVal = newVal - k;
                int applyop1op2 = newVal + solve(nums,k,i+1, op1-1, op2-1);
                result = min(result, applyop1op2);
            }

            // apply op2 ---> op1
            if(nums[i] >= k){
                newVal = nums[i] - k;
                newVal = (newVal+1)/2;
                int applyop2op1 = newVal + solve(nums,k, i+1, op1-1, op2-1);
                result = min(result, applyop2op1);
            }
        }
        // apply now op
        result = min(result, nums[i] + solve(nums, k, i+1, op1, op2));
        return dp[i][op1][op2] = result;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        n = nums.size();
        memset(dp,-1, sizeof(dp));
        return solve(nums,k,0,op1,op2); 
    }
};