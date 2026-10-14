class Solution {
public:
    int n;
    int dp[101][101];

    int solve(int l, int r, string &s){
        if(l == r) return 1;
        if(l > r) return 0;

        if(dp[l][r] != -1){
            return dp[l][r];
        }

        int i = l+1;
        while(s[l] == s[i] && i <= r){
            i++;
        }
        if(i == r+1) return 1;

        int normal = 1 + solve(i,r,s);
        int aage_ka = INT_MAX;

        for(int j=i; j <= r; j++){
            if(s[l] == s[j]){
                int x = solve(i,j-1,s) + solve(j,r,s);
                aage_ka = min(aage_ka, x);
            }
        }
        return dp[l][r] = min(aage_ka, normal);
    }
    int strangePrinter(string s) {
        n = s.length();
        memset(dp,-1, sizeof(dp));
        return solve(0,n-1,s); 
    }
};