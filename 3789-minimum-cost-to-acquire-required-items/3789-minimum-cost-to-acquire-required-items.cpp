class Solution {
public:
    using ll = long long;

    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll a = 1LL * need1 * cost1 + 1LL * need2 * cost2;
        ll b = 1LL * max(need1, need2) * costBoth;
        ll mn = min(need1, need2);

        ll c = mn * costBoth + 1LL * (need1 - mn) * cost1 + 1LL * (need2 - mn) * cost2;
        return min({a, b, c});
    }
};
