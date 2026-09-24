class Solution {
public:
    int t[50001];
    int n;

    int getNextIndex(vector<vector<int>>& jobs, int l, int currentJobEnd){
        int r = n - 1;
        int result = n+1;

        while(l <= r){
            int mid = l +(r - l)/2;
            if(jobs[mid][0] >= currentJobEnd) {
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>>& jobs, int i){
        if(i >= n) return 0;
        if(t[i] != -1) return t[i];

        int next = getNextIndex(jobs, i + 1, jobs[i][1]);
        int taken = jobs[i][2] + solve(jobs, next);
        int notTaken = solve(jobs, i + 1);

        return t[i] = max(taken, notTaken);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memset(t, -1, sizeof(t));

        vector<vector<int>> jobs;
        for(int i=0; i<n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        auto comp = [&](auto& vec1, auto& vec2) {
            return vec1[0] < vec2[0];
        };

        sort(jobs.begin(), jobs.end(), comp);
        return solve(jobs, 0);
    }
};