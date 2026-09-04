class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> preMax(n);
        vector<int> preMin(n);

        // find the preMax

        preMax[0] = nums[0];

        for(int i=1; i<n; i++){
            preMax[i] = max(preMax[i-1], nums[i]);
        }
        
        //find preMin

        preMin[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            preMin[i] = min(preMin[i+1], nums[i]);
        }

        for(int i=0; i<n; i++){
            int ans = preMax[i] - preMin[i];

            if(ans <= k){
                return i;
            }
        }
        return -1;
    }
};