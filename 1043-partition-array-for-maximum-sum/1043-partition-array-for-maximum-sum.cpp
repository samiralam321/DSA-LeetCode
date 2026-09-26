class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int i, vector<int>& arr, int k){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int maxEl = 0;
        int ans = 0;

        for(int j=i; j<n && j < i + k; j++) {
            maxEl = max(maxEl, arr[j]);
            int len = j-i+1;

            int current = maxEl * len + solve(j+1, arr, k);
            ans = max(ans, current);
        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        dp.assign(n, -1);
        return solve(0, arr, k);
    }
};