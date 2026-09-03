class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = *min_element(nums1.begin(), nums1.end());

        if(mini & 1) return true;

        for(int x : nums1){
            if(x & 1){
                return false;
            }
        }
        return true;
        
    }
};