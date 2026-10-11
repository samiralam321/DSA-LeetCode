class Solution {
public:
    int n;
    int dp[101];
    int solve(int i, string &s){
        if(i == n) return 1;
        if(s[i] == '0') return 0;

        if(dp[i] != -1){
            return dp[i];
        }

        int oneChar = solve(i+1, s);
        int twoChar = 0;
        
        if(i+1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))){
            twoChar = solve(i+2, s);
        }
        return dp[i] = oneChar + twoChar;
    }

    int numDecodings(string s) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(0,s);  
    }
};