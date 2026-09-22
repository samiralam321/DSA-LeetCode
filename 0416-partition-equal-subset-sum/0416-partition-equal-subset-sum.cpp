class Solution {
    public:
    int t[201][10001];

    bool isSubset(int n, int target, vector<int>& arr){
        if(target == 0) return true;
        if(n == 0) return false;

        if(t[n][target] != -1){
            return t[n][target];
        }

        bool skip = isSubset(n-1, target, arr);

        bool take = false;
        if(arr[n-1] <= target){
            take = isSubset(n-1, target-arr[n-1], arr);
        }
        return t[n][target] = take || skip;
    }

    bool canPartition(vector<int>& nums){
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int target = sum/2;

        if(sum % 2 != 0) return false;
        memset(t,-1,sizeof(t));
        return isSubset(n,target,nums);
    }
};