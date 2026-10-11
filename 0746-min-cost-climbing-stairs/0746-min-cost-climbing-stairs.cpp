class Solution {
public:
    int n;
    int t[1001];

    int solve(int i, vector<int>& cost){
        if(i >= n) return 0;

        if(t[i] != -1){
            return t[i];
        }

        int take_one = solve(i+1, cost);
        int take_two = solve(i+2, cost);

        return t[i] = cost[i] + min(take_one, take_two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();

        memset(t,-1,sizeof(t));
        return min(solve(0,cost), solve(1,cost));
        
    }
};