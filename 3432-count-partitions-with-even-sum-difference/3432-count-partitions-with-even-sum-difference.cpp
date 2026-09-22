class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(int x : nums) {
            totalSum += x;
        }
        if(totalSum % 2 == 0) return n - 1;
        return 0;
    }
};