class Solution {
public:
    int n;
    int t[201][201];

    int solve(int i, int j, vector<vector<int>>& a) {
        if(i == n-1) return a[i][j];

        if(t[i][j] != 0x3f3f3f3f) return t[i][j];

        int down = a[i][j] + solve(i+1, j, a);
        int right = a[i][j] + solve(i+1, j+1, a);

        return t[i][j] = min(down, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        memset(t, 0x3f, sizeof(t));
        return solve(0, 0, triangle);
    }
};