class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int i = 0;
        int j = 0;

        set<int> st;

        while(j < n){
            sum += nums[j];
            if(j-i+1 == 2){
                if(st.count(sum)) return true;
                st.insert(sum);

                sum -= nums[i];
                i++;
            }
            j++;
        }
        return false;
    }
};