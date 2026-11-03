class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxEl = *max_element(nums.begin(), nums.end());

        int ans = 0;
        for(int &num : nums){
            ans += abs(num-maxEl);
        }
        return ans; 
    }
};