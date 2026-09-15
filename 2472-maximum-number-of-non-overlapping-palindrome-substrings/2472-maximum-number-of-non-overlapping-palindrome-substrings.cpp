class Solution {
public:
    int n;
    vector<int> dp;

    bool isPalindrome(string &s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    int solve(string &s,int i,int k){
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];

        int ans=solve(s,i+1,k);

        for(int j = i+k-1; j < min(n, i+k+1); j++){
            if(isPalindrome(s,i,j)){
                ans=max(ans,1+solve(s, j+1, k));
            }
        }
        return dp[i]=ans;
    }

    int maxPalindromes(string s,int k) {
        n=s.size();
        dp.assign(n,-1);
        return solve(s,0,k);
    }
};