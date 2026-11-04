class Solution {
public:
    using ll = long long;

    multiset<int> left, right;
    ll sumLeft = 0, sumRight = 0;

    void balance(){
        int need = (left.size() + right.size() + 1) / 2;

        while(left.size() > need){
            int val = *left.rbegin();

            left.erase(left.find(val));
            sumLeft -= val;

            right.insert(val);
            sumRight += val;
        }

        while(left.size() < need){
            int val = *right.begin();

            right.erase(right.find(val));
            sumRight -= val;

            left.insert(val);
            sumLeft += val;
        }
    }

    void add(int val){
        if(left.empty() || val <= *left.rbegin()){
            left.insert(val);
            sumLeft += val;
        }
        else{
            right.insert(val);
            sumRight += val;
        }
        balance();
    }

    void remove(int val){
        auto it = left.find(val);

        if(it != left.end()){
            left.erase(it);
            sumLeft -= val;
        }
        else{
            right.erase(right.find(val));
            sumRight -= val;
        }
        balance();
    }

    ll getCost(){
        ll median = *left.rbegin();
        return median * left.size() - sumLeft + sumRight - median * right.size();
    }

    vector<ll> cost;
    vector<vector<ll>> dp;

    ll solve(int i, int cnt, int n, int x){
        if(cnt == 0)return 0;
        if(n - i < cnt * x){
            return 1e18;
        }

        if(dp[i][cnt] != -1){
            return dp[i][cnt];
        }

        ll skip = solve(i+1, cnt, n, x);
        ll take = cost[i] + solve(i+x, cnt - 1, n, x);

        return dp[i][cnt] = min(skip, take);
    }

    ll minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        left.clear();
        right.clear();

        sumLeft = 0;
        sumRight = 0;
        cost.clear();

        for(int i=0; i<x; i++){
            add(nums[i]);
        }
        cost.push_back(getCost());

        for(int i=x; i<n; i++){
            remove(nums[i - x]);
            add(nums[i]);
            cost.push_back(getCost());
        }

        dp.assign(n + 1, vector<ll>(k + 1, -1));
        return solve(0, k, n, x);
    }
};