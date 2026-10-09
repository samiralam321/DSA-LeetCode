class Solution {
public:
    int n;
    int t[501][501];
    int MOD = 1e9+7;

    int solve(int idx, int steps) {
        if(idx < 0 || idx >= n) return 0;
        if(steps == 0) return idx == 0;

        if(t[idx][steps] != -1) {
            return t[idx][steps];
        }

        int right = solve(idx+1, steps-1) % MOD;
        int left = solve(idx-1, steps-1) % MOD;
        int stay = solve(idx, steps-1) % MOD;

        return t[idx][steps] = ((right + left) % MOD + stay) % MOD;
    }

    int numWays(int steps, int arrLen) {
        n = min(arrLen, steps/2 + 1);
        memset(t, -1, sizeof(t));

        return solve(0, steps);
    }
};