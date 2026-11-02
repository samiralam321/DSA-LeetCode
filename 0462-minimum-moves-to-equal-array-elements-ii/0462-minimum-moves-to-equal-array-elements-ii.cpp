class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        int target = nums[n/2];
        int ans = 0;
        for(int i=0; i<=n-1; i++){
            ans += abs(nums[i] - target);
        }
        return ans; 
    }
};