class Solution {
public:
    const int MOD=1e9+7;
    long long t[2005][2005];

    long long solve(int n,int k){
        if(k == 0 || k == n) return 1;
        if(k<0 || k>n) return 0;
        if(t[n][k] != -1) return t[n][k];

        return t[n][k]=(solve(n-1,k-1) + solve(n-1,k))%MOD;
    }

    int numberOfSets(int n,int k){
        memset(t,-1, sizeof(t));
        return solve(n+k-1,2*k);
    }
};