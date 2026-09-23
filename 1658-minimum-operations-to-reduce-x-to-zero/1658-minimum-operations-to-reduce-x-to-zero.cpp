class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;

        for(int i=0; i<n; i++){
            totalSum += nums[i];
        }

        int target = totalSum - x;
        if(target < 0) return -1;
        
        int left = 0;
        int right = 0;

        int sum = 0;
        int maxLen = -1;

        while(right < n){
            sum += nums[right];
            while(left <= right && sum > target){
                sum -= nums[left];
                left++;
            }
            if(sum == target){
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        if(maxLen == -1) return -1;
        return n - maxLen;
    }
};