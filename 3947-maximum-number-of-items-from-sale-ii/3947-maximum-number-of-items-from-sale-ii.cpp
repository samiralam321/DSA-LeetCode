class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);
        vector<int> copies(n + 1, 0);

        int minPrice = INT_MAX;

        for(int i = 0; i < n; i++){
            int factor = items[i][0];
            int price = items[i][1];

            freq[factor]++;
            minPrice = min(minPrice, price);
        }

        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j += i){
                copies[i] += freq[j];
            }
            copies[i]--;
        }

        vector<pair<int, int>> candidates;

        for(int i = 0; i < n; i++){
            int factor = items[i][0];
            int price = items[i][1];

            if(copies[factor] > 0 && price <= 2LL * minPrice){
                candidates.push_back({price, copies[factor]});
            }
        }

        sort(candidates.begin(), candidates.end());
        long long ans = 0;
        for(auto& item : candidates){
            int price = item.first;
            int count = min(item.second, budget / price);

            ans += 2LL * count;
            budget -= count * price;
        }
        ans += budget / minPrice;
        return ans;
    }
};