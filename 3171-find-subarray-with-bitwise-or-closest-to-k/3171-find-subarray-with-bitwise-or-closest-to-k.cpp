class Solution {
public:
    int calc(vector<int> &temp){
        int ans = 0;

        for(int i = 0; i < 31; i++){
            if(temp[i] > 0) {
                ans |= (1 << i);
            }
        }
        return ans;
    }

    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        vector<int> temp(31, 0);
        int l = 0;

        for(int r = 0; r < n; r++){
            for(int i = 0; i < 31; i++){
                if((1 << i) & nums[r]){
                    temp[i]++;
                }
            }

            while(l <= r && calc(temp) >= k){
                int val = calc(temp);
                ans = min(ans, abs(val - k));

                for(int i = 0; i < 31; i++){
                    if((1 << i) & nums[l]){
                        temp[i]--;
                    }
                }
                l++;
            }

            if(l <= r){
                int val = calc(temp);
                ans = min(ans, abs(val - k));
            }
        }
        return ans;
    }
};