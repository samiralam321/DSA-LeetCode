class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];

        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        int totalSum = prefixSum[n - 1];
        int ans = 0;

        for(int i=0; i<n - 1; i++){
            int leftSum = prefixSum[i];
            int rightSum = totalSum - prefixSum[i];

            if((leftSum - rightSum) % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};