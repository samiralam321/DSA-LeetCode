class Solution {
public:
    int n;
    long long dp[100001];
    long long mod = 1e9 + 7;

    long long solve(int i, string &s) {
        if(i == n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        long long oneChar = (s[i] == '*') ? 9 : 1;
        oneChar = oneChar * solve(i + 1, s) % mod;

        long long twoChar = 0;

        if(i + 1 < n) {
            if(s[i] == '*' && s[i + 1] == '*')
                twoChar = 15 * solve(i + 2, s) % mod;
            else if(s[i] == '*' && s[i + 1] <= '6')
                twoChar = 2 * solve(i + 2, s) % mod;
            else if(s[i] == '*')
                twoChar = solve(i + 2, s);
            else if(s[i] == '1' && s[i + 1] == '*')
                twoChar = 9 * solve(i + 2, s) % mod;
            else if(s[i] == '1')
                twoChar = solve(i + 2, s);
            else if(s[i] == '2' && s[i + 1] == '*')
                twoChar = 6 * solve(i + 2, s) % mod;
            else if(s[i] == '2' && s[i + 1] <= '6')
                twoChar = solve(i + 2, s);
        }

        return dp[i] = (oneChar + twoChar) % mod;
    }

    int numDecodings(string s) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, s);
    }
};