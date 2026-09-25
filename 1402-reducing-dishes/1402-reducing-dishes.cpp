class Solution {
public:
    int n;
    int t[501][501];
    int solve(vector<int>& satisfaction, int idx, int time){
        if(idx >= n) return 0;

        if(t[idx][time] != -1){
            return t[idx][time];
        }

        int skip = solve(satisfaction, idx+1, time);
        int take = satisfaction[idx] * time + solve(satisfaction, idx+1, time+1);

        return t[idx][time] = max(skip, take);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        memset(t,-1, sizeof(t));

        return solve(satisfaction, 0, 1);   
    }
};