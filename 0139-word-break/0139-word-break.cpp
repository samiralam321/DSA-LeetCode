class Solution {
public:
    int n;
    int dp[301];

    bool solve(int idx, string &s, vector<string>& wordDict){
        if(idx == n) return true;

        if(dp[idx] != -1){
            return dp[idx];
        }

        for(int l=1; l <= n; l++){
            string temp = s.substr(idx, l);

            if(find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()){
                if(solve(idx+l, s, wordDict)){
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, s, wordDict);
    }
};