class Solution {
public:
    int n;
    unordered_map<vector<bool>, int> mp;

    int solve(vector<int>& nums, vector<bool>& visited, int operations){
        if(operations > n / 2){
            return 0;
        }
        if(mp.find(visited) != mp.end()){
            return mp[visited];
        }

        int maxScore = 0;
        for(int i = 0; i < n - 1; i++){
            if(visited[i]){
                continue;
            }
            for(int j = i + 1; j < n; j++){
                if(visited[j]){
                    continue;
                }

                visited[i] = true;
                visited[j] = true;

                int currScore = operations * __gcd(nums[i], nums[j]);
                int remainingScore = solve(nums, visited, operations + 1);
                maxScore = max(maxScore, currScore + remainingScore);

                visited[i] = false;
                visited[j] = false;
            }
        }
        return mp[visited] = maxScore;
    }

    int maxScore(vector<int>& nums) {
        n = nums.size();
        vector<bool> visited(n, false);
        mp.clear();
        return solve(nums, visited, 1);
    }
};