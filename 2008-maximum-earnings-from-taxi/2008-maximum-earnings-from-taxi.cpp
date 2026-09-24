class Solution {
public:
    long long dp[100001];
    int n;

    long long solve(vector<vector<int>>& rides, int i, int n) {
        if(i >= rides.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int start = rides[i][0];
        int end = rides[i][1];
        int tip = rides[i][2];

        int lo = i+1;
        int hi = n-1;
        int next = n;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(rides[mid][0] >= end){
                next = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        long long skip = solve(rides, i + 1, n);
        long long take = (end - start + tip) + solve(rides, next, n);
        
        return dp[i] = max(take, skip);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        n = rides.size();
        sort(rides.begin(), rides.end());

        memset(dp, -1, sizeof(dp));
        return solve(rides, 0, n);
    }
};