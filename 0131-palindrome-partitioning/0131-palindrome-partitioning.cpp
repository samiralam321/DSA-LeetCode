class Solution {
public:
    int n;
    int dp[17][17];

    bool isPalindrome(string&s, int i, int j){
        if(i>=j) return true;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] != s[j]){
            return dp[i][j] = false;
        }
        return dp[i][j] = isPalindrome(s,i+1,j-1);
    }

    void solve(string&s, int i, vector<string>&temp, vector<vector<string>>&ans){
        if(i == n){
            ans.push_back(temp);
        }

        for(int j=i; j<n; j++){
            if(isPalindrome(s,i,j)){
                temp.push_back(s.substr(i, j-i+1));
                solve(s, j+1, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length();
        memset(dp,-1,sizeof(dp));
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s,0, temp, ans);
        return ans;
    }
};