class Solution {
public:
    unordered_map<int,int> mp;
    int dp[2001][2001];

    bool solve(vector<int>& stones, int pos, int jump) {
        if(pos == stones.size() - 1)
            return true;

        if(dp[pos][jump] != -1)
            return dp[pos][jump];

        for(int nextJump = jump - 1; nextJump <= jump + 1; nextJump++) {
            if(nextJump <= 0)
                continue;

            int nextPos = stones[pos] + nextJump;

            if(mp.find(nextPos) != mp.end()) {
                int nextIndex = mp[nextPos];

                if(solve(stones, nextIndex, nextJump))
                    return dp[pos][jump] = 1;
            }
        }
        return dp[pos][jump] = 0;
    }

    bool canCross(vector<int>& stones) {
        for(int i = 0; i < stones.size(); i++)
            mp[stones[i]] = i;

        memset(dp, -1, sizeof(dp));
        return solve(stones, 0, 0);
    }
};