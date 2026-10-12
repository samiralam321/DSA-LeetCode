class Solution {
public:
    int n;
    int t[2001];
    
    int solve(vector<int>& nums, int target){
        if(target == 0) return 1;
        
        if(target < 0) return 0;
        
        int result = 0;
        
        if(t[target] != -1){
            return t[target];
        }
        
        for(int i = 0; i<n; i++){
            int take_i  = solve(nums, target-nums[i]);
            result += take_i;
        }
        
        return t[target] = result;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, target);
    }
};