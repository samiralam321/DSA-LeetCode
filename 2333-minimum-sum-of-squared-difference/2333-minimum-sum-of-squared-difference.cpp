class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int k = k1 + k2;

        vector<int> diff(n);
        int mx = 0;

        for(int i=0; i<n; i++){
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        vector<int> cnt(mx + 1, 0);

        for(int d : diff){
            cnt[d]++;
        }

        for(int i=mx; i>0 && k>0; i--){
            int take = min(cnt[i], k);

            cnt[i] -= take;
            cnt[i - 1] += take;
            k -= take;
        }

        long long ans = 0;
        for(int i=1; i<= mx; i++){
            ans += 1LL * cnt[i]*i*i;
        }
        return ans;
    }
};