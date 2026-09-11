class Solution {
public:
    int n;
    int t[2501][2501];

    int lis(vector<int>& nums, int prevIdx, int currIdx){
        if(currIdx == n) return 0;

        if(prevIdx != -1 && t[prevIdx][currIdx] != -1){
            return t[prevIdx][currIdx];
        }

        int taken = 0;
        if(prevIdx == -1 || nums[currIdx] > nums[prevIdx]){
            taken = 1 + lis(nums, currIdx, currIdx+1);
        }

        int not_taken = lis(nums, prevIdx, currIdx+1);

        if(prevIdx != -1){
            t[prevIdx][currIdx] = max(taken, not_taken);
        }

        return max(taken, not_taken);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        n = nums.size();
        return lis(nums, -1, 0);
        
    }
};